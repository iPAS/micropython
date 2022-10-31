# Dev by Sonthaya Nongnuch

from machine import Pin, I2C
import math
import utime
import _thread

MPU6050_ADDR = const(0x69)

acc = [0, 0, 0, 0]
gyro = [0, 0, 0, 0]
mag = [0, 0, 0, 0]
temp = 0.0

EVENT_SHAKE = const(0)
EVENT_BOARD_UP = const(1)
EVENT_BOARD_DOWN = const(2)
EVENT_SCREEN_UP = const(3)
EVENT_SCREEN_DOWN = const(4)
EVENT_TILT_LEFT = const(5)
EVENT_TILT_RIGHT = const(6)
EVENT_FREE_FALL = const(7)
EVENT_3G = const(8)
EVENT_6G = const(9)
EVENT_8G = const(10)

__event_callback = [ None ] * 10

__startCalcLowStrengthContinue = False
__xStartCalc = 0

# Check sensor on board
i2c0 = I2C(0, scl=Pin(21), sda=Pin(22), freq=100000)

i2c0.writeto_mem(MPU6050_ADDR, 0x6B, b'\x00')
i2c0.writeto_mem(MPU6050_ADDR, 0x1C, b'\x10')  # 8g
i2c0.writeto_mem(MPU6050_ADDR, 0x1B, b'\x00')  # 250 */sec

def b2i(x, y):
    return (x << 8 | y) if not x & 0x80 else (-(((x ^ 255) << 8) | (y ^ 255) + 1))

def i2b(n):
    if n < 0:
        n = (-n ^ 0xFFFF) + 1
    return bytes([ (n >> 8) & 0xFF, n & 0xFF ])

def update():
    global acc, gyro, mag, temp
    try:
        buff = i2c0.readfrom_mem(MPU6050_ADDR, 0x3B, 14)
    except:
        print("Read IMU fail")
        return
    for i in range(3):
        acc[i] = b2i(buff[(i * 2)], buff[(i * 2) + 1])
        acc[i] = round(acc[i] / 4096.0 * 1000.0, 2)
    x = acc[1]
    y = acc[0]
    z = acc[2]
    acc[0] = x
    acc[1] = y
    acc[2] = -z
    acc[3] = math.sqrt(math.pow(acc[0], 2) + math.pow(acc[1], 2) + math.pow(acc[2], 2))
    del x, y, z
    temp = round(b2i(buff[6], buff[7]) / 340.00 + 36.53, 2)
    for i in range(3):
        gyro[i] = b2i(buff[(i * 2) + 8], buff[(i * 2) + 9])
        gyro[i] = round(gyro[i] / 131.0, 2)
    gyro[3] = math.sqrt(math.pow(gyro[0], 2) + math.pow(gyro[1], 2) + math.pow(gyro[2], 2))

def rotation():
    x_g_value = acc[0] / 1000.0 # Acceleration in x-direction in g units
    y_g_value = acc[1] / 1000.0 # Acceleration in y-direction in g units
    z_g_value = acc[2] / 1000.0 # Acceleration in z-direction in g units

    roll = (((math.atan2(z_g_value, x_g_value) * 180) / 3.14) + 180)
    if roll >= 270:
        roll = 270 - roll
    elif roll >= 90:
        roll = math.fmod(90 - roll, -180) + 180
    else:
        roll = -90 - roll
    roll = round(roll, 2)

    pitch = (((math.atan2(y_g_value, z_g_value) * 180) / 3.14) + 180)
    pitch = 180 - pitch
    pitch = round(pitch, 2)

    return (roll, pitch)

calibrateMagFlag = False
mag_min = [ 99999, 99999, 99999 ]
mag_max = [ -99999, -99999, -99999 ]
def heading():
    global calibrateMagFlag
    if not calibrateMagFlag:
        if not loadCalibrateFromSRAM():
            calibrate_compass()
        calibrateMagFlag = True

    try:
        # use calibration values to shift and scale magnetometer measurements
        x_mag = (0.0 + mag[0] - mag_min[0]) / (mag_max[0] - mag_min[0]) * 2 - 1
        y_mag = (0.0 + mag[1] - mag_min[1]) / (mag_max[1] - mag_min[1]) * 2 - 1
        z_mag = (0.0 + mag[2] - mag_min[2]) / (mag_max[2] - mag_min[2]) * 2 - 1

        # Normalize acceleration measurements so they range from 0 to 1
        s = math.sqrt(math.pow(acc[0], 2) + math.pow(acc[1], 2) + math.pow(acc[2], 2))
        xAccelNorm = acc[0] / s
        yAccelNorm = acc[1] / s
        # DF("Acc norm (x, y): (%f, %f)\n", xAccelNorm, yAccelNorm)

        pitch = math.asin(-xAccelNorm)
        roll = math.asin(yAccelNorm / math.cos(pitch))

        # tilt compensated magnetic sensor measurements
        x_mag_comp = x_mag * math.cos(pitch) + z_mag * math.sin(pitch)
        y_mag_comp = x_mag * math.sin(roll) * math.sin(pitch) + y_mag * math.cos(roll) - z_mag * math.sin(roll) * math.cos(pitch)

        # arctangent of y/x converted to degrees
        heading = 180 * math.atan2(x_mag_comp, y_mag_comp) / math.pi

        heading = (-heading) if heading <= 0 else (360 - heading)
        return int(heading)
    except:
        return 0

def is_gesture(event, blocking=True):
    global __xStartCalc, __startCalcLowStrengthContinue
    if event == EVENT_SHAKE:
        return acc[3] > 4000
    elif event == EVENT_BOARD_UP:
        return acc[1] < -600
    elif event == EVENT_BOARD_DOWN:
        return acc[1] > 600
    elif event == EVENT_SCREEN_UP:
        pitch = rotation()[1]
        return pitch >= -30 and pitch <= 30
    elif event == EVENT_SCREEN_DOWN:
        pitch = rotation()[1]
        return pitch >= 150 or pitch <= -150
    elif event == EVENT_TILT_LEFT:
        roll = rotation()[0]
        return roll <= -30
    elif event == EVENT_TILT_RIGHT:
        roll = rotation()[0]
        return roll >= 30
    elif event == EVENT_FREE_FALL:
        if blocking:
            lowStrengthContinue = False
            for i in range(0, 100, 20):
                if acc[3] < 700:
                    lowStrengthContinue = True
                    utime.sleep_ms(20)
                else:
                    lowStrengthContinue = False
                    break
            return lowStrengthContinue
        else:
            if acc[3] < 700:
                if not __startCalcLowStrengthContinue:
                    __xStartCalc = utime.ticks_ms()
                    __startCalcLowStrengthContinue = True
                else:
                    if (utime.ticks_ms() - __xStartCalc) >= 100E3:
                        __startCalcLowStrengthContinue = False
                        return True
            else:
                __xStartCalc = 0
                __startCalcLowStrengthContinue = False
                return False
    elif event ==  EVENT_3G:
        return acc[3] > 3000

    elif event == EVENT_6G:
        return acc[3] > 6000

    elif event == EVENT_8G:
        return acc[3] > 8000
    else:
        return False

eventCallback = []
callbackDoingFlag = [ False ] * 11
for i in range(11):
    eventCallback += [ [] ]

def on(type, callback):
    global eventCallback
    eventCallback[type] += [ callback ]

def IMULoopTask():
    global callbackDoingFlag
    while True:
        update()
        for inx in range(11):
            if is_gesture(inx, False): # non-blocking
                if callbackDoingFlag[inx] == False:
                    for i in range(len(eventCallback[inx])):
                        _thread.start_new_thread(eventCallback[inx][i], ())
                    callbackDoingFlag[inx] = True
            else:
                callbackDoingFlag[inx] = False

        utime.sleep_ms(20)

_thread.start_new_thread(IMULoopTask, ())

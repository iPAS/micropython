from machine import Pin, PWM, I2C, ADC, time_pulse_us
from time import sleep, sleep_ms, sleep_us
import _thread
import machine
import st7789
from neopixel import NeoPixel

# Board Pin define
I2C_SDA_PIN = const(21)
I2C_SCL_PIN = const(22)

i2c0 = I2C(0, scl=Pin(I2C_SCL_PIN), sda=Pin(I2C_SDA_PIN), freq=400000)

class Ultrasonic_t:
    def __init__(self):
        self.trigger = Pin(17, mode=Pin.OUT)
        self.echo = Pin(5, mode=Pin.IN)
        self.trigger.value(0)

    def distance(self):
        self.trigger.value(0)
        sleep_us(5)
        self.trigger.value(1)
        sleep_us(10)
        self.trigger.value(0)

        try:
            pulse_time = time_pulse_us(self.echo, 1, 1000000)
            d = (pulse_time / 2) / 29.1
            return int(d) if d < 400 else -1
        except OSError as ex:
            return -1


ultrasonic = Ultrasonic_t()


class Buzzer_t:
    note_map = {
        "C4": 261,
        "C#4": 277,
        "D4": 293,
        "Eb4": 311,
        "E4": 329,
        "F4": 349,
        "F#4": 369,
        "G4": 391,
        "G#4": 415,
        "A4": 440,
        "Bb4": 466,
        "B4": 493,
        "C5": 523,
        "C#5": 554,
        "D5": 587,
        "Eb5": 622,
        "E5": 659,
        "F5": 698,
        "F#5": 740,
        "G5": 784,
        "G#5": 831,
        "A5": 880,
        "Bb5": 932,
        "B5": 988,
        "C6": 1046,
        "C#6": 1109,
        "D6": 1175,
        "Eb6": 1244,
        "E6": 1318, 
        "F6": 1396,
        "F#6": 1480,
        "G6": 1568,
        "G#6": 1661,
        "A6": 1760,
        "Bb6": 1865,
        "B6": 1976,
        "C7": 2093,
        "SIL": 0
    }

    def __init__(self):
        self.buzzer = PWM(Pin(16), freq=2000, duty=0)
        self.buzzer.duty(0)
        self.volume = 50
        self.bpm = 120

    def tone(self, freq=2093, duration=0.5):
        self.buzzer.freq(int(freq))
        self.buzzer.duty(int(self.volume / 100 * 512))
        sleep(duration)
        self.buzzer.duty(0)

    def on(self, freq=2000):
        self.buzzer.freq(int(freq))
        self.buzzer.duty(int(self.volume / 100 * 512))

    def off(self):
        self.buzzer.duty(0)

    def note(self, notes, duration=4):
        quarter_delay = (60 * 1000) / self.bpm
        delay = quarter_delay * duration
        delay = delay / 1000 # mS -> S
        for note in notes.split(" "):
            if note in self.note_map:
                self.tone(self.note_map[note], delay)

buzzer = Buzzer_t()

class PCA9685_t:
    def __init__(self):
        self.i2c = i2c0
        self.addr = 0x40
        self.i2c.writeto_mem(self.addr, 0x00, b"\x80") # Soft Reset
        sleep_ms(5) # wait work again

        # Set frequency
        self.i2c.writeto_mem(self.addr, 0x00, b"\x10") # Sleep mode
        self.i2c.writeto_mem(self.addr, 0xFE, b"\x3C") # Prescaler : 100 Hz => (25 MHz / (4096 * 100 Hz)) - 1 = 60 = 0x3C
        self.i2c.writeto_mem(self.addr, 0x00, b"\x80") # Restart
        self.i2c.writeto_mem(self.addr, 0x00, b"\x20") # Auto-Increment enabled
        self.i2c.writeto_mem(self.addr, 0x01, b"\x04") # OUTDRV -> 1
    
    def duty(self, ch, on_value, off_value):
        on_value = int(min(max(0, on_value), 4095))
        off_value = int(min(max(0, off_value), 4095))
        self.i2c.writeto_mem(self.addr, 0x06 + (ch * 4), bytes([
            on_value & 0xFF,
            (on_value >> 8) & 0x0F,
            off_value & 0xFF,
            (off_value >> 8) & 0x0F,
        ]))

pca9685 = PCA9685_t()


class Motor_t:
    M1A = const(0)
    M1B = const(1)
    M2A = const(2)
    M2B = const(3)
    M3A = const(4)
    M3B = const(5)
    M4A = const(6)
    M4B = const(7)

    FORWARD = const(0)
    BACKWARD = const(1)
    TURN_LEFT = const(2)
    TURN_RIGHT = const(3)
    SPIN_LEFT = const(4)
    SPIN_RIGHT = const(5)
    SLIDE_LEFT = const(6)
    SLIDE_RIGHT = const(7)

    def __init__(self):
        pca9685.duty(self.M1A, 0, 4095)
        pca9685.duty(self.M1B, 0, 4095)
        pca9685.duty(self.M2A, 0, 4095)
        pca9685.duty(self.M2B, 0, 4095)
        pca9685.duty(self.M3A, 0, 4095)
        pca9685.duty(self.M3B, 0, 4095)
        pca9685.duty(self.M4A, 0, 4095)
        pca9685.duty(self.M4B, 0, 4095)

    def wheel(self, speed_m1, speed_m2, speed_m3, speed_m4):
        dir1 = 1 if speed_m1 >= 0 else 0
        if speed_m1 < 0:
            speed_m1 = speed_m1 * -1
        speed_m1 = 4095 - min(max(int(speed_m1 / 100 * 4095), 0), 4095)

        dir2 = 1 if speed_m2 >= 0 else 0
        if speed_m2 < 0:
            speed_m2 = speed_m2 * -1
        speed_m2 = 4095 - min(max(int(speed_m2 / 100 * 4095), 0), 4095)
        
        dir3 = 1 if speed_m3 >= 0 else 0
        if speed_m3 < 0:
            speed_m3 = speed_m3 * -1
        speed_m3 = 4095 - min(max(int(speed_m3 / 100 * 4095), 0), 4095)
        
        dir4 = 1 if speed_m4 >= 0 else 0
        if speed_m4 < 0:
            speed_m4 = speed_m4 * -1
        speed_m4 = 4095 - min(max(int(speed_m4 / 100 * 4095), 0), 4095)

        pca9685.duty(self.M1A, 0, speed_m1 if dir1 == 1 else 4095)
        pca9685.duty(self.M1B, 0, 4095 if dir1 == 1 else speed_m1)

        pca9685.duty(self.M2A, 0, speed_m2 if dir2 == 1 else 4095)
        pca9685.duty(self.M2B, 0, 4095 if dir2 == 1 else speed_m2)

        pca9685.duty(self.M3A, 0, speed_m3 if dir3 == 1 else 4095)
        pca9685.duty(self.M3B, 0, 4095 if dir3 == 1 else speed_m3)
        
        pca9685.duty(self.M4A, 0, speed_m4 if dir4 == 1 else 4095)
        pca9685.duty(self.M4B, 0, 4095 if dir4 == 1 else speed_m4)

    def forward(self, speed=50, time=1):
        self.wheel(speed, speed, speed, speed)
        sleep(time)
        self.wheel(0, 0, 0, 0)

    def backward(self, speed=50, time=1):
        self.wheel(speed * -1, speed * -1, speed * -1, speed * -1)
        sleep(time)
        self.wheel(0, 0, 0, 0)

    def turn_left(self, speed=50, time=1):
        self.wheel(0, 0, speed, speed)
        sleep(time)
        self.wheel(0, 0, 0, 0)

    def turn_right(self, speed=50, time=1):
        self.wheel(speed, speed, 0, 0)
        sleep(time)
        self.wheel(0, 0, 0, 0)

    def spin_left(self, speed=50, time=1):
        self.wheel(speed * -1, speed * -1, speed, speed)
        sleep(time)
        self.wheel(0, 0, 0, 0)

    def spin_right(self, speed=50, time=1):
        self.wheel(speed, speed, speed * -1, speed * -1)
        sleep(time)
        self.wheel(0, 0, 0, 0)
    
    def slide_left(self, speed=50, time=1):
        self.wheel(speed * -1, speed, speed, speed * -1)
        sleep(time)
        self.wheel(0, 0, 0, 0)

    def slide_right(self, speed=50, time=1):
        self.wheel(speed, speed * -1, speed * -1, speed)
        sleep(time)
        self.wheel(0, 0, 0, 0)

    def move(self, dir, speed):
        if dir == self.FORWARD:
            self.wheel(speed, speed, speed, speed)
        elif dir == self.BACKWARD:
            self.wheel(speed * -1, speed * -1, speed * -1, speed * -1)
        elif dir == self.TURN_LEFT:
            self.wheel(0, 0, speed, speed)
        elif dir == self.TURN_RIGHT:
            self.wheel(speed, speed, 0, 0)
        elif dir == self.SPIN_LEFT:
            self.wheel(speed * -1, speed * -1, speed, speed)
        elif dir == self.SPIN_RIGHT:
            self.wheel(speed, speed, speed * -1, speed * -1)
        elif dir == self.SLIDE_LEFT:
            self.wheel(speed * -1, speed, speed, speed * -1)
        elif dir == self.SLIDE_RIGHT:
            self.wheel(speed, speed * -1, speed * -1, speed)


    def stop(self):
        self.wheel(0, 0, 0, 0)

motor = Motor_t()


class Servo_t:
    SV1 = const(8)
    SV2 = const(9)
    SV3 = const(10)
    SV4 = const(11)
    SV5 = const(12)
    SV6 = const(13)

    def __init__(self):
        for i in range(6):
            pca9685.duty(8 + i, 0, 0)
        
    def angle(self, pin, angle):
        pca9685.duty(pin, 0, int(((angle / 180) * 858) + 215))

servo = Servo_t()

class VR_t:
    def __init__(self):
        self.adc = ADC(Pin(34))
        self.adc.atten(ADC.ATTN_11DB)
        self.adc.width(ADC.WIDTH_12BIT)
        
    def raw(self):
        return self.adc.read()

    def volt(self):
        return round(self.raw() / 4095 * 3.3, 2)

vr = VR_t()

def color_hex(c):
        if type(c) is str:
            c = int(c[1:], 16)
        r = (c >> 16) & 0xFF
        g = (c >> 8) & 0xFF
        b = c & 0xFF
        return st7789.color565(r, g, b)

spi = machine.SPI(2, baudrate=40000000, polarity=1, phase=1, sck=machine.Pin(18), mosi=machine.Pin(23))
display = st7789.ST7789(spi, 240, 240, reset=machine.Pin(4, machine.Pin.OUT), dc=machine.Pin(2, machine.Pin.OUT))
display.init()

class RGBLED_t:
    def __init__(self, pin, n):
        self.np = NeoPixel(Pin(pin, Pin.OUT), n)
        self.np.bright = 50

    def color_converter(self, c):
        if type(c) is str:
            return (
                int(int(c[1:3], 16) * (self.np.bright / 100)), 
                int(int(c[3:5], 16) * (self.np.bright / 100)), 
                int(int(c[5:7], 16) * (self.np.bright / 100))
            )
        else:
            return c

    def set_color(self, n, c):
        self.np[n] = self.color_converter(c)
    
    def fill(self, c):
        c = self.color_converter(c)
        for i in range(self.np.n):
            self.np[i] = c

    def clear(self):
        self.fill(( 0, 0, 0 ))
    
    def show(self):
        self.np.write()

    def rainbow(self, wait):
        for j in range(256):
            for i in range(self.np.n):
                WheelPos = (i * 1 + j) & 255
                if WheelPos < 85:
                    self.np[i] = (int((WheelPos * 3) * self.np.bright / 100), int((255 - WheelPos * 3) * self.np.bright / 100), 0)
                elif WheelPos < 170:
                    WheelPos -= 85
                    self.np[i] = (int((255 - WheelPos * 3) * self.np.bright / 100), 0, int((WheelPos * 3) * self.np.bright / 100))
                else:
                    WheelPos -= 170
                    self.np[i] = (0, int((WheelPos * 3) * self.np.bright / 100), int((255 - WheelPos * 3) * self.np.bright / 100))
            self.np.write()
            sleep_ms(wait)

    def set_brightness(self, value):
        self.np.bright = value

rgbled = {
    "board": RGBLED_t(25, 6),
    "car": RGBLED_t(19, 12)
}

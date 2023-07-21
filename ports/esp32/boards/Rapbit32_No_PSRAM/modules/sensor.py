# Dev by Sonthaya Nongnuch

from machine import Pin, ADC, time_pulse_us
from time import sleep_us

def light1_raw():
    return analogRead(39)

def light2_raw():
    return analogRead(35)

def light3_raw():
    return analogRead(33)

__white_threshold = 3000
__black_threshold = 2000
def white_threshold(threshold=None):
    if threshold != None:
        __white_threshold = threshold
    return __white_threshold

def black_threshold(threshold=None):
    global __white_threshold
    if threshold != None:
        __black_threshold = threshold
    return __black_threshold

def light1_is_black():
    return True if light1_raw() <= __black_threshold else False

def light2_is_black():
    return True if light2_raw() <= __black_threshold else False

def light3_is_black():
    return True if light3_raw() <= __black_threshold else False

def light1_is_white():
    return True if light1_raw() >= __white_threshold else False

def light2_is_white():
    return True if light2_raw() >= __white_threshold else False

def light3_is_white():
    return True if light3_raw() >= __white_threshold else False

def ldr1_raw():
    return analogRead(34)

def ldr2_raw():
    return analogRead(32)

def ldr1():
    return min(max(int(((ldr1_raw() - 300) / (3000 - 300)) * 100), 0), 100)

def ldr2():
    return min(max(int(((ldr2_raw() - 300) / (3000 - 300)) * 100), 0), 100)

def knob_raw():
    return analogRead(36)

def knob():
    return int(knob_raw() / 4095 * 100)

def knob_volt():
    return round(knob_raw() / 4095 * 3.3, 2)

def analogRead(pin_n):
    adc = ADC(Pin(pin_n))
    adc.atten(ADC.ATTN_11DB)
    adc.width(ADC.WIDTH_12BIT)
    return adc.read()


trigger = Pin(26, mode=Pin.OUT)
echo = Pin(27, mode=Pin.IN)

def distance():
    trigger.value(0)
    sleep_us(5)
    trigger.value(1)
    sleep_us(10)
    trigger.value(0)

    try:
        pulse_time = time_pulse_us(echo, 1, 1000000)
        d = (pulse_time / 2) / 29.1
        return int(d) if d < 400 else -1
    except OSError as ex:
        return -1


"""
# Test only
from time import sleep

while True:
    # print("{}\t{}\t{}".format(light1(), light2(), light3()))
    # print("{}\t{}".format(ldr1(), ldr2()))
    # print("{}".format(knob()))
    # print("{}".format(sw1()))
    # print("{}\t{}".format(ldr1(), ldr2()))
    print("{}\t{}".format(knob_volt(), knob_raw()))
    sleep(0.1)
"""
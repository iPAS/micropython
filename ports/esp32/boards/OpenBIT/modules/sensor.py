# Dev by Sonthaya Nongnuch

from machine import Pin, I2C, ADC
from time import sleep

TMP75_ADDR = const(0x4C)
BH1750_ADDR = const(0x23)

i2c0 = I2C(0, scl=Pin(21), sda=Pin(22), freq=100000)
i2c0.writeto_mem(TMP75_ADDR, 0x01, '\x00')

def temperature():
    try:
        h, l = i2c0.readfrom_mem(TMP75_ADDR, 0x00, 2)
        temp = ((h << 8) | l) >> 4
        temp = temp * 0.0625
        temp = temp * (-1 if (h & 0x80) != 0 else 1)
        return temp
    except:
        return -99
    return -98

def microphone():
    adc = ADC(Pin(39))
    adc.atten(ADC.ATTN_11DB)
    adc.width(ADC.WIDTH_12BIT)
    return adc.read()

i2c0.writeto(BH1750_ADDR, b'\x10')

def light():
    try:
        h, l = i2c0.readfrom(BH1750_ADDR, 2)
        return int(((h << 8) | l) / 1.2)
    except:
        return -99
    return -98

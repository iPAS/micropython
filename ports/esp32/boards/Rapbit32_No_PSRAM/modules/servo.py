# Dev by Sonthaya Nongnuch

from machine import Pin, PWM

SV1 = Pin(2)
SV2 = Pin(15)

SV1_obj = PWM(SV1, freq=50)
SV1_obj.duty(0)

SV2_obj = PWM(SV2, freq=50)
SV2_obj.duty(0)

def angle(pin, angle):
    if pin == SV1:
        SV1_obj.duty(int(25.57 + ((angle / 180.0) * 102.3)))
    elif pin == SV2:
        SV2_obj.duty(int(25.57 + ((angle / 180.0) * 102.3)))
    else:
        PWM(pin, freq=50).duty(int(25.57 + ((angle / 180.0) * 102.3)))


# Dev by Sonthaya Nongnuch

from machine import Pin
import _thread
import utime

S1 = Pin(5, Pin.IN, Pin.PULL_UP)
S2 = Pin(12, Pin.IN, Pin.PULL_UP)

__s1_press = None
__s1_release = None
__s2_press = None
__s2_release = None

def __onSwitchChangesValue(pin):
    if pin.value():
        callback = None
        if pin == S1:
            callback = __s1_release
        elif pin == S2:
            callback = __s2_release
        if callback:
            _thread.start_new_thread(callback, ())
    else:
        callback = None
        if pin == S1:
            callback = __s1_press
        elif pin == S2:
            callback = __s2_press
        if callback:
            _thread.start_new_thread(callback, ())


S1.irq(handler=__onSwitchChangesValue, trigger=Pin.IRQ_FALLING | Pin.IRQ_RISING)
S2.irq(handler=__onSwitchChangesValue, trigger=Pin.IRQ_FALLING | Pin.IRQ_RISING)

def value(pin):
    return 0 if pin.value() else 1

def press(pin, callback):
    global __s1_press, __s2_press
    if pin == S1:
        __s1_press = callback
    elif pin == S2:
        __s2_press = callback

def release(pin, callback):
    global __s1_release, __s2_release
    if pin == S1:
        __s1_release = callback
    elif pin == S2:
        __s2_release = callback

__s1_pressed = None
__s2_pressed = None
__s12_pressed = None

S12 = 99

def SwitchLoopTask():
    sw1_press_start = None
    sw1_press_flag = False
    sw2_press_start = None
    sw2_press_flag = False
    while True:
        sw1 = S1.value()
        sw2 = S2.value()

        # S1
        if sw1 == 0: # S1 is press
            if sw1_press_start == None:
                sw1_press_start = utime.ticks_ms()
        else:
            if sw1_press_start != None:
                diff = utime.ticks_ms() - sw1_press_start
                sw1_press_flag = diff >= 40 and diff < 1000
                sw1_press_start = None
        
        # S2
        if sw2 == 0: # S2 is press
            if sw2_press_start == None:
                sw2_press_start = utime.ticks_ms()
        else:
            if sw2_press_start != None:
                diff = utime.ticks_ms() - sw2_press_start
                sw2_press_flag = diff >= 40 and diff < 1000
                sw2_press_start = None
        
        if sw1 == sw2 == 1:
            if sw1_press_flag and sw2_press_flag:
                if __s12_pressed:
                    _thread.start_new_thread(__s12_pressed, ())
                sw1_press_flag = False
                sw2_press_flag = False
            elif sw1_press_flag:
                if __s1_pressed:
                    _thread.start_new_thread(__s1_pressed, ())
                sw1_press_flag = False
            elif sw2_press_flag:
                if __s2_pressed:
                    _thread.start_new_thread(__s2_pressed, ())
                sw2_press_flag = False

        utime.sleep_ms(20)
    

_thread.start_new_thread(SwitchLoopTask, ())

def pressed(pin, callback):
    global __s1_pressed, __s2_pressed, __s12_pressed
    if pin == S12:
        __s12_pressed = callback
    elif pin == S1:
        __s1_pressed = callback
    elif pin == S2:
        __s2_pressed = callback

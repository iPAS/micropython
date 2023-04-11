from machine import Pin
import _thread
import utime

SW1 = Pin(0, Pin.IN, Pin.PULL_UP)

__s1_press = None
__s1_release = None
def __onSwitchChangesValue(pin):
    if pin.value():
        callback = None
        if pin == SW1:
            callback = __s1_release
        if callback:
            _thread.start_new_thread(callback, ())
    else:
        callback = None
        if pin == SW1:
            callback = __s1_press
        if callback:
            _thread.start_new_thread(callback, ())


SW1.irq(handler=__onSwitchChangesValue, trigger=Pin.IRQ_FALLING | Pin.IRQ_RISING)

def value(pin):
    return 0 if pin.value() else 1

def press(pin, callback):
    global __s1_press
    if pin == SW1:
        __s1_press = callback

def release(pin, callback):
    global __s1_release, __s2_release
    if pin == SW1:
        __s1_release = callback

__s1_pressed = None

def SwitchLoopTask():
    sw1_press_start = None
    sw1_press_flag = False
    while True:
        sw1 = SW1.value()

        # SW1
        if sw1 == 0: # SW1 is press
            if sw1_press_start == None:
                sw1_press_start = utime.ticks_ms()
        else:
            if sw1_press_start != None:
                diff = utime.ticks_ms() - sw1_press_start
                sw1_press_flag = diff >= 40 and diff < 1000
                sw1_press_start = None
        
        if sw1_press_flag:
            if __s1_pressed:
                _thread.start_new_thread(__s1_pressed, ())
            sw1_press_flag = False

        utime.sleep_ms(20)
    

_thread.start_new_thread(SwitchLoopTask, ())

def pressed(pin, callback):
    global __s1_pressed
    if pin == SW1:
        __s1_pressed = callback
    

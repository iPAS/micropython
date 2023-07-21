# Dev by Sonthaya Nongnuch

from machine import Pin

SW1 = Pin(23, Pin.IN, Pin.PULL_UP)

__press = None
__release = None

def __onSwitchChangesValue(pin):
    if pin.value():
        if __release:
            __release()
    else:
        if __press:
            __press()


SW1.irq(handler=__onSwitchChangesValue, trigger=Pin.IRQ_FALLING | Pin.IRQ_RISING)

def value():
    return 0 if SW1.value() else 1

def press(callback):
    global __press
    __press = callback

def release(callback):
    global __release
    __release = callback

from machine import Pin
from time import ticks_us
from time import ticks_diff

IR_PIN = 14

timeStart = -1
data = 0
dataBitIndex = 0
irQueue = [ ]
pin = None
pinIR = None
lastData = 0

def onIRPinChange(p):
    global timeStart, data, dataBitIndex, irQueue, lastData
    if p.value() == 1: # 1
        timeStart = ticks_us()
    else: # 0
        t = ticks_diff(ticks_us(), timeStart)
        # print(t)
        if t > 4000: # start signal
            data = 0
            dataBitIndex = 0
        elif t > 2000 and t < 4000 and dataBitIndex == 0:
            # print("RE")
            irQueue.append(lastData)
        else:
            if dataBitIndex < 32:
                data |= (1 if t > 1000 else 0) << (dataBitIndex)
                dataBitIndex = dataBitIndex + 1
                if dataBitIndex == 32:
                    addr = data & 0xFF
                    iaddr = (data >> 8) & 0xFF
                    cmd = (data >> 16) & 0xFF
                    icmd = (data >> 24) & 0xFF
                    # print(hex(data))
                    if addr == (iaddr ^ 0xFF) and cmd == (icmd ^ 0xFF):
                        # print("OK")
                        irQueue.append(cmd)
                        lastData = cmd
                    else:
                        print("ERROR")
                        lastData = 0
                    dataBitIndex = -1

pinIR = Pin(IR_PIN, Pin.IN, Pin.PULL_UP)
pinIR.irq(onIRPinChange, Pin.IRQ_FALLING|Pin.IRQ_RISING)

def read():
    global irQueue
    if len(irQueue):
        data = irQueue[0]
        irQueue = irQueue[1:]
        return data
    else:
        return 0

from machine import Pin
import display
import buzzer
import motor

motor.init()
Pin(25, Pin.OUT).value(0) # LED2
Pin(23, Pin.OUT).value(0) # LDE1
buzzer.off()
display.fill(0)
display.show()

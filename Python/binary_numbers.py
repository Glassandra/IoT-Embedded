from machine import Pin
import time

def decimalToBinary(number):
    return "{0:010b}".format(int(number))

pins = [16, 17, 18, 19, 20, 21, 22, 26, 27, 28]
def showLed():
    for index in range(0,256):
        binary_number = decimalToBinary(index)
        for pin_index in range(len(pins)):
            if binary_number[pin_index] == "1":
                led = Pin(pins[pin_index], Pin.OUT) 
                led.value(1)
            else:
                led = Pin(pins[pin_index],Pin.OUT)
                led.value(0)
        time.sleep(0.4)
        
          
while True:
    showLed()


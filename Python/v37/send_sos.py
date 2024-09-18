from machine import Pin
import time

# constants
short_duration = 0.2
long_duration = 0.5
pause_duration = 0.2
between_letters_duration = 0.5

# define pins
led = Pin(15, Pin.OUT)
button = Pin(13, Pin.IN, Pin.PULL_UP)

# made 3 functions for easier overseeing
# 2 for the two different lengths and one for the task
def short():
    led.value(1)
    time.sleep(short_duration)
    led.value(0)
    time.sleep(pause_duration)

def long():
    led.value(1)
    time.sleep(long_duration)
    led.value(0)
    time.sleep(pause_duration)

def send_sos(num_of_sos):
    for _ in range(num_of_sos):
        for _ in range(3):
            short()
        time.sleep(between_letters_duration)
        
        for _ in range(3):
            long()
        time.sleep(between_letters_duration)
        
        for _ in range(3):
            short()
        time.sleep(between_letters_duration)

try:
    while True:
        if not button.value():
            send_sos(1)
        else:
            led.value(0)
except KeyboardInterrupt:
    pass


byte ledPins[] = {16, 17, 18, 19, 20, 21, 22, 26, 27, 28};
int ledCounts;

void setup() {
    ledCounts = sizeof(ledPins) / sizeof(ledPins[0]); // Correct calculation of ledCounts
    for (byte pin : ledPins) {
        pinMode(pin, OUTPUT);
    }
}

void setLEDs(int number) {
    for (int i = 0; i < ledCounts; i++) {
        // Use bitwise AND and shift to determine the state of each bit
        digitalWrite(ledPins[i], (number & (1 << i)) ? HIGH : LOW);
    }
}

void loop() {
    for (int j = 0; j < 512; j++) {
        setLEDs(j);
        delay(300);
    }
}
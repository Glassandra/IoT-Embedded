#include <string>

byte ledPins[] = {16, 17, 18, 19, 20, 21, 22, 26, 27, 28};
int ledCounts;

std::string decimalToBinary(int n, int length)
{
    if (n == 0)
        return std::string(length, '0');

    std::string binary = "";
    while (n > 0)
    {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n = n / 2;
    }


    if (binary.length() < length)
    {
        binary = std::string(length - binary.length(), '0') + binary;
    }

    return binary;
}

void setup()
{
    ledCounts = sizeof(ledPins);
    for (int i = 0; i < ledCounts; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop()
{
    for (int j = 0; j < 512; j++)
    {        
        std::string temp = decimalToBinary(j,ledCounts);
        for (int i = 0; i < ledCounts; i++)
        {
            if (temp[i] == '1') {
                digitalWrite(ledPins[i], HIGH);
            }
            else {           
                digitalWrite(ledPins[i], LOW);
            }
        }
        delay(300);
    }
}
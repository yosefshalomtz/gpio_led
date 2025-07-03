// Simple LED blink for Raspberry Pi Zero W using WiringPi
#include <wiringPi.h>
#include <iostream>
#include <unistd.h> // for sleep
#include <stdlib.h>

#define LED_PIN 0 // WiringPi pin 0 = BCM_GPIO 17 (Physical pin 11)

int main(int argc, char** argv) {
    // Initialize WiringPi using BCM_GPIO numbering
    if (wiringPiSetup() == -1) {
        std::cerr << "WiringPi setup failed!\n";
        return 1;
    }

    pinMode(LED_PIN, OUTPUT);

    std::cout << "Blinking LED on GPIO 17 (WiringPi pin 0)... Press Ctrl+C to stop.\n";
    while (true) {
        digitalWrite(LED_PIN, HIGH); // LED on
        delay(std::atoi(argv[1]));                 // 500 ms
        digitalWrite(LED_PIN, LOW);  // LED off
        delay(std::atoi(argv[1]));                 // 500 ms
    }
    return 0;
}

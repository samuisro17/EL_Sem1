#include <Arduino.h>

// Note: No setup() or loop() here! Just specific functions.
void initTempSensor() {
    Serial.println("Temp Sensor Initialized...");
}

void runTempTask() {
    Serial.println("Checking Temperature: 24.5 C");
    // Sensor reading logic here
}
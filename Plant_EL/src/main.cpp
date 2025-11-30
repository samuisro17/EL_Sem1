#include <Arduino.h>
#include "my_tasks.h" // Import your "Menu"

void setup() {
    Serial.begin(115200);
    
    // Initialize both "files" once
    initTempSensor();
    initSoilMoisture();
}

void loop() {
    // 1. Execute Temperature File's logic
    runTempTask();
    delay(1000); 

    // 2. Execute Smoke File's logic
    runSoilMoistureTask();
    delay(1000);
}
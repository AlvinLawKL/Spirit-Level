//Created by Alvin Law 05/11/2013
//This is a spirit level using accelerometer.

//User Guide
//When the engduino is flat, there will be three LEDs on.
//GREEN in the middle, RED on the left and BLUE on the right.
//If the engduino is not flat, either RED or BLUE light will on.
//Each LED's position away from original GREEN LED's position 
//means (to the nearest)0.1 g/s difference.
//RED LED counting from the left of original GREEN LED's position.
//BLUE LED counts from the right.
//When the engduino is vertically upright, all LEDs will on first
//then the LED's position is shown
//Actual values of X, Y and Z can be read in serial monitor.

#include <EngduinoAccelerometer.h>
#include <EngduinoLEDs.h>
#include <Wire.h>

void setup() {
  EngduinoAccelerometer.begin();
  EngduinoLEDs.begin();
}

void loop() {
  float xyz[3];
  float flatxyz[3];
  float diffxyz[3];
  
  EngduinoAccelerometer.xyz(xyz);//Read xyz values in g/s
  
  for(int i = 0; i < 3; i++) {
    diffxyz[i]= xyz[i] - flatxyz[i];
  }
  
  //Difference of acceleration is used to determine is the Engduine flat or not.
  //Only the difference of y value, diffxyz[1], is used.
  //Since the LED(s) has(have) to be specify in each case, loop can not be used.
  if(diffxyz[1] < -0.9) {
    EngduinoLEDs.setAll(RED);
    delay(500);
    EngduinoLEDs.setAll(OFF);
    EngduinoLEDs.setLED(10, RED);
  }
  else if(diffxyz[1] < -0.8) {
    EngduinoLEDs.setLED(11, RED);
  }
  else if(diffxyz[1] < -0.7) {
    EngduinoLEDs.setLED(12, RED);
  }
  else if(diffxyz[1] < -0.6) {
    EngduinoLEDs.setLED(13, RED);
  }
  else if(diffxyz[1] < -0.5) {
    EngduinoLEDs.setLED(14, RED);
  }
  else if(diffxyz[1] < -0.4) {
    EngduinoLEDs.setLED(15, RED);
  }
  else if(diffxyz[1] < -0.3) {
    EngduinoLEDs.setLED(0, RED);
  }
  else if(diffxyz[1] < -0.2) {
    EngduinoLEDs.setLED(1, RED);
  }
  else if(diffxyz[1] < -0.1) {
    EngduinoLEDs.setLED(2, RED);
  }
  else if(diffxyz[1] > 0.9) {
    EngduinoLEDs.setAll(BLUE);
    delay(500);
    EngduinoLEDs.setAll(OFF);
    EngduinoLEDs.setLED(12, BLUE);
  }
  else if(diffxyz[1] > 0.8) {
    EngduinoLEDs.setLED(11, BLUE);
  }
  else if(diffxyz[1] > 0.7) {
    EngduinoLEDs.setLED(10, BLUE);
  }
  else if(diffxyz[1] > 0.6) {
    EngduinoLEDs.setLED(9, BLUE);
  }
  else if(diffxyz[1] > 0.5) {
    EngduinoLEDs.setLED(8, BLUE);
  }
  else if(diffxyz[1] > 0.4) {
    EngduinoLEDs.setLED(7, BLUE);
  }
  else if(diffxyz[1] > 0.3) {
    EngduinoLEDs.setLED(6, BLUE);
  }
  else if(diffxyz[1] > 0.2) {
    EngduinoLEDs.setLED(5, BLUE);
  }
  else if(diffxyz[1] > 0.1) {
    EngduinoLEDs.setLED(4, BLUE);
  }
  else {
    EngduinoLEDs.setLED(2, RED);
    EngduinoLEDs.setLED(3, GREEN);
    EngduinoLEDs.setLED(4, BLUE);
  }
  
  //Below is to observe the difference of XYZ in serial monitor
  Serial.print("Difference in XYZ: [ ");
  for(int i = 0; i < 3; i++){
    Serial.print(diffxyz[i]);
    Serial.print(" ");
  }
  Serial.print("]\n");
  
  delay(500);
  EngduinoLEDs.setAll(OFF);
}

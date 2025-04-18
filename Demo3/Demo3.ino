/*********************************************
Test & debug code
Written by: 
Date: 

*********************************************/

#include "AIDriver.h"
#include "HCSR04.h"
#include "LiquidCrystal_I2C.h"
#include <Wire.h>
#include "Adafruit_TCS34725.h"

byte gammatable[256];

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// Instantiate two ultrasonic sensors
HCSR04 Front_HCSR04(4, 5);
HCSR04 Right_HCSR04(6, 7);

// Instantiate Car
AIDriver *mrJonesDriving;  //3,8,9,11,12,13 Pins are reserved

// Instantiate LCD Display
LiquidCrystal_I2C lcd(39, 16, 2);

// Variables for PID Controller
double sensed_output, control_signal;
double setpoint;
double Kp; //proportional gain
double Ki; //integral gain
double Kd; //derivative gain
int T; //sample time in milliseconds (ms)
unsigned long last_time;
double total_error, last_error;
int max_control;
int min_control; 

const char* software_version = "00.00.01";

void setup() {
  mrJonesDriving = new AIDriver();
  Serial.begin(9600);
  lcd_setup(software_version);
  rgb_sen_setup ();
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BEGIN");
}

void loop() { 
  int f = Front_HCSR04.getDistance();
  int r = Right_HCSR04.getDistance();
  
  PID_Control(); //calls the PID function every T interval and outputs a control signal  


  //Make mrJonesDriving drive forward left wheel speed 200 and right wheel speeed 200
  lcd.setCursor(0,0);
  lcd.print("Drive Backward");
  mrJonesDriving->driveBackward(255,255);
  delay(2000);
  lcd.print("Drive Forward");
    mrJonesDriving->driveForward(255,255);
  delay(2000);
  lcd.print("Rotate Right");
    mrJonesDriving->rotateRight(255);
  delay(2000);
  lcd.print("Rotate Left");
    mrJonesDriving->rotateLeft(255);
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("BRAKING");
  mrJonesDriving->brake();


}


void PID_Control(){

  unsigned long current_time = millis(); //returns the number of milliseconds passed since the Arduino started running the program
 
  int delta_time = current_time - last_time; //delta time interval 
  
  if (delta_time >= T){

    double error = setpoint - sensed_output;
    
    total_error += error; //accumalates the error - integral term
    if (total_error >= max_control) total_error = max_control;
    else if (total_error <= min_control) total_error = min_control;
    
    double delta_error = error - last_error; //difference of error for derivative term

    control_signal = Kp*error + (Ki*T)*total_error + (Kd/T)*delta_error; //PID control compute
    if (control_signal >= max_control) control_signal = max_control;
    else if (control_signal <= min_control) control_signal = min_control;
    
    last_error = error;
    last_time = current_time;
    }  
}





/*
#include <DFRobot_TCS34725.h>


DFRobot_TCS34725 tcs = DFRobot_TCS34725(&Wire, TCS34725_ADDRESS,TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X);

  while(tcs.begin() != 0)
  {
    Serial.println("No TCS34725 found ... check your connections");
    delay(1000);
  }


uint16_t clear, red, green, blue;
tcs.getRGBC(&red, &green, &blue, &clear);
tcs.lock();  
Serial.print("C:\t"); Serial.print(clear);
Serial.print("\tR:\t"); Serial.print(red);
Serial.print("\tG:\t"); Serial.print(green);
Serial.print("\tB:\t"); Serial.print(blue);
Serial.println("\t");

// Figure out some basic hex code for visualization
uint32_t sum = clear;
float r, g, b;
r = red; r /= sum;
g = green; g /= sum;
b = blue; b /= sum;
r *= 256; g *= 256; b *= 256;
Serial.print("\t");
Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
Serial.println();  
*/
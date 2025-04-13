/*  <- Do not delete

AIDRIVER METHODS:
 - mrJonesDriving->rotateRight(200); // speed can be between 0-255
 - mrJonesDriving->rotateLeft(200); 
 - mrJonesDriving->driveForward(200,200); //Make mrJonesDriving drive forward left wheel speed 200 and right wheel speeed 200
 - mrJonesDriving->driveBackward(200,200);
 - mrJonesDriving->brake(); // Make mrJonesDriving stop instantly 

LCD METHODS:
- lcd.clear();  // Clear the screen
- lcd.setCursor(0,0); //Set cursor (0,0) or (0,1)
- lcd.print(""); //Print something

ULTRASONIC METHODS:
- int f = Front_HCSR04.getDistance(); // read distance in CM and save to a variable
- int r = Right_HCSR04.getDistance(); // read distance in CM and save to a variable

RGB COLOUR SENSOR METHODS:
- float red, green, blue; // Create 3x Floats to store RGB Values
- delay(60);  // takes 50ms to read, can be in a statemachine
- tcs.getRGB(&red, &green, &blue); //Read sensor
- Serial.print(int(red)); // example serial print

LINE SENSORS:
- Serial.read(A1) // Read serial value


ARDUINO METHODS:
 - delay(1000);  // Ardunio stops processing and continues in set state for duration in milliseconds 1000 = 1 second
 - Serial.println(mrJonesDriving->read()); // Prints ranger state to the serial monitor
 - Serial.println("Hello World"); //Prints something to the serial monitor

CONTROL STRUCTURES
if (true){
  Serial.println("This is true")
}

if (true){
  Serial.println("This is true")
} else {
  Serial.println("This is false")
}

While (true) {
  mrJonesDriving->driveForward(200,200);
}

Testing code:
#include "AIDriver.h"

// Declare a pointer to a AIDriver object
  AIDriver *mrJonesDriving;
 	
	void setup(){   // sets up once as the program starts
    //Instantiate a two wheeled to the pointer 'mrJonesDriving'
    mrJonesDriving = new AIDriver();
	}

	void loop(){ // loops continuously 50 times a second
      // Read the distanceRanger ulstrasonic sensor and return the object distance in mm
      Serial.println(mrJonesDriving->read());
			
      //obj->doSomething(); in this case make the object mrJonesDriving rotate to the right at a speed of 200
      mrJonesDriving->rotateRight(125); // speed can be between 0-255
			// wait 2000 milliseconds or 2 seconds
      delay(2000);
      mrJonesDriving->rotateLeft(125);
			delay(2000);
      //Make mrJonesDriving drive forward left wheel speed 200 and right wheel speeed 200
      mrJonesDriving->driveForward(125,125);
      delay(2000);
      mrJonesDriving->driveBackward(125,125);
      delay(2000);
	}
















































































*/// <- Do not delete
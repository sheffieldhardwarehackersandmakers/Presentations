#include <Servo.h> //This is the library we're using; 
                   //a pre-written chunk of code to make 
                   //a complex task much easier

Servo myservo;     // create servo "object" to control a servo

int sensorPin = 0; // analog pin used to connect the light dependant resistor
int sensorValue;   // variable to read the value from the analog pin
int servoValue;    // variable to hold the value that we'll send to the Servo

void setup() {
  myservo.attach(9);  // Tells the library that we're going to attach the servo to Pin 9
  Serial.begin(9600); // Get ready to send data over the Serial connection to the computer
}

void loop() {
  sensorValue = analogRead(sensorPin);   // reads the value of the LDR (value between 0 and 1023)
  
  servoValue = map(sensorValue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(servoValue);                  // sets the servo position according to the scaled value
  
  Serial.print(sensorValue);             // Print the sensor value
  Serial.print(" -> ");                // ...and a little arrow
  Serial.println(servoValue);            // ...and the value we've just sent to the servo
  
  delay(15);                           // waits for the servo to get there
}


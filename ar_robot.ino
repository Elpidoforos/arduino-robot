/* The examples which have been used for this project can be found below
Sweep
* by BARRAGAN <http://barraganstudio.com>
* This example code is in the public domain.

RADAR SYSTEM USING ARDUINO PROGRAMING CODE
* https://technicalscientistrm.blogspot.com/2019/03/radar-system-using-arduino-programing.html

* modified 8 Nov 2013
* by Scott Fitzgerald
* http://www.arduino.cc/en/Tutorial/Sweep

Adafruit Motor shield library
* copyright Adafruit Industries LLC, 2009
* this code is public domain, enjoy!

Ultrasonic Sensor HC-SR04 and Arduino Tutorial
* by Dejan Nedelkovski,
* www.HowToMechatronics.com

*/

#include <AFMotor.h>
#include <Servo.h>

// DC motor on M2, M4
AF_DCMotor rightMotor(2);
AF_DCMotor leftMotor(4);

// Create a servo object
Servo myServo; 

// Servo initial position
int servoPos = 0;    

// Defines pins for Ultrasound sensor
const int trigPin = A5;
const int echoPin = A0;

// Ultrasonic related variables
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  Serial.println("Robot start moving");
 
  // turn on motor #2 and #4
  rightMotor.setSpeed(200);
  leftMotor.setSpeed(245); // Left motor it is slower (hardware issue)

  // Servo pin = 10
  myServo.attach(10); 

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}


void loop() {
   
  // Servo from 15 - 165 degrees and backwards
  for(servoPos=15 ; servoPos<=165 ; servoPos++){
      myServo.write(servoPos);
      delay(30);
      distance = scanUltrasoundDistance();
  }
  for(servoPos=165 ; servoPos>15 ; servoPos--){
      myServo.write(servoPos);
      delay(30);
      distance = scanUltrasoundDistance();
  }

/*
  rightMotor.run(FORWARD);
  leftMotor.run(FORWARD);
  delay(5000);
  
  rightMotor.run(RELEASE);
  leftMotor.run(RELEASE);

  delay(100);

  rightMotor.run(BACKWARD);
  leftMotor.run(BACKWARD);
  delay(5000);

  rightMotor.run(RELEASE);
  leftMotor.run(RELEASE);

  delay(100);

  */
}

int scanUltrasoundDistance() {
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculating the distance
    distance= duration*0.034/2;

    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    return distance;
}

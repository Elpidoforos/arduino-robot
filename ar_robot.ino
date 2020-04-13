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
AF_DCMotor right_motor2(2);
AF_DCMotor left_motor4(4);

// Create a servo object
Servo myservo; 

// Stepper motor on M2+M4 48 steps per revolution
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Robot start moving");
 
  // turn on motor #2 and #4
  right_motor2.setSpeed(200);
  left_motor4.setSpeed(245);
  // attach the servo in pin 10
  myservo.attach(10); 
}

// variable to store the servo position
int servo_pos = 0;    

// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {

  // Servo from 15 - 165 degrees and backwards
  for(servo_pos=15 ; servo_pos<=165 ; servo_pos++){
      myservo.write(servo_pos);
      delay(30);
  }
  for(servo_pos=165 ; servo_pos>15 ; servo_pos--){
      myservo.write(servo_pos);
      delay(30);
  }

/*
  right_motor2.run(FORWARD);
  left_motor4.run(FORWARD);
  delay(5000);
  
  right_motor2.run(RELEASE);
  left_motor4.run(RELEASE);

  delay(100);

  right_motor2.run(BACKWARD);
  left_motor4.run(BACKWARD);
  delay(5000);

  right_motor2.run(RELEASE);
  left_motor4.run(RELEASE);

  delay(100);

  */
}
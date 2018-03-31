#include <MyoController.h>
#include "Ultrasonic.h"

// Ultrasonic sensor
Ultrasonic ultrasonic(12,13); // (Trig PIN,Echo orange PIN)

// Motor controller 
int speedPin_M1 = 5;     //M1 Speed Control E1
int speedPin_M2 = 6;     //M2 Speed Control E2
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;     //M1 Direction Control
#define SPEED 100

#define LED_PIN 11

MyoController myo = MyoController();

void setup() {

  // Ultrasonic sensor
  Serial.begin(9600);
  pinMode(12, OUTPUT); // trig pin
  pinMode(13, INPUT); // echo ping
  digitalWrite(12, HIGH); 
  digitalWrite(13, LOW);  

  // Motor controller
  pinMode(speedPin_M1, OUTPUT);
  pinMode(speedPin_M2, OUTPUT);
  pinMode(directionPin_M1, OUTPUT);
  pinMode(directionPin_M2, OUTPUT);
  
  myo.initMyo();
}

void loop()
{

  long distance = ultrasonic.Ranging(CM);
  Serial.print(distance);

   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      break; // continue current motion
    case fist:
      carBack(SPEED, SPEED);
      break;
    case waveIn:
      carTurnLeft(SPEED , SPEED );
      break;
    case waveOut:
      carTurnRight(SPEED, SPEED);
      break;
    case fingersSpread:
      if (distance > 10) {
        carAdvance(SPEED, SPEED); // move only if nothing's in front of us
      }      
      break;
    case doubleTap:
      carStop();
      break;
   } 

   if (distance < 15) {
      digitalWrite(LED_PIN, HIGH);
      carStop();
   }
   else {
    digitalWrite(LED_PIN, LOW);
   }
   delay(100);
}


void carStop(){                 //  Motor Stop
  digitalWrite(speedPin_M2,0); 
  digitalWrite(directionPin_M1,LOW);    
  digitalWrite(speedPin_M1,0);   
  digitalWrite(directionPin_M2,LOW);    
}   

void carTurnLeft(int leftSpeed,int rightSpeed){         //Turn Left
  analogWrite (speedPin_M2,leftSpeed);              //PWM Speed Control
  digitalWrite(directionPin_M1,LOW);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,HIGH);
} 

void carTurnRight(int leftSpeed,int rightSpeed){        //Turn Right
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,HIGH);   
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,LOW);
}

void carBack(int leftSpeed,int rightSpeed){             //Move backward
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,HIGH);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,HIGH);
}
void carAdvance(int leftSpeed,int rightSpeed){          //Move forward  
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,LOW);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,LOW);
}

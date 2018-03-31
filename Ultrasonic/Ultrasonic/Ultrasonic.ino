// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jrodrigo.net )
// more info at http://www.ardublog.com
// Wiki: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04/wiki/Plug-&-Play

#include "Ultrasonic.h"

Ultrasonic ultrasonic(12,13); // (Trig PIN,Echo PIN)

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT); // trig pin
  pinMode(13, INPUT); // echo ping
  digitalWrite(12, HIGH); 
  digitalWrite(13, LOW);  
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  delay(100);
}

int speedPin_M1 = 5;     //M1 Speed Control E1
int speedPin_M2 = 6;     //M2 Speed Control E2
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;     //M1 Direction Control

void setup(){ 
                              
}

void loop(){
    carAdvance(150,150);
    delay(1000);
    carBack(150,150);
    delay(1000);
    carTurnLeft(150,150);
    delay(1000);
    carTurnRight(150,150);
    delay(1000);
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
  digitalWrite(directionPin_M1,LOW);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,LOW);
}
void carAdvance(int leftSpeed,int rightSpeed){          //Move forward  
  analogWrite (speedPin_M2,leftSpeed);
  digitalWrite(directionPin_M1,HIGH);    
  analogWrite (speedPin_M1,rightSpeed);    
  digitalWrite(directionPin_M2,HIGH);
}

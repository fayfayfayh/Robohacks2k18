int LED_PIN = 13;
char buf[10];

void setup() {
  
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

}

void loop() {

  int data_len = 0;
  while (1) {

    while (Serial.available()){
      buf[data_len++ % 10] = Serial.read();
    }

    if (data_len > 2) {
      if (buf[data_len - 2] == '\r' && buf[data_len - 1] == '\n') 
        break; // end
    }

    if ((data_len==4) && (!strncmp(buf,"ON",2))) {
      //digitalWrite(LED_PIN, HIGH); // Set D13 pin as high and openg the light L
      Serial.println("LIGHT ON");
    }
    
    else if((data_len==5)&&(!strncmp(buf,"OFF",3))) {
      //digitalWrite(LED_PIN, LOW); // Set D13 pin as low and the light L
      Serial.println("LIGHT OFF");
    }

    
    
  }

}

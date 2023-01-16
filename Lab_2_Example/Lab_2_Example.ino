int count = 0; 
char buf[5]; 

void setup() {
  Serial.begin(9000); 
}

void loop() {
  if(Serial.available()){
    char rec; 
    rec = Serial.read(); 
    Serial.print("Recieved: "); 
    Serial.println(rec); 
    count = count + (rec - '0'); 
    Serial.print("Count + Rec = "); 
    Serial.println(count); 
  }

  // if(Serial.available()){
  //   char rec; 
  //   rec = Serial.read(); 
  //   buf[count] = rec; 
  //   count++;
  //   if (count == 5)
  //     count = ;0
  //   Serial.print("recieved: "); 
  //   Serial.println(buf); 
  // }

  // if(Serial.available()){
  //   char rec; 
  //   rec = Serial.read(); 
  //   Serial.print("recieved: "); 
  //   Serial.println(rec; 
  // }

  // count = Serial.available(); 
  // Serial.println("Count = "); 
  // Serial.println(count); 
  // delay(2000); 
}

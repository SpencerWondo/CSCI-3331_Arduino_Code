int redpin = 11; 
int bluepin = 10; 
int greenpin = 9; 
int val; 

void setup() {
  pinMode(redpin, OUTPUT); 
  pinMode(bluepin, OUTPUT); 
  pinMode(greenpin, OUTPUT); 
  Serial.begin(9600); 

}

void loop() {

  //This analog write function will woprk to dim the led by calling the pin and the val next to it
  // Val = 1 (dim)
  // Val = 10 (mid)
  // Val = 100 (high)

  analogWrite(9, 1);

  delay(1000); 

  analogWrite(9, 10); 

  delay(1000); 

  analogWrite(9, 100); 

  delay(1000); 
  // for(val = 255; val > 0; val--){
  //   analogWrite(11, val); 
  //   analogWrite(10, 255 - val); 
  //   analogWrite(9, 128 - val); 
  //   Serial.println(val, DEC); 
  //   delay(5);
  // }
  // for(val = 255; val < 0; val++){
  //   analogWrite(11, val); 
  //   analogWrite(10, 255 - val); 
  //   analogWrite(9, 128 - val); 
  //   Serial.println(val, DEC); 
  //   delay(5);
  // }

}

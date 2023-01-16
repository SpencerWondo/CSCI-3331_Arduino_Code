void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 


}

void loop() {
  // put your main code here, to run repeatedly:
  int joyX = analogRead(A0); 
  serial.println(joyX); 
  delay(1000); 

}

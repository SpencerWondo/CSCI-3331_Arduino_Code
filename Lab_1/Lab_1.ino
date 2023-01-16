// Spencer Wondolowski 
// Computer Organization Lab 1 (Fall 2022)
// 9/20/2022
//
//
// ------Parts------
//    Push Button
//    Tilt sensor
//    Reed Switch
//    Arduino Uno
//    Sensor Shield

int greenPin = 4; 
int redPin = 5; 
int bluePin = 3; 
int pbPin = 8; 


void setup() {
  pinMode(greenPin, OUTPUT);  // Green LED
  pinMode(redPin, OUTPUT);    // Red LED
  pinMode(bluePin, OUTPUT);   // Blue LED

  pinMode(pbPin, Input_pull_up); 
}

void loop() {
  // digitalWrite(redPin, HIGH); 
  // digitalWrite(bluePin, LOW); 
  // digitalWrite(greenPin, LOW); 

  // delay(1000); // milliseconds (1000ms = 1s)

  // digitalWrite(redPin, LOW); 
  // digitalWrite(bluePin, HIGH); 
  // digitalWrite(greenPin, LOW); 

  // delay(1000); 

  // digitalWrite(redPin, LOW); 
  // digitalWrite(bluePin, LOW); 
  // digitalWrite(greenPin, HIGH); 

  int press; 
  press = digitalRead(pbPin); 

  if (press == LOW) {
    digitalWrite(redPin, LOW); 
    digitalWrite(bluePin, HIGH); 
    digitalWrite(greenPin, LOW);
  } else {
    digitalWrite(redPin, LOW); 
    digitalWrite(bluePin, LOW); 
    digitalWrite(greenPin, HIGH); 
  }
}

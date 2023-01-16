// Spencer Wondolowski 
// Computer Organization Lab 1 Actually (Fall 2022)
// 9/20/2022
//
// Student ID number : 00704838
// Student ID in Morse -----|-----|--...|-----|....-|---..|...--|---..
//
// Dash = red
// Dot = green
//
// ------Parts------
//    Push Button
//    Tilt sensor
//    Reed Switch
//    Arduino Uno
//    Sensor Shield

int greenPin = 4; 
int redPin = 5; 
int bluePin = 2; 

int pbPin = 8; 

int reedPin = 11;

int press_num = 0;

int reed;
int press; 

void setup() {
  pinMode(greenPin, OUTPUT);  // Green LED
  pinMode(redPin, OUTPUT);    // Red LED
  pinMode(bluePin, OUTPUT);   // Blue LED

  pinMode(pbPin, INPUT_PULLUP); 

  pinMode(reedPin, INPUT); 
}

// Code for the turning on and off of the led per color ----------------------------------------------------

void red(){
  digitalWrite(redPin, HIGH); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, LOW);
  delay(100);  
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, LOW);
  delay(100);
}

void green(){
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, HIGH); 
  delay(100);
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, LOW);
  delay(100); 
}

void blue(){
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, HIGH); 
  digitalWrite(greenPin, LOW);
  delay(1000);
}

// Variable for the morse code value per digit -----------------------------

void zero(){
  red(); 
  red();
  red();
  red();
  red();
  delay(1000);
}
void one(){
  green(); 
  red();
  red();
  red();
  red();
  delay(1000);
}
void two(){
  green(); 
  green();
  red();
  red();
  red();
  delay(1000);
}
void three(){
  green(); 
  green();
  green();
  red();
  red();
  delay(1000);
}
void four(){
  green(); 
  green();
  green();
  green();
  red();
  delay(1000);
}
void five(){
  green(); 
  green(); 
  green(); 
  green(); 
  green(); 
  delay(1000);
}
void six(){
  red(); 
  green(); 
  green(); 
  green(); 
  green(); 
  delay(1000);
}
void seven(){
  red(); 
  red(); 
  green(); 
  green(); 
  green(); 
  delay(1000);
}
void eight(){
  red(); 
  red(); 
  red(); 
  green(); 
  green(); 
  delay(1000);
}
void nine(){
  red(); 
  red(); 
  red(); 
  red(); 
  green(); 
  delay(1000);
}

void loop() {

  press = digitalRead(pbPin); 
  reed = digitalRead(reedPin);

  if (press == LOW) {
    if (press_num == 0){
      zero(); 
      press_num += 1; 
    } 
    else if (press_num == 1){
      zero(); 
      press_num += 1; 
    }
    else if (press_num == 2){
      seven(); 
      press_num += 1; 
    }
    else if (press_num == 3){
      zero(); 
      press_num += 1; 
    }
    else if (press_num == 4){
      four(); 
      press_num += 1; 
    }
    else if (press_num == 5){
      eight(); 
      press_num += 1; 
    }
    else if (press_num == 6){
      three(); 
      press_num += 1; 
    }
    else if (press_num == 7){
      eight(); 
      press_num += 1; 
    }
    else if (press_num == 8){
      red(); 
      green(); 
      blue();  
    }

  }

  if(reed == HIGH){
    press_num = 0;
    red(); 
  }

}
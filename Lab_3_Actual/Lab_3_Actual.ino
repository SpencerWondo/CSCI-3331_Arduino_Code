// Spencer Wondolowski 
// Computer Organization Lab 3 Actual (Fall 2022)
// 11/7/2022
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

#include <EEPROM.h> 

int greenPin = 4; 
int redPin = 5; 
int bluePin = 2; 

int pbPin = 8; 

int reedPin = 11;

int press_num = 0;

int reed;
int press; 

int dash_color = EEPROM.read(0); // EEPROM 0
int dot_color = EEPROM.read(1);  // EEPROM 1
int delay_time = EEPROM.read(2); // EEPROM 2

bool done = false; 

char *numbers[] = {
  // The numbers 0-9 in Morse code  
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", 
  "--...", "---..", "----."
};

void setup() {
  pinMode(greenPin, OUTPUT);  // Green LED
  pinMode(redPin, OUTPUT);    // Red LED
  pinMode(bluePin, OUTPUT);   // Blue LED

  pinMode(pbPin, INPUT_PULLUP); 

  pinMode(reedPin, INPUT); 

  EEPROM.read(0); 

  Serial.begin(9600);  
}

// Code for the turning on and off of the led per color ---------------------------------------------------------------

void red(){
  digitalWrite(redPin, HIGH); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, LOW);
  delay(delay_time);  
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, LOW);
  delay(delay_time);
}

void green(){
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, HIGH); 
  delay(delay_time);
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, LOW);
  delay(delay_time); 
}

void blue(){
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, HIGH); 
  digitalWrite(greenPin, LOW);
  delay(delay_time);
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, LOW);
  delay(delay_time);
}





void id_num(){
  char id; 

  while (!done){

    if (Serial.available()){
      id = Serial.read(); 

      if (id >= '0' && id <= '9') {
        Serial.println(id);
        flash_morse(numbers[id - '0']);
      }
    }

  }
  
}

void flash_morse(char *morse_code){
  unsigned int i = 0; 

  while (morse_code[i] != NULL){
    flash_dot_dash(morse_code[i]); 
    i++; 
  }
  
}

void flash_dot_dash(char dot_or_dash){
  press = digitalRead(pbPin); 

  if (dot_or_dash == '.'){
    if (press == LOW){
      dot(); 
    }     
  } else {
    if (press == LOW){
      dash(); 
    }      
  }

}





// Variable for the Changes in colors of the dots and dashes -----------------------------------------------------------

void dot_change(String &color){
  while (Serial.available() == 0){}

  for (int i = 0; i < 1; i++){
    Serial.println("[red] | [green] | [blue]");
    Serial.println("Enter Dot Color: "); 

    String dot_str = Serial.readString(); 
    dot_str.trim(); 

    if(dot_str == "cdr"){
      color = "red";
      loop(); 
    }else if(dot_str == "cdg") {
      color = "green"; 
      loop(); 
    } else if(dot_str == "cdb") {
      color = "blue";
      loop(); 
    }    
  }
}

void dash_change(String &color2){
  while (Serial.available() == 0){}

  for (int i = 0; i < 1; i++){
    Serial.println("[red] | [green] | [blue]");
    Serial.println("Enter Dash Color: "); 

    String dash_str = Serial.readString(); 
    dash_str.trim();  

    if(dash_str == "cDr"){
      color2 = "red"; 
      loop();
    } else if(dash_str == "cDg") {
      color2 = "green";
      loop();
    } else if(dash_str == "cDb") {
      color2 = "blue"; 
      loop();   
    }
  }
}

// Variable for the actual color in the dots ---------------------------------------------------------------------------

void dot_color_funct(){ 
  String dot_color2; 
  dot_change(dot_color2); 
  
  if (dot_color2 == "red"){
    dot_color = 1; 
  } else if (dot_color2 == "green"){
    dot_color = 2; 
  } else if (dot_color2 == "blue"){ 
    dot_color = 3; 
  }
}

void dash_color_funct(){
  String dash_color2; 
  dash_change(dash_color2); 
  
  if (dash_color2 == "red"){
    dash_color = 1; 
  } else if (dash_color2 == "green"){
    dash_color = 2;
  } else if (dash_color2 == "blue"){
    dash_color = 3 ;
  }
}

void dot(){
  if (dot_color == 1){
    red(); 
  } else if (dot_color == 2){
    green(); 
  } else if (dot_color == 3){
    blue(); 
  }
}

void dash(){
  if (dash_color == 1){
    red(); 
  } else if (dash_color == 2){
    green(); 
  } else if (dash_color == 3){
    blue(); 
  }
}

// Variable for the change in time for the dashes ----------------------------------------------------------------------

void speed(){
  Serial.println("[s1] | [s2] | [s3]");

  while (Serial.available() == 0){}

  String delay = Serial.readString(); 
  delay.trim(); 

  if(delay == "s1"){
    delay_time = 1000;
    loop();  
  } else if(delay == "s2") {
    delay_time = 500; 
    loop();
  } else if(delay == "s3") {
    delay_time = 100; 
    loop();  
  }
}

// Variable for the morse code value per digit ------------------------------------------------------------------

void zero(){
  dash(); 
  dash();
  dash();
  dash();
  dash();
  delay(1000);
}
void one(){
  dot(); 
  dash(); 
  dash();
  dash();
  dash();
  delay(1000);
}
void two(){
  dot(); 
  dot();
  dash();
  dash();
  dash();
  delay(1000);
}
void three(){
  dot(); 
  dot();
  dot();
  dash();
  dash();
  delay(1000);
}
void four(){
  dot(); 
  dot();
  dot();
  dot();
  dash();
  delay(1000);
}
void five(){
  dot(); 
  dot();
  dot();
  dot(); 
  dot(); 
  delay(1000);
}
void six(){
  dash(); 
  dot(); 
  dot();
  dot();
  dot();
  delay(1000);
}
void seven(){
  dash(); 
  dash(); 
  dot(); 
  dot(); 
  dot(); 
  delay(1000);
}
void eight(){
  dash(); 
  dash(); 
  dash(); 
  dot(); 
  dot(); 
  delay(1000);
}
void nine(){
  dash(); 
  dash(); 
  dash(); 
  dash(); 
  dot(); 
  delay(1000);
}

// variable for the blinking of lights 

void blinkLoop(){
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

// Actual loop

void loop() {

  if(Serial.available()){
    String dot_str = Serial.readString(); 
    dot_str.trim(); 

    if(dot_str == "cdr"){
      dot_color_funct(); 
    } 
    
    else if (dot_str == "cDr"){
      dash_color_funct();
    } 
    
    else if (dot_str == "s"){
      speed();       
    } 
    
    else if(dot_str == "i"){
      id_num();
    } 
    
    else {
      loop(); 
    }
  }

  press = digitalRead(pbPin); 
  reed = digitalRead(reedPin);

  if (press == LOW) {
    blinkLoop(); 
  }

  if(reed == HIGH){
    press_num = 0;
  
    EEPROM.write(0, dash_color); 
    EEPROM.write(1, dot_color); 
    EEPROM.write(2, delay_time);   

    red(); 
  }

}
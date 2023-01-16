// Spencer Wondolowski 
// Computer Organization Lab 4 Actual (Fall 2022)
// 12/20/2022
//
// ------Parts------
//    Joystick 
//    Temperature Sensor 
//    Light Sensor

// Setup for the Temp sensor 

int ThermistorPin = A3;
int Vo;
float R1 = 10000; // value of R1 on board
float logR2, R2, T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor

// Setup for the Joystick

int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

// Setup for the dimmable light

int redpin = 11; 
int bluepin = 10; 
int greenpin = 9; 
int val; 
int pin;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);

  pinMode(redpin, OUTPUT); 
  pinMode(bluepin, OUTPUT); 
  pinMode(greenpin, OUTPUT); 
  
}

// Code for the Joystick Output (DONE WITH CALIBRATION)

void Joystick() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  String positionX = "";
  String positionY = "";
 
  if (mapX >= -23){
    positionY = "UP"; 
  }
  if (mapX <= -19){
    positionY = "DOWN"; 
  }
  if (mapX == -21 || mapX == -22){
    positionY = "CENTER";
  }

  if (mapY >= -1){
    positionX = "RIGHT"; 
  }
  if (mapY <= -4){
    positionX = "LEFT"; 
  }
  if (mapY == -2 || mapY == -3){
    positionX = "CENTER";
  }

  Serial.print("(");
  Serial.print(positionX);
  Serial.print(",");
  Serial.print(positionY);
  Serial.print(") \n");

  delay(100);
}

// Temperature Sensor Code 

void Temp() {
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculate resistance on thermistor
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // temperature in Kelvin
  T = T - 273.15; //convert Kelvin to Celcius
  T = (T * 9.0)/ 5.0 + 32.0; //convert Celcius to Farenheit
  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" F"); 
  delay(500);
}

// Light Sensor Code 

void Light() {
  int analogValue = analogRead(A5);

  Serial.print("Analog reading: ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 10) {
    Serial.println(" - Dark");
  } else if (analogValue < 200) {
    Serial.println(" - Dim");
  } else if (analogValue < 500) {
    Serial.println(" - Light");
  } else if (analogValue < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }

  delay(500);
}

void led_dim(){
  analogWrite(pin, val); 
}

void loop(){

  if(Serial.available()){
    String task = Serial.readString(); 
    task.trim(); 

    if (task == "j"){
      Joystick();
    }

    if (task == "T"){
      Temp(); 
    }

    if (task == "L"){
      Light(); 
    }

    // red

    if (task == "r1"){
      analogWrite(11, 1);  
    }       

    if (task == "r2"){
      analogWrite(11, 25);  
    }  

    if (task == "r3"){
      analogWrite(11, 100);  
    }   

    // blue

    if (task == "b1"){
      analogWrite(10, 1);  
    }       

    if (task == "b2"){
      analogWrite(10, 25);  
    }  

    if (task == "b3"){
      analogWrite(10, 100);  
    }   

    // green

    if (task == "g1"){
      analogWrite(9, 1);  
    }       

    if (task == "g2"){
      analogWrite(9, 25);  
    }  

    if (task == "g3"){
      analogWrite(9, 100);  
    }  
  }

}





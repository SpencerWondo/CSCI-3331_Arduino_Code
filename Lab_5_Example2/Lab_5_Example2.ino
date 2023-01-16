// int VRx = A0;
// int VRy = A1;
// int SW = 2;

// int xPosition = 0;
// int yPosition = 0;
// int SW_state = 0;
// int mapX = 0;
// int mapY = 0;

// void setup() {
//   Serial.begin(9600); 
  
//   pinMode(VRx, INPUT);
//   pinMode(VRy, INPUT);
//   pinMode(SW, INPUT_PULLUP); 
  
// }

// void loop() {
//   xPosition = analogRead(VRx);
//   yPosition = analogRead(VRy);
//   SW_state = digitalRead(SW);
//   mapX = map(xPosition, 0, 1023, -512, 512);
//   mapY = map(yPosition, 0, 1023, -512, 512);
  
//   Serial.print("X: ");
//   Serial.print(mapX);
//   Serial.print(" | Y: ");
//   Serial.print(mapY);
//   Serial.print(" | Button: ");
//   Serial.println(SW_state);

//   delay(100);
  
// }


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0);

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


// int ThermistorPin = A0;
// int Vo;
// float R1 = 10000; // value of R1 on board
// float logR2, R2, T;
// float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor
// void setup() {
//   Serial.begin(9600);
// }
// void loop() {
//   Vo = analogRead(ThermistorPin);
//   R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculate resistance on thermistor
//   logR2 = log(R2);
//   T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // temperature in Kelvin
//   T = T - 273.15; //convert Kelvin to Celcius
//  // T = (T * 9.0)/ 5.0 + 32.0; //convert Celcius to Farenheit
//   Serial.print("Temperature: "); 
//   Serial.print(T);
//   Serial.println(" C"); 
//   delay(500);
// }

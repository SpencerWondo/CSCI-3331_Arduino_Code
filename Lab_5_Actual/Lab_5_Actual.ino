// Spencer Wondolowski 
// Computer Organization Lab 5 Actual (Fall 2022)
// 12/18/2022
//
// ------Parts------
//  Three Color LED

#include <TimerOne.h>

int randomNumber;
String a = ": "; 

bool T_1_Working = true; 
bool T_2_Working = true;
bool T_3_Working = true;

int greenPin = 4; 
int redPin = 5; 
int bluePin = 2; 

int elements[50]; 

void setup() {
  pinMode(greenPin, OUTPUT);  // Green LED
  pinMode(redPin, OUTPUT);    // Red LED
  pinMode(bluePin, OUTPUT);   // Blue LED
  Serial.begin(9600); 
}

void red(){
  digitalWrite(redPin, HIGH); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, LOW);
  delay(1000); 
}

void green(){
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, HIGH); 
  delay(1000); 
}

void blue(){
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, HIGH); 
  digitalWrite(greenPin, LOW);
  delay(1000); 
}

void Off(){
  digitalWrite(redPin, LOW); 
  digitalWrite(bluePin, LOW); 
  digitalWrite(greenPin, LOW);
}

// The code for the first task of generating an array of random elements

void Task_One(){
  if (T_1_Working){
    green(); 
    for (int i = 0; i <= 50; i = i + 1) {
      randomNumber = random(1,50);  
      elements[i] = randomNumber;   
      Serial.println(i + a + randomNumber);
    }
    T_1_Working = false; 
  }
  Off(); 
}

// The Code for the bubble sorting for task 2

void Task_Two(){
  if(T_2_Working){
    bubbleSort(elements, 50);
    Serial.print("Array has been sorted! \n");
    T_2_Working = false; 
  }
}

void bubbleSort(int a[], int size) {
  blue(); 
  for(int i = 0; i <(size-1); i++) {
    for(int o = 0; o < (size-(i+1)); o++) {
      if(a[o] > a[o+1]) {
        int t = a[o];
        a[o] = a[o+1];
        a[o+1] = t;
      }
    }
  }
  Off(); 
}

// The Code for the 3rd task that will print out the sorted list

void Task_Three(){
  if (T_3_Working){
    red(); 
    int i = 0; 
    Serial.print("Sorted Array: ");
    while (i < 50){
      Serial.print(elements[i]); 
      Serial.print(",");
      i++; 
    }
    T_3_Working = false; 
  }
  Off(); 
}

void loop(void) {
  bool play = true; 
  while(play){
    Task_One(); 
    delay(1000); 
    Task_Two();
    delay(1000); 
    Task_Three(); 
    delay(1000); 
    play = false; 
  }
}
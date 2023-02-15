#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, 4);

const byte buttonPins[] = {2, 1, 4, 3}; // LEFT, UP, RIGHT, DOWN

typedef enum {
  START, 
  RUNNING,
  GAMEOVER
} State;

typedef enum {
    LEFT,
    UP,
    RIGHT,
    DOWN
} Direction;

#define piece    3
#define MAP_SIZE_X          40
#define MAP_SIZE_Y          20

State gameState;

int8_t snake[165][2];
uint8_t s_length;

Direction dir;
Direction newDir;

int8_t fruit[2];

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  for (byte i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  setupGame();
}

void setupGame() {
  gameState = START;
  dir = RIGHT;
  newDir = RIGHT;
  resetSnake();
  generateFood();
  display.clearDisplay();
  drawMap();
  display.display();
}

void resetSnake() {
  s_length = 5;
  for(int i = 0; i < s_length; i++) {
    snake[i][0] = MAP_SIZE_X / 2 - i;
    snake[i][1] = MAP_SIZE_Y / 2;
  }
}

int moveTime = 0;

void loop() {
  switch(gameState) {
    case START:
      if(buttonPress()) gameState = RUNNING;
      break;
    case RUNNING:
      moveTime++;
      readDirection();
      if(moveTime >= 20) {
        dir = newDir;
        display.clearDisplay();
        if(moveSnake()) {
          gameState = GAMEOVER;
          delay(1000);
        }
        drawMap();
        display.display();
        checkFood();
        moveTime = 0;
      }
      break;
    case GAMEOVER:
      if(buttonPress()) {
        delay(500);
        setupGame();
        gameState = START;
      }
      break;
  }
  
  delay(10);
}

bool buttonPress() {
  for (byte i = 0; i < 4; i++) {
    byte buttonPin = buttonPins[i];
    if (digitalRead(buttonPin) == LOW) {
      return true;
    }
  }
  return false;
}

void readDirection() {
  for (byte i = 0; i < 4; i++) {
    byte buttonPin = buttonPins[i];
    if (digitalRead(buttonPin) == LOW && i != ((int)dir + 2) % 4) {
      newDir = (Direction)i;
      return;
    }
  }
}

bool moveSnake() {
  int8_t x = snake[0][0];
  int8_t y = snake[0][1];

  switch(dir) {
    case LEFT:
      x -= 1;
      break;
    case UP:
      y -= 1;
      break;
    case RIGHT:
      x += 1;
      break;
    case DOWN:
      y += 1;
      break;
  }

  if(collision(x, y))
    return true;

  for(int i = s_length - 1; i > 0; i--) {
    snake[i][0] = snake[i - 1][0];
    snake[i][1] = snake[i - 1][1];
  }

  snake[0][0] = x;
  snake[0][1] = y;
  return false;
}

void checkFood() {
  if(fruit[0] == snake[0][0] && fruit[1] == snake[0][1])
  {
    if(s_length + 1 <= 165)
      s_length++;
    generateFood();
  }
}

void generateFood() {
  bool b = false;
  do {
    b = false;
    fruit[0] = random(0, MAP_SIZE_X);
    fruit[1] = random(0, MAP_SIZE_Y);
    for(int i = 0; i < s_length; i++) {
      if(fruit[0] == snake[i][0] && fruit[1] == snake[i][1]) {
        b = true;
        continue;
      }
    }
  } while(b);

}

bool collision(int8_t x, int8_t y) {
  for(int i = 1; i < s_length; i++) {
    if(x == snake[i][0] && y == snake[i][1]) return true;
  }
  if(x < 0 || y < 0 || x >= MAP_SIZE_X || y >= MAP_SIZE_Y) return true;
  return false;
}

void drawMap() {
  int offsetX = 128 - piece * MAP_SIZE_X - 2;
  int offsetY = 2;

  display.drawRect(fruit[0] * piece + offsetX, fruit[1] * piece + offsetY, piece, piece, SSD1306_INVERSE);

  for(int i = 0; i < s_length; i++) {
    display.fillRect(snake[i][0] * piece + offsetX, snake[i][1] * piece + offsetY, piece, piece, SSD1306_WHITE);
  }
}
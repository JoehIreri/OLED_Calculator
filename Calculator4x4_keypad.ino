#include <Keypad.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



#define I2C_SCL 2  // SCL
#define I2C_SDA 42  // SDA


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define PWM_CHANNEL 0


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define ROW_NUM     4 // four rows
#define COLUMN_NUM  4 // four columns
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte pin_rows[ROW_NUM] = {1, 10, 9, 11}; // Keypad row pins
byte pin_column[COLUMN_NUM] = {12, 14, 21, 34};  // Keypad column pins
Keypad keypad = Keypad( makeKeymap(keys), pin_column, pin_rows, COLUMN_NUM, ROW_NUM);

String input = "";  // Store user input
char operation;
float num1 = 0, num2 = 0;

void setup() {
  Serial.begin(115200);
  
 

  // Setting up custom I2C pins
  Wire.begin(I2C_SDA, I2C_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(200);
 
  // Display Calculator on startup
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.print("Calculator");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    if (key >= '0' && key <= '9') {  // If the key is a number
      input += key;  // Append number to input string
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print(input);  // Display the current input
      display.display();
    }
    else if (key == 'C') {  // Clear input
      input = "";
      num1 = num2 = 0;
      display.clearDisplay();
      display.display();
    }
    else if (key == '+' || key == '-' || key == '*' || key == '/') {
      operation = key;  // Store the operation
      num1 = input.toFloat();  // Convert current input to number
      input = "";  // Clear input for next number
      display.clearDisplay(); // Clear display to show operation clearly
      display.setCursor(0, 0);
      display.print(num1); // Display first number
      display.setCursor(0, 16); // Move to next line for operation
      display.print(operation);  // Display the operation
      display.display();
    }
    else if (key == '=') {
      num2 = input.toFloat();  // Get the second number
      float result = calculate(num1, num2, operation);  // Perform calculation
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print(result);  // Display result
      display.display();
      input = "";  // Reset input for new calculations
    }
  }
}

float calculate(float n1, float n2, char op) {
  switch (op) {
    case '+': return n1 + n2;
    case '-': return n1 - n2;
    case '*': return n1 * n2;
    case '/': return n2 != 0 ? n1 / n2 : 0;  // Check for divide by zero
    default: return 0;
  }
}

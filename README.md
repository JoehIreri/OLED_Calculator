## OLED_Calculator
# Arduino Calculator with OLED Display and Keypad
# Project Overview
This Arduino project implements a basic calculator with a 4x4 keypad for input and an OLED display for output. The calculator supports basic arithmetic operations: addition, subtraction, multiplication, and division.

# Components Used
Arduino Board (e.g., Arduino Uno, Mega)
4x4 Matrix Keypad - for user input
0.96" I2C OLED Display (128x64) - for displaying input and results
Jumper wires and breadboard (if applicable)
# Libraries
This project uses the following libraries:

Keypad.h: For reading input from the keypad.
Wire.h: For I2C communication with the OLED display.
Adafruit_GFX.h and Adafruit_SSD1306.h: For controlling the OLED display.
Install these libraries through the Arduino IDE Library Manager if you haven't already.

# Pin Configuration
OLED I2C Pins:
SDA (Data) connected to pin 42
SCL (Clock) connected to pin 2
Keypad Pins:
Row Pins: {1, 10, 9, 11}
Column Pins: {12, 14, 21, 34}
Note: Adjust the pins as necessary for your specific Arduino board.

# Code Description
Key Features
OLED Display: Displays user input, selected operation, and the result.
Arithmetic Operations: Supports addition, subtraction, multiplication, and division.
Keypad Input: Detects numeric and operator inputs, as well as special commands such as C (Clear) and = (Evaluate).
Operation Flow
Startup: The OLED displays "Calculator" for 2 seconds at startup.
Input:
Numbers entered via keypad are appended to the current input.
Operator keys (+, -, *, /) store the first number and selected operation.
= calculates the result based on the selected operation.
Display:
Each keypress updates the display.
The result of the operation is displayed upon pressing =.
Functions
setup(): Initializes the keypad, OLED display, and I2C communication.
loop(): Continuously reads keypad inputs and performs calculations based on input keys.
calculate(float n1, float n2, char op): Takes two numbers and an operator to perform the desired operation.
# Usage

Enter numbers (0-9).
Choose an operator (+, -, *, /).
Press = to see the result.
Press C to clear the input and reset.
Example Calculation:

Enter 5, then +, then 3, and finally = to see 8 displayed.
# Important Notes
Division by Zero: The code prevents division by zero by returning 0 if the second number is 0.
Display Dimensions: Adjust SCREEN_WIDTH and SCREEN_HEIGHT if using a different OLED display size.
# Future Enhancements
Add more functions: Extend with advanced operations such as square roots or power functions.
Error Handling: Improve error messages for invalid operations (e.g., divide by zero).
Enhanced UI: Use the OLED display to show more detailed steps of the calculation process.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

// Initialization
LiquidCrystal_I2C lcd(0x27, 16, 2);
String Display = "";
String Command = "";
String str = "";
bool Turn = false;
int step_number = 0;

void setup()
{
  // Setup Display
  lcd.init();
  lcd.backlight();
  ClearDisplay();
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop()
{
  // Check Serial
  if (!Serial.available()) return;
  str = Serial.readString();
  
  // Recieved Command
  if (str.startsWith("SSZ"))
  {
    lcd.clear();
    Display = "Command Recieved";
    lcd.setCursor(0, 0);
    lcd.print(Display);
    str.remove(0, 4);
    Command = str;
    VerifyCommand(Command);
    delay(100);
    ClearDisplay();
  }
}

void ClearDisplay()
{
  lcd.clear();
  Display = " SSZ UE4 Bridge";
  lcd.setCursor(0, 0);
  lcd.print(Display);
  Display = "Waiting 4 Unreal";
  lcd.setCursor(0, 1);
  lcd.print(Display);
}

void InvalidCommand()
{
  lcd.clear();
  Display = Command;
  lcd.setCursor(0, 1);
  lcd.print(Display);
  Display = "Invalid  Command";
  lcd.setCursor(0, 0);
  lcd.print(Display);
}

void PrintCommand(String PrintMe)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(String("Command Recieved"));
  Display = PrintMe;
  lcd.setCursor(0, 1);
  lcd.print(Display);

}

void VerifyCommand(String InputCommand)
{
  if (InputCommand == String("TurnRight"))
  {
    PrintCommand(InputCommand);
    TurnRight();
    return;
  }
  if (InputCommand == String("TurnLeft"))
  {
    PrintCommand(InputCommand);
    TurnLeft();
    return;
  }
  InvalidCommand();
}

void TurnRight()
{
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
}

void TurnLeft()
{
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  delay(2);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  
}
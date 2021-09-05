#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialization
LiquidCrystal_I2C lcd(0x27, 16, 2);
String Display = "";
String Command = "";
String str = "";

void setup()
{
  // Setup Display
  lcd.init();
  lcd.backlight();
  ClearDisplay();
  Serial.begin(9600);
  Serial.setTimeout(5);
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
    delay(1000);
    ClearDisplay();
  }
}

void ClearDisplay()
{
  lcd.clear();
  Display = "Waiting 4 Unreal";
  lcd.setCursor(0, 0);
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

void VerifyCommand(String InputCommand)
{
  if (InputCommand == String("Left"))
  {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(Command);
    Display = "Left";
    lcd.setCursor(0, 1);
    lcd.print(Display);
    return;
  }
  if (InputCommand == String("Right")) 
  {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(Command);
    Display = "Right";
    lcd.setCursor(0, 1);
    lcd.print(Display);
    return;
  }
  InvalidCommand();
}
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
Servo myservo;
String pass;
String star;
//int pos=0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','=','D'}
};
LiquidCrystal lcd(13,12,11,10,A3,8);
byte rowPins[ROWS] = {0,1,2,3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4,5,6,7}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  myservo.attach(9);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("enter password");
}
  
void loop()
{
//  lcd.setCursor(0,0);
//  lcd.print("enter password");
  
  myservo.write(0);
  char c = customKeypad.getKey();
 
 if(c)
 {
    if(c!='=')
    {
      pass += c;
      star+="*";
//      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print(star);
//      lcd.clear();
      Serial.println(pass);
      
    }
    else
    {
      if(pass == "1237")
     {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Login Success");
      delay(1000);
      Serial.println("welcome");
      myservo.write(180);
      delay(3000);
      myservo.write(0);
     }
      else
     {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("access denied");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("re-enter pswd");
      Serial.println("sorry");  
     }
      star="";
      pass="";
    }
 }
 }

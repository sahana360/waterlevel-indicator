
#include <LiquidCrystal.h>
LiquidCrystal lcd(4,3,8,9,10,11);
void setup()
{
  lcd.begin(16, 2);
   lcd.clear();
  //lcd.print("WATER LEVEL IN %");
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop()
{
  int i1=analogRead(A0);
  int i2=analogRead(A1);
  int i3=analogRead(A2);
  int i4=analogRead(A3);
  lcd.clear();
  lcd.print("WATER LEVEL IN % ");
  lcd.setCursor(0,1);
  if((i1>1000) && (i2>1000) && (i3>1000) && (i4>1000))
  {
    digitalWrite(13,HIGH);
    lcd.print("FULL");
  }
  else if((i1>1000) && (i2>1000) && (i3>1000))
  {
    digitalWrite(13,LOW);
    lcd.print("75% water       ");
  }
  else if((i1>1000) && (i2>1000))
  {
    digitalWrite(13,LOW);
    lcd.print("50% water       ");
  }
  else
  {
    digitalWrite(13,LOW);
    lcd.print("<25% water       ");
  }
  delay(1000);
  Serial.println(i1);
  Serial.println(i2);
  Serial.println(i3);
  Serial.println(i4);
  
  // put your main code here, to run repeatedly:

}

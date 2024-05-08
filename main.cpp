#include <LiquidCrystal.h>

int seconds = 0;
int trigger = 6; 
int echo = 7; 

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600); 
  lcd_1.begin(16, 2); 
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT); 
  digitalWrite(trigger, LOW);
}

void loop()
{
  lcd_1.setCursor(0, 0);
  delay(1000); 
  seconds += 1;
  
  long t;
  long d; 

  digitalWrite(trigger, HIGH); 
  delay(100);
  digitalWrite(trigger, LOW); 

  t = pulseIn(echo, HIGH);
  d = t/59; 

  Serial.print("Distancia: "); 
  Serial.print(d);
  Serial.print("cm");
  Serial.println(); 
  delay(50);
  lcd_1.print(d);
  lcd_1.setCursor(3,0); 
  lcd_1.println("cm                ");
}

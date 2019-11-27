#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 2, 3, 4, 5);
LiquidCrystal lcd1( 12,13, 8, 9, 10, 11);
float critTemp = 40; //critical temperature

const int lm350=A0;
float vin0=0;
float temperature0=0;
int dataIn0=0;

const int lm351=A1;
float vin1=0;
float temperature1=0;
int dataIn1=0;

float vin=0;
float temperature=0;
int dataIn=0;

void setup() {
  Serial.begin(9600);
  lcd .begin(16, 2);
  lcd1.begin(16, 2);
  pinMode(lm350, INPUT);
  pinMode(lm351, INPUT);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH);

  lcd1.print("Isik");
  lcd.print("Racing Team");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(1000);
}

//converting analog input from lm35 sensor data to celcius value
float celciusCevir(float dataIn){
  vin = (dataIn / 1023.0) * 5000;
  temperature = vin / 10.0;
  return temperature;
  }

void loop() {
  
  lcd.clear();
  lcd.home();
  
  lcd1.clear();
  lcd1.home();

  lcd.setCursor(0, 0);
  lcd.print("Batarya:");
  lcd1.setCursor(0, 0);
  lcd1.print("Kabin ici:");

  lcd.setCursor(0,1);
  temperature0=celciusCevir(analogRead(lm350));
  lcd.print(temperature0);
  lcd.print(" C");

  lcd1.setCursor(0,1);
  temperature1 = celciusCevir(analogRead(lm351));
  lcd1.print(temperature1);
  lcd1.print(" C");
 delay(250);


 //conditions for alarm to trigger
  if(temperature0>critTemp || temperature1>critTemp){ 
    digitalWrite(A2, LOW);
    }
  else{ 
    digitalWrite(A2, HIGH);
    }

  delay(250);
}

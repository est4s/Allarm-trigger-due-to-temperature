#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 2, 3, 4, 5);
LiquidCrystal lcd1( 12,13, 8, 9, 10, 11);
float critTemp = 40;

const int lm350=A0;
float vin0=0;
float sicaklik0=0;
int gelenVeri0=0;

const int lm351=A1;
float vin1=0;
float sicaklik1=0;
int gelenVeri1=0;

float vin=0;
float sicaklik=0;
int gelenVeri=0;

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

float celciusCevir(float gelenVeri){
  
  vin = (gelenVeri / 1023.0) * 5000;
  sicaklik = vin / 10.0;
  return sicaklik;
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
  sicaklik0=celciusCevir(analogRead(lm350));
  lcd.print(sicaklik0);
  lcd.print(" C");

  lcd1.setCursor(0,1);
  sicaklik1 = celciusCevir(analogRead(lm351));
  lcd1.print(sicaklik1);
  lcd1.print(" C");
 delay(250);


 
  if(sicaklik0>75.0 || sicaklik1>75.0){ 
    digitalWrite(A2, LOW);
    }
  else{ 
    digitalWrite(A2, HIGH);
    }

    
  delay(250);
}

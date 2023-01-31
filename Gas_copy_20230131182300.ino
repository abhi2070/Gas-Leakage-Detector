#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int sensorPin = A0; // choose the input pin (for GAS sensor)
int buzzer = 13; // choose the pin for the Buzzer
int G_led = 8; // choose the pin for the Green LED
int R_led = 9; // choose the pin for the Red Led

int read_value; // variable for reading the gaspin status
void setup()
{
  pinMode(sensorPin, INPUT); // declare sensor as input
  pinMode(buzzer,OUTPUT); // declare Buzzer as output
  pinMode(R_led,OUTPUT); // declare Red LED as output
  pinMode(G_led,OUTPUT); // declare Green LED as output
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" WELCOME To ");
  lcd.setCursor(0,1);
  lcd.print(" GAS Detector ");
  delay(2000);
  lcd.clear();
}
int threshold = 1200; // add a threshold value for unsafe gas level
void loop(){
    int set_ppm = 1000; // set to 1000ppm(parts per million) for LPG gas 
    read_value = (analogRead(sensorPin)); // read input value

    lcd.setCursor(0, 0);
    lcd.print("Gas Level: ");
    lcd.print(read_value);
    lcd.print(" ");

if(read_value>set_ppm){ // check if the gas value is above the set_ppm
    lcd.setCursor(0, 1);
    lcd.print("LPG detected ");
    if(read_value>set_ppm==2000){
            digitalWrite(buzzer, HIGH); // Turn buzzer on.
            delay(100);
    }else{
            digitalWrite(buzzer, HIGH); // Turn buzzer on.
            tone(buzzer,20000,800);
            delay(950);
    }
    digitalWrite(G_led, LOW); // Turn red LED off.
    digitalWrite(R_led, HIGH); // Turn green LED on.
}else{ // If the gas value is not above the set threshold for LPG gas
    lcd.setCursor(0, 1);
    lcd.print(".....Normal.....");
    digitalWrite(buzzer, LOW); // Turn buzzer off.
    digitalWrite(G_led, HIGH); // Turn red LED off.
    digitalWrite(R_led, LOW); // Turn green LED off.
}

}
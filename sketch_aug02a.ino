#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
Adafruit_SSD1306 display(-1);

int pwm;
int apwm;
bool but1;
bool but2;
bool but3;

 void SetPWM() { 
  pwm = constrain(pwm, 0, 255);
  apwm = constrain(apwm, 0, 255);
  pwm = 0 ;                                                                                      
  if(but1 == 1){
    apwm += 10;
    }
   if(but3 == 1){
    apwm -= 10;
    }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0,8);
  display.setTextSize(1);
  display.print("Set pwm:");
  display.print(apwm);
 }

void setup() {
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 pinMode(5,INPUT);
 pinMode(6,INPUT_PULLUP);
 pinMode(7,INPUT);
 pinMode(10,OUTPUT);
 Serial.begin(9600);
}

void loop() { 

  bool but1 = !digitalRead(5);
  bool but2 = !digitalRead(6);
  bool but3 = !digitalRead(7);
  Serial.print("But1:");Serial.println(but1);
  Serial.print("But2:");Serial.println(but2);
  Serial.print("But3:");Serial.println(but3);

  apwm = constrain(apwm, 0, 255);  
  pwm = constrain(pwm, 0, 255); 
  if(but3 == 1){
    apwm += 10;
    }
   if(but1 == 1){
    apwm -= 10;
    }
  
SetPWM();

for (int i = 0; i < 1; i++) {
    if(but2 == 1 & but1 == 0 & but3 == 0){
    pwm = constrain(pwm, 0, 255);
    pwm = apwm;
    Serial.print("Парение со скважностью:");Serial.println(pwm);
    Serial.print("apwm:");Serial.println(apwm);
    analogWrite(10, pwm);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(0,8);
    display.setTextSize(1);
    display.print("Vaping pwm:");
    display.print(pwm);
    analogWrite(13, pwm);
      Serial.println(pwm);
}
else{
      pwm = 0;
      analogWrite(10, pwm);
      }
display.display();
}
Serial.println(pwm);
  Serial.print("apwm:");Serial.println(apwm);

 display.display();

}

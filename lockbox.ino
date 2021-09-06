#include <Time.h>
#include <TimeLib.h>

#include <EEPROM.h>

const unsigned long eventInterval = 10000;
unsigned long previousTime = 0;
unsigned long start1 = 0;
unsigned long start2 = 0;
unsigned long start3 = 0;
unsigned long start4 = 0;
unsigned long start5 = 0;
unsigned long start6 = 0;
unsigned long btstart = 0;
unsigned long starter1 = 0;
unsigned long starter2 = 0;
unsigned long starter3 = 0;
unsigned long starter4 = 0;
unsigned long starter5 = 0;
unsigned long starter6 = 0;
unsigned long starttime = 0;
unsigned long elapsed = 0;
unsigned long remain = 0;
int a = 0;

#include <Servo.h>
Servo myservo; 
char Incoming_value = '0';
char last = '0';
char lastbutton = '0';
int EEPROMaddress1 = 100;
int EEPROMaddress2 = 250;
int EEPROMaddressS1 = 300;
int EEPROMaddressS2 = 400;
int EEPROMaddressS3 = 500;
int EEPROMaddressS4 = 600;
int EEPROMaddressS5 = 700;
int EEPROMaddressS6 = 800;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  lastbutton = EEPROM.read(EEPROMaddress2);
  Incoming_value = Serial.read();
  unsigned long currentTimem = millis();      
  unsigned long currentTime = second();
  EEPROM.write(EEPROMaddress1, currentTime);
  
  if (Incoming_value == '1'){
    myservo.write(0);
    delay(5000);
    myservo.write(90);
    start1 = currentTimem;
    last = '1';
    EEPROM.write(EEPROMaddress2, last);
    EEPROM.write(EEPROMaddressS1, start1);
    start2 = 0;
    start3 = 0;
    start4 = 0;
    start5 = 0;
    start6 = 0;
    a = 2;
  }
  if (Incoming_value == '2'){
    myservo.write(0);
    delay(30000);
    myservo.write(90);
    start2 = currentTimem;
    last = '2';
    EEPROM.write(EEPROMaddress2, last);
    EEPROM.write(EEPROMaddressS2, start2);
    start1 = 0;
    start3 = 0;
    start4 = 0;
    start5 = 0;
    start6 = 0;
    a = 2;
  }
  if (Incoming_value == '3'){
    myservo.write(0);
    delay(30000);
    myservo.write(90);
    start3 = currentTimem;
    last = '3';
    EEPROM.write(EEPROMaddress2, last);
    EEPROM.write(EEPROMaddressS1, start3);
    start1 = 0;
    start2 = 0;
    start4 = 0;
    start5 = 0;
    start6 = 0;
    a = 2;
  }
  if (Incoming_value == '4'){
    myservo.write(0);
    delay(30000);
    myservo.write(90);
    start4 = currentTimem;
    last = '4';
    EEPROM.write(EEPROMaddress2, last);
    EEPROM.write(EEPROMaddressS2, start4);
    start1 = 0;
    start2 = 0;
    start3 = 0;
    start5 = 0;
    start6 = 0;
    a = 2;
  }
  if (Incoming_value == '5'){
    myservo.write(0);
    delay(30000);
    myservo.write(90);
    start5 = currentTimem;
    last = '5';
    EEPROM.write(EEPROMaddress2, last);
    EEPROM.write(EEPROMaddressS1, start5);
    start1 = 0;
    start2 = 0;
    start3 = 0;
    start4 = 0;
    start6 = 0;
    a = 2;
  }
  if (Incoming_value == '6'){
    myservo.write(0);
    delay(30000);
    myservo.write(90);
    start6 = currentTimem;
    last = '6';
    EEPROM.write(EEPROMaddress2, last);
    EEPROM.write(EEPROMaddressS2, start6);
    start1 = 0;
    start2 = 0;
    start3 = 0;
    start4 = 0;
    start5 = 0;
    a = 2;
  }









  
  if (myservo.read() == 90 && start1 > 0){
    if (currentTimem - start1 > 120000){
    myservo.write(0);
  }
}
  if (myservo.read() == 90 && start2 > 0){
    if (currentTimem - start2 > 1800000){
      myservo.write(0);
  } 
  }
  if (myservo.read() == 90 && start3 > 0){
    if (currentTime - start1 > 2700000){
    myservo.write(0);
  }
}
  if (myservo.read() == 90 && start4 > 0){
    if (currentTime - start2 > 3600000){
    myservo.write(0);
  }
  }
  if (myservo.read() == 90 && start5 > 0){
    if (currentTime - start1 > 4500000){
    myservo.write(0);
  }
}
  if (myservo.read() == 90 && start6 > 0){
    if (currentTime - start2 > 5400000){
    myservo.write(0);
  }
  }








  
  
  Serial.println(lastbutton);
  if (a == 0){
    starttime = EEPROM.read(EEPROMaddress1);
    starter1 = EEPROM.read(EEPROMaddressS1);
    starter2 = EEPROM.read(EEPROMaddressS2);
    if (lastbutton == '1'){
      if(currentTime - start1 > 15){
        myservo.write(0);
      }
    }
    else if (lastbutton == '2'){
      if(currentTime - start2 > 30){
        myservo.write(0);
      }
    }
  }
  if (Incoming_value == 'a'){
    myservo.write(0);
    delay(30000);
    myservo.write(90);
  }
  if (Incoming_value == "off"){
    myservo.write(0);
  }

    
}

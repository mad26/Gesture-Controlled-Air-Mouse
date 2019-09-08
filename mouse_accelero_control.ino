#include <SoftwareSerial.h>
const int rxpin = 2, txpin = 3;
SoftwareSerial bluetooth(rxpin, txpin);
const int x=A0;
const int y=A1;
int xh, yh;
int xcord, ycord;
const int trigger = 5;
int lstate = 0;
int rstate = 0;
const int lclick = 6;
const int rclick = 7;
const int led = 8;

void setup()
{
  pinMode(x,INPUT);
  pinMode(y,INPUT);
  pinMode(trigger,INPUT_PULLUP);
  pinMode(lclick,INPUT);
  pinMode(rclick,INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(lclick,HIGH);
  digitalWrite(rclick,HIGH);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop()
{
digitalWrite(led,LOW);
  while(digitalRead(trigger)==LOW)
  { 
    digitalWrite(led, HIGH);
    lstate = digitalRead(lclick);
    rstate = digitalRead(rclick);
    xh=analogRead(x);
    yh=analogRead(y);
    xcord=map(xh,286,429,100,999);
    ycord=map(yh,282,427,100,800);
    Serial.print(xcord);
    Serial.print(ycord);
    if (lstate == LOW)
    Serial.print(1);
    else 
    Serial.print(0);
    if (rstate == LOW)
    Serial.print(1);
    else 
    Serial.print(0);
    bluetooth.print(xcord);
    bluetooth.print(ycord);
    if (lstate == LOW)
    bluetooth.print(1);
    else 
    bluetooth.print(0);
    if (rstate == LOW)
    bluetooth.print(1);
    else 
    bluetooth.print(0);
    delay(4000);
   }
}

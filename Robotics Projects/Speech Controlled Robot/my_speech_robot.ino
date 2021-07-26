/*
  Physical Pixel

  An example of using the Arduino board to receive data from the computer. In
  this case, the Arduino boards turns on an LED when it receives the character
  'H', and turns off the LED when it receives the character 'L'.

  The data can be sent from the Arduino Serial Monitor, or another program like
  Processing (see code below), Flash (via a serial-net proxy), PD, or Max/MSP.

  The circuit:
  - LED connected from digital pin 13 to ground

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/PhysicalPixel
*/
int incomingByte=0;
int LeftFrontMotor=13;
int RightFrontMotor=12;
int LeftBackMotor=10;
int RightBackMotor=9;
int ledPin1=5;
int ledPin2=6;

void setup() {
  // put your setup code here, to run once:
pinMode(LeftFrontMotor,OUTPUT);
pinMode(RightFrontMotor,OUTPUT);
pinMode(LeftBackMotor,OUTPUT);
pinMode(LeftBackMotor,OUTPUT);
pinMode(ledPin1,OUTPUT);
pinMode(ledPin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
  incomingByte=Serial.read();
  if(incomingByte=='F')
  {
    digitalWrite(LeftFrontMotor,HIGH);
    digitalWrite(RightFrontMotor,HIGH);
    digitalWrite(LeftBackMotor,LOW);
    digitalWrite(RightBackMotor,LOW);
    digitalWrite(ledPin1,HIGH);
    delay(1000);
    digitalWrite(ledPin1,LOW);
  }
  else if(incomingByte=='B')
  {
    digitalWrite(LeftFrontMotor,LOW);
    digitalWrite(RightFrontMotor,LOW);
    digitalWrite(LeftBackMotor,HIGH);
    digitalWrite(RightBackMotor,HIGH);
    digitalWrite(ledPin1,HIGH);
    delay(1000);
    digitalWrite(ledPin1,LOW);
  }
  else if(incomingByte=='S')
  {
    digitalWrite(LeftFrontMotor,LOW);
    digitalWrite(RightFrontMotor,LOW);
    digitalWrite(LeftBackMotor,LOW);
    digitalWrite(RightBackMotor,LOW);
    digitalWrite(ledPin2,HIGH);
    delay(1000);
    digitalWrite(ledPin2,LOW);
  }
  else if(incomingByte=='R')
  {
    digitalWrite(LeftFrontMotor,LOW);
    digitalWrite(RightFrontMotor,HIGH);
    digitalWrite(LeftBackMotor,HIGH);
    digitalWrite(RightBackMotor,LOW);
    digitalWrite(ledPin1,HIGH);
    delay(1000);
    digitalWrite(ledPin1,LOW);
  }
  else if(incomingByte=='L')
  {
    digitalWrite(LeftFrontMotor,HIGH);
    digitalWrite(RightFrontMotor,LOW);
    digitalWrite(LeftBackMotor,LOW);
    digitalWrite(RightBackMotor,HIGH);
    digitalWrite(ledPin1,HIGH);
    delay(1000);
    digitalWrite(ledPin1,LOW);
  }
}
}

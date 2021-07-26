int LeftMotorFront=2;
int LeftMotorBack=3;
int RightMotorFront=4;
int RightMotorBack=5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LeftMotorFront,OUTPUT);
pinMode(LeftMotorBack,OUTPUT);
pinMode(RightMotorFront,OUTPUT);
pinMode(RightMotorBack,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available())
{
  char ln=Serial.read();

  if (ln=='W' or ln=='w')
  {
    digitalWrite(LeftMotorFront,HIGH);
    digitalWrite(RightMotorFront,HIGH);
    digitalWrite(LeftMotorBack,LOW);
    digitalWrite(RightMotorBack,LOW);
  }
  else if(ln=='S' or ln=='s')
  {
    digitalWrite(LeftMotorFront,LOW);
    digitalWrite(RightMotorFront,LOW);
    digitalWrite(LeftMotorBack,HIGH);
    digitalWrite(RightMotorBack,HIGH);
  }
  else if(ln=='A' or ln=='a')
  {
    digitalWrite(LeftMotorFront,HIGH);
    digitalWrite(RightMotorFront,LOW);
    digitalWrite(LeftMotorBack,LOW);
    digitalWrite(RightMotorBack,HIGH);
  }
  else if(ln=='D' or ln=='d')
  {
    digitalWrite(LeftMotorFront,LOW);
    digitalWrite(RightMotorFront,HIGH);
    digitalWrite(LeftMotorBack,HIGH);
    digitalWrite(RightMotorBack,LOW);
  }
  else if(ln==32)
  {
    digitalWrite(LeftMotorFront,LOW);
    digitalWrite(RightMotorFront,LOW);
    digitalWrite(LeftMotorBack,LOW);
    digitalWrite(RightMotorBack,LOW);
  }
}
}

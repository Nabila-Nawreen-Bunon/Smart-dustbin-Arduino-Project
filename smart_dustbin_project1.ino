// C++ code
//
#include<Servo.h>
Servo myServo;
int trig_pin=8,echo_pin=12,servo_pin=7;
int distance(int trig, int echo){
  digitalWrite(trig,LOW);
  delayMicroseconds(100);
  digitalWrite(trig,HIGH);
  delayMicroseconds(100);
  digitalWrite(trig,LOW);
  delayMicroseconds(100);
  int duration=pulseIn(echo,HIGH);
  int distance=(0.034*duration)/2;
  return distance;
}
  
void setup()
{
  myServo.attach(servo_pin);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(servo_pin,OUTPUT);
  
}

void loop()
{
  if(distance(trig_pin,echo_pin)<30){
    myServo.write(90);
  }
  else if(distance(trig_pin,echo_pin)>30&&distance(trig_pin,echo_pin)<200){
    myServo.write(0);
  }
}
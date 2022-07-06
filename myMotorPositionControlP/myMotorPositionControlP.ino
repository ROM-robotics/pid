#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>

#define encoder0PinA 2
#define encoder0PinB 5

#define MotorPWM  9
#define MotorPin1 11
#define MotorPin2 10

int       counts = 0.0;
double    MotorVolt, myBit, Vsupply, myFreq, alpha;
double    now_time, prv_time, now_act_angle, des_angle, samplingTime;
double    now_error, prv_error;

void setup() {
  myFreq          = 10.0;
  Vsupply         = 12.0;
  prv_time        = 0.0;
  alpha           = 0.3;
  Serial.begin(9600);
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(MotorPWM, OUTPUT);
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  digitalWrite(encoder0PinA, LOW);
  digitalWrite(encoder0PinB, LOW);
  attachInterrupt(digitalPinToInterrupt(2), readEncoder, CHANGE);
}

void readEncoder()
{
  if (digitalRead(encoder0PinB) == digitalRead(encoder0PinA))
  {
    counts = counts - 1;
  }
  else
  {
    counts = counts + 1;
  }
}

void loop() {
  now_time      = millis() / 1000.0;
  samplingTime  = now_time - prv_time;
  now_act_angle = ( (360.0 * 2.0) / (64 * 50.0)) * counts;
  des_angle     = 90.0*sin(2*PI*1.0*now_time);
  now_error     = des_angle - now_act_angle;
  MotorVolt     = 0.5 * now_error ;
  myBit         = (abs(MotorVolt) / Vsupply) * 255;
  if (myBit > 255)  { myBit = 255; }
  else              { myBit = myBit; }
  if (MotorVolt > 0)  { digitalWrite(MotorPin1, HIGH);  digitalWrite(MotorPin2, LOW);  }
  else                { digitalWrite(MotorPin1, LOW);   digitalWrite(MotorPin2, HIGH); }
  analogWrite(MotorPWM, myBit);

  Serial.print (now_act_angle);
  Serial.print(" ");
  Serial.print (des_angle);
  Serial.print(" ");
  Serial.println(" ");
  prv_time  = now_time;
  prv_error = now_error;
}


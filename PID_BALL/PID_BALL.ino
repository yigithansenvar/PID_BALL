#include <Servo.h>

Servo servo;
#define trig 2
#define echo 3

#define kp 15
#define ki 0.02
#define kd 20

double priError = 0;
double toError = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(5);
  Serial.begin(9600);
  servo.write(50);

}
void loop() {
  PID();
  //  int a = distance();
  //  Serial.println(a);
}

long distance () {
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  delay(100);
  return cm;
}

void PID() {
  
  int dis = distance ();
  int setP = 11;
  int error = setP - dis;
  double Pvalue = error * kp;
  double Ivalue = toError * ki;
  double Dvalue = (error - priError) * kd;

  double PIDvalue = Pvalue + Ivalue + Dvalue;
  priError = error;
  toError += error;
  //Serial.println(PIDvalue);
  int Fvalue = (int)PIDvalue;


  Fvalue = map(Fvalue, -135, 135, 135, 0);


  if (Fvalue < 0) {
    Fvalue = 0;
  }
  if (Fvalue > 135) {
    Fvalue = 135;
  }

  servo.write(Fvalue);
}

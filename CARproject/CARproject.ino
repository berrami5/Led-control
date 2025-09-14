#include <Servo.h>

Servo motor;




int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int ENB = 6;
int IN3 = 5;
int IN4 = 3;


int trig = 12;
int echo = 13;
long duration;
int distance;


int servoMotor = 2;

void setup() {
  pinMode (servoMotor , OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  motor.attach(servoMotor);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

int distanceInCm () {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  delay(100);
  if (distance > 0)return distance;
  
}
int degree45 () {
  motor.write(90);
  int temp1 = distanceInCm ();
  if (temp1 <= 10)return 0;
  delay(100);
  motor.write(45);
  int temp2 = distanceInCm();
  if (temp2 <= 10)return 0;
  delay(100);
  motor.write(135);
  int temp3 = distanceInCm();
  if (temp3 <= 20) return 0;
  delay(100);
  return 1;
}
int degree90 () {
  analogWrite(ENA , 0);
  analogWrite(ENB , 0);
  motor.write(0);
  int temp1 = distanceInCm ();
  delay(100);
  motor.write(180);
  int temp2 = distanceInCm ();
  delay(100);
  analogWrite(ENA , 200);
  analogWrite(ENB , 200);
  if (temp1 < temp2) {
    right();
  }else {
    left();
  }
  
  return 0;
}
void back () {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
void front () {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
}
void left () {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(650);
}
void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(650);
}


void loop() {
  analogWrite(ENA , 150);
  analogWrite(ENB , 150);
  motor.write(0);
  front();
  int d = degree45 ();
  if (d == 0) {
    analogWrite(ENA , 0);
    analogWrite(ENB , 0);
    degree90 ();
  }
}








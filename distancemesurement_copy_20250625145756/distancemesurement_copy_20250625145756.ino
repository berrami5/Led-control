int cm;
int value;
void setup() {
  Serial.begin(9600);
  pinMode(4 , INPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2 , 0);
}
void loop() {
  digitalWrite(2 , 1);
  delay(500);
  digitalWrite(2 , 0);
  value = pulseIn(4, 1, 50000);
  cm = value / 58;

  Serial.print(cm);
  Serial.println(" (cm)");

}


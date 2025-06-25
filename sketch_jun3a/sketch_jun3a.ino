void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
      Serial.println( digitalRead(2));
      digitalWrite(13,1);
      delay(500);
}
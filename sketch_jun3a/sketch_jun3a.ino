int btn_pulldown = 13;
void setup()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
      Serial.print(digitalRead(13));
      Serial.print(" ");
      Serial.print(digitalRead(12));
      Serial.print("\n");
      delay(500);
}
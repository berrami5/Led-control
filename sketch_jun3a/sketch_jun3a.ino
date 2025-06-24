int prev = 1;
int current = 1;
bool v2 = false;
void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
      v2 = digitalRead(2);
      Serial.print(current);
      if (v2 == 1){prev = current++;}
      if (current % 2 == 0) digitalWrite(13, 1);
      if (current % 2 != 0) digitalWrite(13, 0);
      delay(500);
}
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  int led[2] = {13, 12};
  for (int i = 0; i < 2 ; i++) {
    digitalWrite(led[i], HIGH);
    delay(100); 
    digitalWrite(led[i], LOW);
    delay(100); 
  }
}
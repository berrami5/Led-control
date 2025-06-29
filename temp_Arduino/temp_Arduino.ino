void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float temp = 	analogRead(A0) * ( 5.0 / 1023.0) ;
  float c = (temp - 0.5) * 100 ;
  float farad = c * 9.0/5.0 + 32;
  
  
  Serial.print(c);
  Serial.print(" ");
  Serial.println(farad);


  delay(500);
}
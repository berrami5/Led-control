int banary (int n, int index) {
    int res[4];
    int counter = 3;
    while (n > 0) {
        int c = n % 2;
        n /= 2;
        res[counter--] = c;
    }
    return res[index];
}
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
   for (int i = 0 ; i < 16 ; i++) {
    digitalWrite(13 , banary(i , 0));
    digitalWrite(12 , banary(i , 1));
    digitalWrite(11 , banary(i , 2));
    digitalWrite(10 , banary(i , 3));
    delay(500);
   }
}
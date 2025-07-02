byte sevenSegDigits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0 (segments a-f ON, g OFF)
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};
void setup() {
  for (int i = 2 ; i < 9; i++) {
      pinMode(i, OUTPUT);    
    
  }
}

void loop() {
  for (int i = 0 ; i < 10 ; i++) {
    for (int j = 2 ; j < 9 ; j++) {
      digitalWrite(j, sevenSegDigits[i][j-2] == 0 ? LOW : HIGH);
    }
    delay(1000);
  }
}
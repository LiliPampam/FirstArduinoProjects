#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3); 
  Serial.begin(9600);
  Serial.print("The result is: ");
  Serial.println(result);
}

int a = 10, b = 70;
void loop() {
  delay(1000);
  Serial.print("a = ");
  Serial.print(a);
  Serial.print(", b = ");
  Serial.println(b);
  Serial.print(" result = ");
  Serial.println(myFunction(a, b));
  a = a + 4; b = b + 67;
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}

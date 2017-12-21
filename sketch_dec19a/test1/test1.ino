const int pb1 = 2;
const int pb2 = 3;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int led5 = 8;
int led6 = 9;
int test[] {4, 5, 6, 7, 8, 9};
boolean ting = 0;


void setup() {
  Serial.begin(9600);
  pinMode(pb1, INPUT_PULLUP);
  pinMode(pb2, INPUT_PULLUP);
  for (int i = 4; i < 10; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
Serial.print(digitalRead(pb1));
Serial.print("  ");
Serial.println(digitalRead(pb2));
Serial.println("  ");
Serial.println(ting);

  if ( digitalRead(pb1 == 0)) {
    ting = 0;
  }
  if (digitalRead(pb2 == 0)) {
    ting = 1;
  }
  if ( ting == 0) {
    for (int i = 4; i < 10; i++) {
      digitalWrite(i, 1);
      delay(500);
      digitalWrite(i, 0);
    }
  }
  if (ting == 1) {
    for (int i = 9; i >3; i--) {
      if ( i == 3) {
        i =9 ;
      }
      digitalWrite(i, 1);
      delay(500);
      digitalWrite(i, 0);
    }
  }



}

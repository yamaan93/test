int pb0 = 2;
int pb1 = 3;
int  led[] { 4, 5, 6, 7,8,9};
int  test[] {4, 5, 6, 7,8,9};
int counter = 0;//  what row in the array should be called, for turning on segments
int debounceDelay = 200;
int buttonState;// the current reading from the input pin
int buttonState0;
int lastButtonState = 0; // the previous reading from the input pin
int lasButtonState0 = 0; // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled

int i = 0;

void setup() {
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  // setting up pins as inputs
  pinMode(8, INPUT);
  pinMode(9, INPUT);

}
void screen() {
  if ( counter == 0) {
    digitalWrite(led[0], 1);
  }
  else {
    digitalWrite(led[0], 0);
  }
  if ( counter == 1) {
    digitalWrite(led[1], 1);
  }
  else {
    digitalWrite(led[1], 0);
  }
  if ( counter == 2) {
    digitalWrite(led[2], 1);
  }
  else {
    digitalWrite(led[2], 0);
  }
  if ( counter == 3) {
    digitalWrite(led[3], 1);
  }
  else {
    digitalWrite(led[3], 0);
  }
  if ( counter == 4) {
    digitalWrite(led[4], 1);
  }
  else {
    digitalWrite(led[4], 0);
  }
  if ( counter == 5) {
    digitalWrite(led[5], 1);
  }
  else {
    digitalWrite(led[5], 0);
  }
  if ( counter == 6) {
    digitalWrite(led[6], 1);
  }
  else {
    digitalWrite(led[6], 0);
  }
}

void loop() {
  Serial.begin(9600);
  screen();;;

  //button1
  int reading = digitalRead(pb1);
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) < debounceDelay) {

    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only add to counter if the new button state is HIGH
      if (buttonState == HIGH) {
        for (i = 0; i < 8; i++) {
          digitalWrite(test[i], 0);
        }
        counter = (counter + 1) % 11;
      }
    }
  }
  int reading0 = digitalRead(pb0);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading0 != lasButtonState0) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) < debounceDelay) {

    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading0 != buttonState0) {
      buttonState0 = reading0;

      // only add to counter if the new button state is HIGH
      if (buttonState0 == HIGH) {
         for (i = 0; i < 8; i++) {
          digitalWrite(test[i], 0);
        }
       counter = (counter - 1);
       if( counter==7){
        counter =0;
       }
      }
    }
  }
  Serial.print( digitalRead(pb0));
}

/*
  Rotary Phone Dial Reader

  This sketch reads out the number dialed on a rotary phone dial.

  The rotary dial has two signals:
            1) turns ON when the wheel is turning
            2) pulses a count based on the number dialed.

  The results are printed to the serial monitor.
  You'll have to set your own INITPIN and NUMPIN.
  additional code from by LIANA, with help from NAIM, with some borrowed code from ARDUINO EXAMPLES.
  2014 Feb 13
*/
int segPinA = 15;// led 7 green
int segPinB = 16;// led 6 yellow
int segPinC = 19;// led 2 brown
int segPinD = 18;// led 3 red
int segPinE = 17;// led 4 orange
int segPinF = 14;// led 9 blue
int segPinG = 13;// led 10 purple

#define INITPIN 1
#define NUMPIN 2

int onePin = 3;
int twoPin = 4;
int threePin = 5;
int fourPin = 6;
int fivePin = 7;
int sixPin = 8;
int sevenPin = 9;
int eightPin = 10;
int ninePin = 11;
int zeroPin = 12;

int counter; // holds the pulse count for each dial spin
int currentValue = 0;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 5;    // the debounce time; increase if the output flickers

void setup() {
  //start serial connection
  Serial.begin(9600);
  // configure the two inputs, and the onboard LED.
  pinMode(INITPIN, INPUT_PULLUP);
  pinMode(NUMPIN, INPUT_PULLUP);

  pinMode(onePin, OUTPUT);
  pinMode(twoPin, OUTPUT);
  pinMode(threePin, OUTPUT);
  pinMode(fourPin, OUTPUT);
  pinMode(fivePin, OUTPUT);
  pinMode(sixPin, OUTPUT);
  pinMode(sevenPin, OUTPUT);
  pinMode(eightPin, OUTPUT);
  pinMode(ninePin, OUTPUT);
  pinMode(zeroPin, OUTPUT);

  digitalWrite(onePin, HIGH);
  digitalWrite(twoPin, HIGH);
  digitalWrite(threePin, HIGH);
  digitalWrite(fourPin, HIGH);
  digitalWrite(fivePin, HIGH);
  digitalWrite(sixPin, HIGH);
  digitalWrite(sevenPin, HIGH);
  digitalWrite(eightPin, HIGH);
  digitalWrite(ninePin, HIGH);
  digitalWrite(zeroPin, HIGH);

  pinMode(segPinA, OUTPUT);
  pinMode(segPinB, OUTPUT);
  pinMode(segPinC, OUTPUT);
  pinMode(segPinD, OUTPUT);
  pinMode(segPinE, OUTPUT);
  pinMode(segPinF, OUTPUT);
  pinMode(segPinG, OUTPUT);

}

void loop() {

  dialNumber();

}

void dialNumber() {

  int initRead = digitalRead (INITPIN); // Is the wheel turning or not?
  static int lastValue = HIGH;  // holds the last read from the pulse pin.

  if (initRead == LOW) {  // If the wheel is turning....
    int newValue = digitalRead (NUMPIN); // check the pulse pin.
    if (newValue != lastValue) { // if it's CHANGED from the last read...
      lastDebounceTime = millis(); // save its clock cycle; we need to check it.
    }
    // If enough time has passed (aka, it's not just a "bounce" from the
    // analog signal)...
    if ((millis() - lastDebounceTime) > debounceDelay) {
      // and if the current value is DIFFERENT than the one you just read...
      if (currentValue != newValue) {
        currentValue = newValue; // make them the same.
        if (newValue == 1) { // If you just set it to a 1...
          counter++; // it just finished a pulse, so add one to the counter.
        }
      }
    }

    lastValue = newValue; // Your new value becomes the old one for comparison.
    
  } else {

    switch (counter) {

      case 1:
        digitalWrite(onePin, LOW);
        delay(350);
        digitalWrite(onePin, HIGH);
        ONE();
        break;
      case 2:
        digitalWrite(twoPin, LOW);
        delay(350);
        digitalWrite(twoPin, HIGH);
        TWO();
        break;
      case 3:
        digitalWrite(threePin, LOW);
        delay(350);
        digitalWrite(threePin, HIGH);
        THREE();
        break;
      case 4:
        digitalWrite(fourPin, LOW);
        delay(300);
        digitalWrite(fourPin, HIGH);
        FOUR();
        break;
      case 5:
        digitalWrite(fivePin, LOW);
        delay(300);
        digitalWrite(fivePin, HIGH);
        FIVE();
        break;
      case 6:
        digitalWrite(sixPin, LOW);
        delay(300);
        digitalWrite(sixPin, HIGH);
        SIX();
        break;
      case 7:
        digitalWrite(sevenPin, LOW);
        delay(300);
        digitalWrite(sevenPin, HIGH);
        SEVEN();
        break;
      case 8:
        digitalWrite(eightPin, LOW);
        delay(300);
        digitalWrite(eightPin, HIGH);
        EIGHT();
        break;
      case 9:
        digitalWrite(ninePin, LOW);
        delay(300);
        digitalWrite(ninePin, HIGH);
        NINE();
        break;
      case 10:
        digitalWrite(zeroPin, LOW);
        delay(300);
        digitalWrite(zeroPin, HIGH);
        ZERO();
        break;

    }
    counter = 0;
  }

}



void ONE() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, LOW);
  digitalWrite(segPinB, HIGH);
  digitalWrite(segPinC, HIGH);
  digitalWrite(segPinD, LOW);
  digitalWrite(segPinE, LOW);
  digitalWrite(segPinF, LOW);
  digitalWrite(segPinG, LOW);
  delay(4000);
  RESET();
}

void TWO() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, HIGH);
  digitalWrite(segPinB, HIGH);
  digitalWrite(segPinC, LOW);
  digitalWrite(segPinD, HIGH);
  digitalWrite(segPinE, HIGH);
  digitalWrite(segPinF, LOW);
  digitalWrite(segPinG, HIGH);
  delay(4000);
  RESET();

}

void THREE() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, HIGH);
  digitalWrite(segPinB, HIGH);
  digitalWrite(segPinC, HIGH);
  digitalWrite(segPinD, HIGH);
  digitalWrite(segPinE, LOW);
  digitalWrite(segPinF, LOW);
  digitalWrite(segPinG, HIGH);
  delay(4000);
  RESET();

}

void FOUR() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, LOW);
  digitalWrite(segPinB, HIGH);
  digitalWrite(segPinC, HIGH);
  digitalWrite(segPinD, LOW);
  digitalWrite(segPinE, LOW);
  digitalWrite(segPinF, HIGH);
  digitalWrite(segPinG, HIGH);
  delay(4000);
  RESET();

}

void FIVE() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, HIGH);
  digitalWrite(segPinB, LOW);
  digitalWrite(segPinC, HIGH);
  digitalWrite(segPinD, HIGH);
  digitalWrite(segPinE, LOW);
  digitalWrite(segPinF, HIGH);
  digitalWrite(segPinG, HIGH);
  delay(4000);
  RESET();

}

void SIX() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, HIGH);
  digitalWrite(segPinB, LOW);
  digitalWrite(segPinC, HIGH);
  digitalWrite(segPinD, HIGH);
  digitalWrite(segPinE, HIGH);
  digitalWrite(segPinF, HIGH);
  digitalWrite(segPinG, HIGH);
  delay(4000);
  RESET();

}

void SEVEN() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, HIGH);
  digitalWrite(segPinB, HIGH);
  digitalWrite(segPinC, HIGH);
  digitalWrite(segPinD, LOW);
  digitalWrite(segPinE, LOW);
  digitalWrite(segPinF, LOW);
  digitalWrite(segPinG, LOW);
  delay(4000);
  RESET();

}

void EIGHT() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, HIGH);
  digitalWrite(segPinB, HIGH);
  digitalWrite(segPinC, HIGH);
  digitalWrite(segPinD, HIGH);
  digitalWrite(segPinE, HIGH);
  digitalWrite(segPinF, HIGH);
  digitalWrite(segPinG, HIGH);
  delay(4000);
  RESET();

}

void NINE() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, HIGH);
  digitalWrite(segPinB, HIGH);
  digitalWrite(segPinC, HIGH);
  digitalWrite(segPinD, LOW);
  digitalWrite(segPinE, LOW);
  digitalWrite(segPinF, HIGH);
  digitalWrite(segPinG, HIGH);
  delay(4000);
  RESET();

}

void ZERO() {

  CIRCLE();
  delay(250);
  digitalWrite(segPinA, HIGH);
  digitalWrite(segPinB, HIGH);
  digitalWrite(segPinC, HIGH);
  digitalWrite(segPinD, HIGH);
  digitalWrite(segPinE, HIGH);
  digitalWrite(segPinF, HIGH);
  digitalWrite(segPinG, LOW);
  delay(4000);
  RESET();

}


void CIRCLE() {

  digitalWrite(segPinA, HIGH);
  delay(100);
  digitalWrite(segPinA, LOW);
  digitalWrite(segPinB, HIGH);
  delay(100);
  digitalWrite(segPinB, LOW);
  digitalWrite(segPinC, HIGH);
  delay(100);
  digitalWrite(segPinC, LOW);
  digitalWrite(segPinD, HIGH);
  delay(100);
  digitalWrite(segPinD, LOW);
  digitalWrite(segPinE, HIGH);
  delay(100);;
  digitalWrite(segPinE, LOW);
  digitalWrite(segPinF, HIGH);
  delay(100);
  digitalWrite(segPinF, LOW);
  digitalWrite(segPinG, LOW);

}

void RESET() {

  digitalWrite(segPinA, LOW);
  digitalWrite(segPinB, LOW);
  digitalWrite(segPinC, LOW);
  digitalWrite(segPinD, LOW);
  digitalWrite(segPinE, LOW);
  digitalWrite(segPinF, LOW);
  digitalWrite(segPinG, LOW);
  delay(1000);

}

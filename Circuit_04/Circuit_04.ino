int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup()
{
  int index;

  for (index = 0; index <= 7; index++)
  {
    pinMode(ledPins[index], OUTPUT);
  }
}


void loop()
{
  oneAfterAnotherNoLoop();
  //oneAfterAnotherLoop();
  //oneOnAtATime();
  //pingPong();
  //marquee();
  //randomLED();
}

void oneAfterAnotherNoLoop()
{
  int delayTime = 100;

  digitalWrite(ledPins[0], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[1], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[2], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[3], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[4], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[5], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[6], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[7], HIGH);
  delay(delayTime);


  digitalWrite(ledPins[7], LOW);
  delay(delayTime);
  digitalWrite(ledPins[6], LOW);
  delay(delayTime);
  digitalWrite(ledPins[5], LOW);
  delay(delayTime);
  digitalWrite(ledPins[4], LOW);
  delay(delayTime);
  digitalWrite(ledPins[3], LOW);
  delay(delayTime);
  digitalWrite(ledPins[2], LOW);
  delay(delayTime);
  digitalWrite(ledPins[1], LOW);
  delay(delayTime);
  digitalWrite(ledPins[0], LOW);
  delay(delayTime);
}

void oneAfterAnotherLoop()
{
  int index;
  int delayTime = 100;

  for (index = 0; index <= 7; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);
  }

  for (index = 7; index >= 0; index--)
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);
  }
}


void oneOnAtATime()
{
  int index;
  int delayTime = 100;

  for (index = 0; index <= 7; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[index], LOW);
  }
}


/*
pingPong()

This function will step through the LEDs,
lighting one at at time in both directions.
*/

void pingPong()
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
  // make this smaller for faster switching

  // step through the LEDs, from 0 to 7

  for (index = 0; index <= 7; index++)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }

  // step through the LEDs, from 7 to 0

  for (index = 7; index >= 0; index--)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
}


/*
marquee()

This function will mimic "chase lights" like those around signs.
*/

void marquee()
{
  int index;
  int delayTime = 200; // milliseconds to pause between LEDs
  // Make this smaller for faster switching

  // Step through the first four LEDs
  // (We'll light up one in the lower 4 and one in the upper 4)

  for (index = 0; index <= 3; index++) // Step from 0 to 3
  {
    digitalWrite(ledPins[index], HIGH);    // Turn a LED on
    digitalWrite(ledPins[index + 4], HIGH); // Skip four, and turn that LED on
    delay(delayTime);                      // Pause to slow down the sequence
    digitalWrite(ledPins[index], LOW);     // Turn the LED off
    digitalWrite(ledPins[index + 4], LOW); // Skip four, and turn that LED off
  }
}


/*
randomLED()

This function will turn on random LEDs. Can you modify it so it
also lights them for random times?
*/

void randomLED()
{
  int index;
  int delayTime;

  // The random() function will return a semi-random number each
  // time it is called. See http://arduino.cc/en/Reference/Random
  // for tips on how to make random() even more random.

  index = random(8);	// pick a random number between 0 and 7
  delayTime = 100;

  digitalWrite(ledPins[index], HIGH);  // turn LED on
  delay(delayTime);                    // pause to slow down
  digitalWrite(ledPins[index], LOW);   // turn LED off
}


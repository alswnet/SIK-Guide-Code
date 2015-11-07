/*
    74HC595 pin		LED pin		Arduino pin

    1  (QB)		LED 2 +
    2  (QC)		LED 3 +
    3  (QD)		LED 4 +
    4  (QE)		LED 5 +
    5  (QF)		LED 6 +
    6  (QG)		LED 7 +
    7  (QH)		LED 8 +
    8  (GND)				GND

    9  (QH*)
    10 (SRCLR*)				5V
    11 (SRCLK)				Digital 3
    12 (RCLK)				Digital 4
    13 (OE*)				GND
    14 (SER)				Digital 2
    15 (QA)		LED 1 +
    16 (VCC)				5V

*/

int datapin = 2;
int clockpin = 3;
int latchpin = 4;

byte data = 0;

void setup()
{
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(latchpin, OUTPUT);
}


void loop()
{
  oneAfterAnother();

  //oneOnAtATime();

  //pingPong();

  //randomLED();

  //marquee();

  //binaryCount();
}


void shiftWrite(int desiredPin, boolean desiredState)
{
  bitWrite(data, desiredPin, desiredState);
  shiftOut(datapin, clockpin, MSBFIRST, data);
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}

void oneAfterAnother()
{
  int index;
  int delayTime = 100;

  for (index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);
  }

  for (index = 7; index >= 0; index--)
  {
    shiftWrite(index, LOW);
    delay(delayTime);
  }
}

void oneOnAtATime()
{
  int index;
  int delayTime = 100;
  for (index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);
    shiftWrite(index, LOW);
  }
}

void pingPong()
{
  int index;
  int delayTime = 100;

  for (index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);
    shiftWrite(index, LOW);
  }

  for (index = 7; index >= 0; index--)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);
    shiftWrite(index, LOW);
  }
}


void randomLED()
{
  int index;
  int delayTime = 100;
  index = random(8);

  shiftWrite(index, HIGH);
  delay(delayTime);
  shiftWrite(index, LOW);
}


/*
marquee()

This function will mimic "chase lights" like those around signs.
*/

void marquee()
{
  int index;
  int delayTime = 200; // Time (milliseconds) to pause between LEDs
  // Make this smaller for faster switching

  // Step through the first four LEDs
  // (We'll light up one in the lower 4 and one in the upper 4)

  for (index = 0; index <= 3; index++)
  {
    shiftWrite(index, HIGH);    // Turn a LED on
    shiftWrite(index + 4, HIGH); // Skip four, and turn that LED on
    delay(delayTime);		// Pause to slow down the sequence
    shiftWrite(index, LOW);	// Turn both LEDs off
    shiftWrite(index + 4, LOW);
  }
}


/*
binaryCount()

Numbers are stored internally in the Arduino as arrays of "bits",
each of which is a 1 or 0. Just like the base-10 numbers we use
every day, The position of the bit affects the magnitude of its
contribution to the total number:

Bit position   Contribution
0              1
1              2
2              4
3              8
4              16
5              32
6              64
7              128

To build any number from 0 to 255 from the above 8 bits, just
select the contributions you need to make. The bits will then be
1 if you use that contribution, and 0 if you don't.

This function will increment the "data" variable from 0 to 255
and repeat. When we send this value to the shift register and LEDs,
you can see the on-off pattern of the eight bits that make up the
byte. See http://www.arduino.cc/playground/Code/BitMath for more
information on binary numbers.
*/

void binaryCount()
{
  int delayTime = 1000; // time (milliseconds) to pause between LEDs
  // make this smaller for faster switching

  // Send the data byte to the shift register:

  shiftOut(datapin, clockpin, MSBFIRST, data);

  // Toggle the latch pin to make the data appear at the outputs:

  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);

  // Add one to data, and repeat!
  // (Because a byte type can only store numbers from 0 to 255,
  // if we add more than that, it will "roll around" back to 0
  // and start over).

  data++;

  // Delay so you can see what's going on:

  delay(delayTime);
}

/*
  note 	frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz
*/

const int buzzerPin = 9;
const int songLength = 18;

char notes[] = "cdfda ag cdfdg gf ";
int beats[] = {1, 1, 1, 1, 1, 1, 4, 4, 2, 1, 1, 1, 1, 1, 1, 4, 4, 2};
int tempo = 150;


void setup()
{
  pinMode(buzzerPin, OUTPUT);
}


void loop()
{
  int i, duration;

  for (i = 0; i < songLength; i++)
  {
    duration = beats[i] * tempo;

    if (notes[i] == ' ')
    {
      delay(duration);
    }
    else
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);
    }
    delay(tempo / 10);
  }
  while (true) {}
}


int frequency(char note)
{
  int i;
  const int numNotes = 8;  // number of notes we're storing

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < numNotes; i++)
  {
    if (names[i] == note)
    {
      return (frequencies[i]);
    }
  }
  return (0);
}


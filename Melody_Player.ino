/*
Play a song with the piezo buzzer.


There are 4 functions:
  setup()  -- runs once when board starts up
  loop()   -- loops indefinitely
  playTone(frequency, duration) -- plays a note at given frequency and duration 
  frequency(char note)          -- returns the frequency corresponding to a given note


*/
  
const int buzzerPin = 10;
const int led = 7;
// Here is the song:
// Notes is an array of text characters corresponding to the notes
// in your song. A space represents a rest (no tone).
// A capital letter means to play one octave up.
// Beats is an array of values for each note and rest.
// A "1" represents a quarter-note, 2 a half-note, etc.
// Don't forget that the rests (spaces) need a length as well.
// songLength must equal the total number of notes and spaces 
// The tempo is how fast to play the song.
// To make the song play faster, decrease this value.


// I chose Frere Jacques as my song for this portion.
char notes[] = {"CDEC CDEC EFG EFG GAGFEC GAGFEC"};
int beats[] = {1,2,3,4, 1,2,3,1, 3,4,5, 3,4,5, 4,5,4,3,2,1, 4,5,4,3,2,1};
const int songLength = 38;
int tempo = 130;


void setup() 
{
// This runs once when the board starts up
  pinMode(buzzerPin, OUTPUT);
  pinMode(led, OUTPUT);
}


void loop() 
{
// This is called indefinitely
  int i, duration;
  
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
    
    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      playTone(frequency(notes[i]), duration);
     }
    delay(tempo/10);              // brief pause between notes
  }
  
  // We only want to play the song once, so we'll pause forever:
  //while(true){}
  // If you'd like your song to play over and over,
  // remove the above statement
}


int frequency(char note) 
{
  // This function takes a note character and returns the
  // corresponding frequency in Hz for the tone() function.
  
  int i;
  const int numNotes = 14;  // number of notes we're storing
  
  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B'};
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 262*2, 294*2, 330*2, 349*2, 392*2, 440*2, 494*2};
  
  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.
  
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}

void loop_2()
{
// This function is called repeatedly as the sketch runs

  float freq;

  // Step through the frequencies for the scale
  for(freq=32.7; freq <=8000;  freq=freq*2)  // play 6 octaves
  {

     digitalWrite(led,HIGH);
     delay(1);
     digitalWrite(led,LOW);


  }

  // If you only want to play the song once, pause forever:
  // while(true){}
}


void playTone(float frequency, int duration)
{
  // This function plays a tone at the requested frequency for the requested duration.
  // frequency: frequency of the tone
  // duration: how long the tone should last in milliseconds
  
  int pulse = 500000.0/frequency;
  long i;
  
  // Keep looping until the note is finished playing
  for (i = 0; i < duration * 1000L; i += pulse*2 )
  {
    // Make the pulse: HIGH, wait, LOW, wait:
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(pulse);
  }
  loop_2();
}

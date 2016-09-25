#include <LiquidCrystal.h>

//List of notes
//C4 is middle c
#define C4 262
#define D4 293
#define E4 330
#define F4 349
#define G4 392
#define A4 440
#define B4 494

#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784
#define A5 880
#define B5 988

//Initialize buzzer, button, and LCD pins
const int buzzerPin = 9;
const int buttonPin = 10;
LiquidCrystal lcd(7, 6, 4, 3, 1, 0);

// Length must equal the total number of notes and spaces 
const int songLength = 67;

// 0 represent rests
int notes[] = {D4, A4, A4, 0, E4, B4, F4, C5, C5, 0, E4, B4,
D4, A4, A4, 0, E4, B4, F4, C5, C5, 0, E4, B4,
D4, F4, D5, D4, F4, D5,
E5, F5, E5, F5, E5, C5, A4, 
A4, D4, F4, G4, A4, A4, D4, F4, G4, E4,
D4, F4, D5, D4, F4, D5,
E5, F5, E5, F5, E5, C5, A4, 
A4, D4, F4, G4, A4, 
A4, D4
};

// Beats is an array values for each note and rest.
// A 1 is eighth note, 2 is quarter note, 4 is half note, 8 is whole note
// A 1 represents a quarter-note, 2 a half-note, etc.
// Rests need a length as well.
int beats[] = {2, 2, 2, 1, 1, 4, 2, 2, 2, 1, 1, 4,
2, 2, 2, 1, 1, 4, 2, 2, 2, 1, 1, 4,
1, 1, 4, 1, 1, 4,
3, 1, 1, 1, 1, 1, 4, 2, 2, 1, 1, 6, 
2, 2, 1, 1, 6,
1, 1, 4, 1, 1, 4,
3, 1, 1, 1, 1, 1, 4, 2, 2, 1, 1, 6, 
2, 6
};

// To make the song play faster, decrease this value.
int tempo = 160;


void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  lcd.begin(16,2);
  lcd.print("Song of Storms");
  lcd.setCursor(0,1);
  lcd.print("Legend of Zelda");
}

void loop() 
{
  //Loop through the array
  int i, duration;
  boolean goAgain = true;
  while(goAgain) {
    if (digitalRead(buttonPin) == LOW) {
      goAgain = false;
    }
    delay(100);
  }
  for (i = 0; i < songLength; i++)
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
    //If rest, then pause for specified time
    if (notes[i] == 0)
    {
      delay(duration);
    }
    //Else, play note for specified time
    else
    {
      tone(buzzerPin, notes[i], duration);
      delay(duration);
    }
    //Brief pause between notes
    delay(tempo/10);
  }
}

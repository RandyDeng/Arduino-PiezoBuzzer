#include <LiquidCrystal.h>

//Initialize buzzer, button, and LCD pins
const int buzzerPin = 9;
const int buttonPin = 10;
LiquidCrystal lcd(7, 6, 4, 3, 1, 0);

// Length must equal the total number of notes and spaces 
const int songLength = 88;

// I directly input the frequencies that need to be played
// Alternatively, you could set each frequency to a particular note
// 0 represent rests
int notes[] = {698,880,988,698,880,988,698,880,988,1319,1175,988,1047,988,784,659,587,659,784,659,
698,880,988,698,880,988,698,880,988,1319,1175,988,1047,1319,988,784,988,784,587,659,
587,659,698,784,880,988,1047,988,659,698,784,880,988,1047,1175,1319,1397,1568,
587,659,698,784,880,988,1047,988,659,
784,698,880,784,988,880,1047,988,1175,1047,1319,1175,1397,1319,1319,1397,1175,1319,
0,0,0
};

// Beats is an array values for each note and rest.
// A "1" represents a quarter-note, 2 a half-note, etc.
// Rests need a length as well.
int beats[] = {2,2,4,2,2,4,2,2,2,2,4,2,2,2,2,8,2,2,2,10,
2,2,4,2,2,4,2,2,2,2,4,2,2,2,2,8,2,2,2,10,
2,2,4,2,2,4,2,2,8,2,2,4,2,2,4,2,2,8,
2,2,4,2,2,4,2,2,8,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,6,
4,2,2
};

// To make the song play faster, decrease this value.
int tempo = 120;


void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  lcd.begin(16,2);
  lcd.print("Lost Woods");
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

#include "pitches.h"

const int pin = 8 ;

const int melody[] = {
    NOTE_CS3, NOTE_GS2, NOTE_CS3, NOTE_GS2, NOTE_CS3, NOTE_C3, NOTE_C3
    , NOTE_P
    , NOTE_C3, NOTE_GS2, NOTE_C3, NOTE_GS2, NOTE_C3, NOTE_CS3, NOTE_CS3
    , NOTE_P
    , NOTE_CS3, NOTE_GS2, NOTE_CS3, NOTE_GS2, NOTE_CS3, NOTE_C3, NOTE_C3
    , NOTE_P
    , NOTE_C3, NOTE_GS2, NOTE_C3, NOTE_GS2, NOTE_C3, NOTE_CS3
} ;

const int noteDurations[] = {
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4
} ;


void setup() {
    pinMode(pin, OUTPUT) ;
}

void loop() {
  play() ;
  delay(1000) ;
}

void play() {
    for (int thisNote = 0; thisNote < 30; thisNote++) {
        int noteDuration = 2000 / noteDurations[thisNote] ;
        if (melody[thisNote] == NOTE_P) {
            noTone(pin) ;
            delay(noteDuration) ;
        } else {
            tone(pin, melody[thisNote], noteDuration) ;
        }
    
        int pauseBetweenNotes = noteDuration * 1.30 ;
        delay(pauseBetweenNotes) ;

        noTone(pin) ;
    }
}


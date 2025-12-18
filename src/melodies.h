#ifndef MELODIES_H
#define MELODIES_H

#include <Arduino.h>
#include "notes.h"

//Types
struct Note {
  uint16_t pitch;
  uint16_t duration;
};

struct Melody {
  const Note *notes;
  uint8_t length;
};

//Initial test melody chime, can be removed later.
const Note melodyDoor[] = {
  {NOTE_G4, 150},
  {NOTE_REST, 50},
  {NOTE_A4, 150},
  {NOTE_REST, 50},
  {NOTE_C5, 300},
};

const Melody MELODY_DOOR = {
  melodyDoor,
  sizeof(melodyDoor) / sizeof(Note)
};

//Toreador
const Note melodyToreador[] = {
  {NOTE_G4, 400}, {NOTE_REST, 80},
  {NOTE_G4, 200}, {NOTE_REST, 40},
  {NOTE_G4, 200}, {NOTE_REST, 40},
  {NOTE_E4, 400}, {NOTE_REST, 100},

  {NOTE_G4, 400}, {NOTE_REST, 80},
  {NOTE_A4, 200}, {NOTE_REST, 40},
  {NOTE_G4, 200}, {NOTE_REST, 40},
  {NOTE_E4, 500}, {NOTE_REST, 150},

  {NOTE_C4, 400}, {NOTE_REST, 80},
  {NOTE_E4, 200}, {NOTE_REST, 40},
  {NOTE_G4, 400}, {NOTE_REST, 80},
  {NOTE_A4, 400}, {NOTE_REST, 100},

  {NOTE_G4, 400}, {NOTE_REST, 80},
  {NOTE_E4, 200}, {NOTE_REST, 40},
  {NOTE_C4, 600}, {NOTE_REST, 250},

  {NOTE_E4, 250}, {NOTE_REST, 50},
  {NOTE_G4, 250}, {NOTE_REST, 50},
  {NOTE_A4, 400}, {NOTE_REST, 100},
  {NOTE_G4, 600}, {NOTE_REST, 400}
};

const Melody MELODY_TOREADOR = {
  melodyToreador,
  sizeof(melodyToreador) / sizeof(Note)
};

//Spiderman theme
const Note melodySpiderMan[] = {
  {NOTE_E4, 200}, {NOTE_REST, 40},
  {NOTE_G4, 200}, {NOTE_REST, 40},
  {NOTE_A4, 400}, {NOTE_REST, 80},

  {NOTE_G4, 200}, {NOTE_REST, 40},
  {NOTE_E4, 200}, {NOTE_REST, 40},
  {NOTE_D4, 500}, {NOTE_REST, 150},

  {NOTE_E4, 200}, {NOTE_REST, 40},
  {NOTE_G4, 200}, {NOTE_REST, 40},
  {NOTE_A4, 200}, {NOTE_REST, 40},
  {NOTE_B4, 300}, {NOTE_REST, 60},

  {NOTE_A4, 200}, {NOTE_REST, 40},
  {NOTE_G4, 200}, {NOTE_REST, 40},
  {NOTE_E4, 500}, {NOTE_REST, 200},

  {NOTE_A4, 250}, {NOTE_REST, 60},
  {NOTE_C5, 250}, {NOTE_REST, 60},
  {NOTE_B4, 400}, {NOTE_REST, 80},

  {NOTE_A4, 200}, {NOTE_REST, 40},
  {NOTE_G4, 200}, {NOTE_REST, 40},
  {NOTE_E4, 500}, {NOTE_REST, 200},

  {NOTE_G4, 200}, {NOTE_REST, 40},
  {NOTE_A4, 200}, {NOTE_REST, 40},
  {NOTE_B4, 250}, {NOTE_REST, 60},
  {NOTE_C5, 250}, {NOTE_REST, 60},

  {NOTE_B4, 250}, {NOTE_REST, 60},
  {NOTE_A4, 250}, {NOTE_REST, 60},
  {NOTE_G4, 600}, {NOTE_REST, 400}
};

const Melody MELODY_SPIDERMAN {
  melodySpiderMan,
  sizeof(melodySpiderMan) / sizeof(Note)
};

//Tetris
const Note melodyTetris[] = {
  {NOTE_E5, 400}, {NOTE_B4, 200}, {NOTE_C5, 200},
  {NOTE_D5, 400}, {NOTE_C5, 200}, {NOTE_B4, 200},
  {NOTE_A4, 400}, {NOTE_A4, 200}, {NOTE_C5, 200},
  {NOTE_E5, 400}, {NOTE_D5, 200}, {NOTE_C5, 200},
  {NOTE_B4, 400}, {NOTE_C5, 200}, {NOTE_D5, 400},
  {NOTE_E5, 400}, {NOTE_C5, 400}, {NOTE_A4, 400},
  {NOTE_A4, 400},
};

const Melody MELODY_TETRIS = {
  melodyTetris,
  sizeof(melodyTetris) / sizeof(Note)
};

//Jingle Bells
const Note melodyJingleBells[] {
  {NOTE_E4, 250}, {NOTE_E4, 250}, {NOTE_E4, 500},
  {NOTE_REST, 50},
  {NOTE_E4, 250}, {NOTE_E4, 250}, {NOTE_E4, 500},
  {NOTE_REST, 50},
  {NOTE_E4, 250}, {NOTE_G4, 250}, {NOTE_C4, 250}, {NOTE_D4, 250}, {NOTE_E4, 1000},
  {NOTE_REST, 50},
    
  {NOTE_F4, 250}, {NOTE_F4, 250}, {NOTE_F4, 250}, {NOTE_F4, 250},
  {NOTE_F4, 250}, {NOTE_E4, 250}, {NOTE_E4, 250}, {NOTE_E4, 250}, {NOTE_E4, 250},
  {NOTE_E4, 250}, {NOTE_D4, 250}, {NOTE_D4, 250}, {NOTE_E4, 250}, {NOTE_D4, 500}, {NOTE_G4, 500},
};

const Melody MELODY_JINGLE_BELLS = {
  melodyJingleBells,
  sizeof(melodyJingleBells) / sizeof(Note)
};

//Fur Elise
const Note melodyFurElise[]{
  {NOTE_E5, 250}, {NOTE_DS5, 250}, {NOTE_E5, 250}, {NOTE_DS5, 250},
  {NOTE_E5, 250}, {NOTE_B4, 250}, {NOTE_D5, 250}, {NOTE_C5, 250},
  {NOTE_A4, 500}, {NOTE_REST, 100},
    
  {NOTE_C4, 250}, {NOTE_E4, 250}, {NOTE_A4, 250}, {NOTE_B4, 250},
  {NOTE_REST, 100},
  {NOTE_E4, 250}, {NOTE_GS4, 250}, {NOTE_B4, 250}, {NOTE_C5, 250},
  {NOTE_REST, 100},
    
  {NOTE_E5, 250}, {NOTE_DS5, 250}, {NOTE_E5, 250}, {NOTE_DS5, 250},
  {NOTE_E5, 250}, {NOTE_B4, 250}, {NOTE_D5, 250}, {NOTE_C5, 250},
  {NOTE_A4, 500}
};

const Melody MELODY_FUR_ELISE = {
  melodyFurElise,
  sizeof(melodyFurElise) / sizeof(Note)
};

//Beethoven No. 5
const Note melodyBeethoven[] = {
  {NOTE_G4, 250}, {NOTE_G4, 250}, {NOTE_G4, 250}, {NOTE_E4, 250},
  {NOTE_FS4, 250}, {NOTE_FS4, 250}, {NOTE_FS4, 250}, {NOTE_D4, 750},

  {NOTE_G4, 250}, {NOTE_G4, 250}, {NOTE_G4, 250}, {NOTE_E4, 750},
  {NOTE_FS4, 250}, {NOTE_FS4, 250}, {NOTE_FS4, 250}, {NOTE_D4, 750},

  {NOTE_E4, 250}, {NOTE_E4, 250}, {NOTE_F4, 250}, {NOTE_G4, 250},
  {NOTE_G4, 250}, {NOTE_F4, 250}, {NOTE_E4, 250}, {NOTE_D4, 250},
  {NOTE_REST, 100},

  {NOTE_G4, 250}, {NOTE_G4, 250}, {NOTE_G4, 250}, {NOTE_E4, 750},
  {NOTE_FS4, 250}, {NOTE_FS4, 250}, {NOTE_FS4, 250}, {NOTE_D4, 750},

};

const Melody MELODY_BEETHOVEN = {
  melodyBeethoven,
  sizeof(melodyBeethoven) / sizeof(Note)
};

const Note melodyRondaTurca[] = {
  {NOTE_E4, 125}, {NOTE_E4, 125}, {NOTE_E4, 125}, {NOTE_FS4, 125},
  {NOTE_G4, 125}, {NOTE_FS4, 125}, {NOTE_E4, 125}, {NOTE_D4, 125},
  {NOTE_C4, 125}, {NOTE_D4, 125}, {NOTE_E4, 125}, {NOTE_C4, 125},
  {NOTE_A3, 250}, {NOTE_REST, 50},

  {NOTE_A3, 125}, {NOTE_C4, 125}, {NOTE_E4, 125}, {NOTE_A4, 125},
  {NOTE_G4, 125}, {NOTE_E4, 125}, {NOTE_C4, 125}, {NOTE_A3, 125},
  {NOTE_REST, 50},

  {NOTE_E4, 125}, {NOTE_E4, 125}, {NOTE_E4, 125}, {NOTE_FS4, 125},
  {NOTE_G4, 125}, {NOTE_FS4, 125}, {NOTE_E4, 125}, {NOTE_D4, 125},
  {NOTE_C4, 125}, {NOTE_D4, 125}, {NOTE_E4, 125}, {NOTE_C4, 125},
  {NOTE_A3, 250}
};

const Melody MELODY_RONDA {
  melodyRondaTurca,
  sizeof(melodyRondaTurca) / sizeof(Note)
};

//Siren
const Note melodySiren[] = {
  {NOTE_C5, 200},
  {NOTE_G4, 200},
};

const Melody MELODY_SIREN = {
  melodySiren,
  sizeof(melodySiren) / sizeof(Note)
};

#endif

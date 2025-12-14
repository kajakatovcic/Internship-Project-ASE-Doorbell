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

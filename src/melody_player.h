#ifndef MELODY_PLAYER_H
#define MELODY_PLAYER_H

#include <Arduino.h>
#include "pin_definitions.h"
#include "melodies.h"

static const Melody *currentMelody = nullptr;
static uint8_t melodyIndex = 0;
static unsigned long noteStartTime = 0;
static bool melodyActive = false;
static bool melodyFinished = false; 

inline void playMelodyOnce(const Melody &melody) {
  currentMelody = &melody;
  melodyIndex = 0;
  noteStartTime = millis();
  melodyActive = true;
  melodyFinished = false;

  uint16_t pitch = melody.notes[0].pitch;
  if (pitch == NOTE_REST) noTone(BUZZER_PWM);
  else tone(BUZZER_PWM, pitch);
}

inline void playMelodyLoop(const Melody &melody) {
  currentMelody = &melody;
  melodyIndex = 0;
  noteStartTime = millis(); 
  melodyActive = true;
  melodyFinished = false;

  uint16_t pitch = melody.notes[0].pitch;
  if (pitch == NOTE_REST) noTone(BUZZER_PWM);
  else tone(BUZZER_PWM, pitch);
}

inline void stopMelody() {
  noTone(BUZZER_PWM);
  melodyActive = false;
  melodyFinished = true;
}

inline void updateMelody() {
  if (!melodyActive || !currentMelody) return;

  if (millis() - noteStartTime >= currentMelody->notes[melodyIndex].duration) {
    melodyIndex++;
    noteStartTime = millis();

    if (melodyIndex >= currentMelody->length) {
      if (currentMelody == &MELODY_SIREN) {
        melodyIndex = 0; //siren loops forever until reset
      } else {
        melodyActive = false;
        melodyFinished = true;
        noTone(BUZZER_PWM);
        return;
      }
    }

    uint16_t pitch = currentMelody->notes[melodyIndex].pitch;
    if (pitch == NOTE_REST) noTone(BUZZER_PWM);
    else tone(BUZZER_PWM, pitch);
  }
}

inline bool isMelodyFinished() {
  return melodyFinished;
}

#endif

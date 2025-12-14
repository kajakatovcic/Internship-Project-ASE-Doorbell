#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include <Arduino.h>

struct DebouncedInput {
  uint8_t pin;
  bool stableState;
  bool lastReading;
  unsigned long lastChangeTime;
};

inline void initDebounce(DebouncedInput &in, uint8_t pin) {
  in.pin = pin;
  in.stableState = digitalRead(pin);
  in.lastReading = in.stableState;
  in.lastChangeTime = millis();
}

inline void updateDebounce(DebouncedInput &in, unsigned long debounceMs = 30) {
  bool reading = digitalRead(in.pin);

  if (reading != in.lastReading) {
    in.lastChangeTime = millis();
  }

  if ((millis() - in.lastChangeTime) > debounceMs) {
    in.stableState = reading;
  }

  in.lastReading = reading;
}

#endif

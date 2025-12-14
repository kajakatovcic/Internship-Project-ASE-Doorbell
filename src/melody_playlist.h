#ifndef MELODY_PLAYLIST_H
#define MELODY_PLAYLIST_H

#include "melodies.h"

//Doorbell playlist (cycle through these)
const Melody *doorPlaylist[] = {
  &MELODY_DOOR,
  &MELODY_TETRIS,
};

const uint8_t DOOR_PLAYLIST_LEN =
  sizeof(doorPlaylist) / sizeof(Melody*);

static uint8_t doorPlaylistIndex = 0;

inline const Melody& getNextDoorMelody() {
  const Melody &m = *doorPlaylist[doorPlaylistIndex];

  doorPlaylistIndex++;
  if (doorPlaylistIndex >= DOOR_PLAYLIST_LEN) {
    doorPlaylistIndex = 0;
  }

  return m;
}

#endif

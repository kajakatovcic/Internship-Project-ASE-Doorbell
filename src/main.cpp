#include <Arduino.h>

#include "pin_definitions.h"
#include "debounce.h"
#include "melody_player.h"
#include "melody_playlist.h"

//Defining States for FSM
enum State {
    STATE_IDLE,
    STATE_DOOR_ALERT,
    STATE_MUTED,
    STATE_SIREN
};

State state = STATE_IDLE;

//Inputs
DebouncedInput door;
DebouncedInput muteBtn;
DebouncedInput sirenBtn;

//Timing 
unsigned long muteStartTime = 0;
const unsigned long MUTE_TIMEOUT_MS = 5UL * 60UL * 1000UL;

unsigned long pauseStartTime = 0;
const unsigned long PAUSE_MS = 3000; // 3 seconds pause between melodies
bool inPause = false;

//Setup
void setup() {
    pinMode(LED_DOOR, OUTPUT);
    pinMode(LED_MUTE, OUTPUT);
    pinMode(LED_SIREN, OUTPUT);
    pinMode(BUZZER_PWM, OUTPUT);

    pinMode(INPUT_DOOR, INPUT_PULLUP);
    pinMode(INPUT_MUTE, INPUT);
    pinMode(INPUT_SIREN, INPUT);

    initDebounce(door, INPUT_DOOR);
    initDebounce(muteBtn, INPUT_MUTE);
    initDebounce(sirenBtn, INPUT_SIREN);

    digitalWrite(LED_DOOR, LOW);
    digitalWrite(LED_MUTE, LOW);
    digitalWrite(LED_SIREN, LOW);

    stopMelody();
}

//Main Loop
void loop() {

    //Updating inputs using debouncer
    updateDebounce(door);
    updateDebounce(muteBtn);
    updateDebounce(sirenBtn);

    //FSM
    switch (state) {

        case STATE_IDLE:
            if (sirenBtn.stableState == HIGH) {
                playMelodyLoop(MELODY_SIREN);
                digitalWrite(LED_SIREN, HIGH);
                state = STATE_SIREN;
                break;
            }
            if (door.stableState == HIGH) {
                playMelodyOnce(getNextDoorMelody());
                digitalWrite(LED_DOOR, HIGH);
                state = STATE_DOOR_ALERT;
            }
            break;

        case STATE_DOOR_ALERT:
            digitalWrite(LED_DOOR, door.stableState);
            updateMelody();

            //Melody finished, 3 second pause between next in queue
            if (isMelodyFinished() && door.stableState) {
                if (!inPause) {
                    //Pause starts
                    inPause = true;
                    pauseStartTime = millis();
                    stopMelody();
                } else if (millis() - pauseStartTime >= PAUSE_MS) {
                    //Pause finished, play next melody
                    inPause = false;
                    playMelodyOnce(getNextDoorMelody());
                }
            }

            if (!door.stableState) {
                stopMelody();
                digitalWrite(LED_DOOR, LOW);
                inPause = false;
                state = STATE_IDLE;
            }

            if (muteBtn.stableState == HIGH) {
                stopMelody();
                digitalWrite(LED_MUTE, HIGH);
                muteStartTime = millis();
                inPause = false;
                state = STATE_MUTED;
            }

            if (sirenBtn.stableState == HIGH) {
                stopMelody();
                playMelodyOnce(MELODY_SIREN);
                digitalWrite(LED_SIREN, HIGH);
                inPause = false;
                state = STATE_SIREN;
            }
            break;

        case STATE_MUTED:
            digitalWrite(LED_DOOR, door.stableState);

            if (!door.stableState) {
                digitalWrite(LED_MUTE, LOW);
                inPause = false;
                state = STATE_IDLE;
            }

            if (millis() - muteStartTime >= MUTE_TIMEOUT_MS && door.stableState) {
                digitalWrite(LED_MUTE, LOW);
                playMelodyOnce(getNextDoorMelody());
                inPause = false;
                state = STATE_DOOR_ALERT;
            }

            if (sirenBtn.stableState == HIGH) {
                digitalWrite(LED_MUTE, LOW);
                playMelodyOnce(MELODY_SIREN);
                digitalWrite(LED_SIREN, HIGH);
                inPause = false;
                state = STATE_SIREN;
            }
            break;

        case STATE_SIREN:
            updateMelody();

            if (sirenBtn.stableState == LOW) {
                stopMelody();
                digitalWrite(LED_SIREN, LOW);
                inPause = false;
                state = door.stableState ? STATE_DOOR_ALERT : STATE_IDLE;
            }
            break;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Function to play a sound
void playSound(int frequency, int duration) {
    Beep(frequency, duration);
}

// Function to handle keyboard events
void handleKeyboardEvent(char key) {
    int frequency = 0;
    int duration = 500; // Default duration for each note

    switch (key) {
        case 'a':
            frequency = 251;  // Frequency of note C
            break;
        case 's':
            frequency = 283;  // Frequency of note D
            break;
        case 'd':
            frequency = 329;  // Frequency of note E
            break;
        case 'f':
            frequency = 349;  // Frequency of note F
            break;
        case 'g':
            frequency = 392;  // Frequency of note G
            break;
        case 'h':
            frequency = 440;  // Frequency of note A
            break;
        case 'j':
            frequency = 493;  // Frequency of note B
            break;
        case 'w':
            frequency = 277;  // Frequency of note C#
            break;
        case 'e':
            frequency = 311;  // Frequency of note D#
            break;
        case 't':
            frequency = 370;  // Frequency of note F#
            break;
        case 'y':
            frequency = 415;  // Frequency of note G#
            break;
        case 'u':
            frequency = 466;  // Frequency of note A#
            break;
        default:
            break;
    }

    if (frequency != 0) {
        playSound(frequency, duration);
    }
}

int main() {
    char key;

    // Infinite loop to continuously handle keyboard events
    while (1) {
        if (kbhit()) {
            key = getch();
            handleKeyboardEvent(key);
        }
    }

    return 0;
}

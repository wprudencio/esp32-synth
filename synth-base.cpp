#include "AudioTools.h"
#include "AudioTools/AudioLibs/MaximilianDSP.h"

// Audio output via I2S
I2SStream out;
Maximilian maximilian(out);

// Button pins
const int buttonPin1 = 12;
const int buttonPin2 = 32;
const int buttonPin3 = 14;

// Button states
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

// Current note index for sequencing
int currentNote = 0;

// Internal clock for timing
maxiClock myClock;

// Filter object
maxiFilter filter;

// Oscillators
maxiOsc osc[4];
maxiOsc oscOne, oscTwo, oscThree, oscFour;

// Frequencies for Fmaj7 chord: F - A - C - E
double freqs_fmaj7[4] = { 174.61, 220.00, 261.63, 329.63 };

// Frequencies for Amaj7 chord: A - C# - E - G#
double freqs_amaj7[4] = { 220.00, 277.18, 329.63, 415.30 };

void setup() {
  Serial.begin(115200);

  // Configure button inputs
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  // Configure clock: 4 ticks per beat, 120 BPM
  myClock.setTicksPerBeat(4);
  myClock.setTempo(120);

  // Audio output configuration
  auto cfg = out.defaultConfig(TX_MODE);
  cfg.is_master = true;  // ESP32 generates the clock
  cfg.pin_bck = 26;      // Bit Clock (BCK)
  cfg.pin_ws = 25;       // Word Select / LRCK
  cfg.pin_data = 27;     // Data pin
  cfg.sample_rate = 32000;
  cfg.buffer_size = 256;

  out.begin(cfg);
  maximilian.begin(cfg);
}

void play(float *output) {
  myClock.ticker();  // Advance clock

  if (myClock.tick) {
    currentNote = (currentNote + 1) % 4;  // Cycle through notes 0–3
  }

  if (buttonState1 == LOW) {
    // Play Fmaj7 sequence using saw waves
    double note = osc[currentNote].sawn(freqs_fmaj7[currentNote]);
    double filtered = filter.lores(note, 1000, 0.8);  // Low-pass filter
    output[0] = filtered * 0.3;
    output[1] = output[0];
    return;
  }

  if (buttonState2 == LOW) {
    // Play Amaj7 sequence using saw waves
    double note = osc[currentNote].sawn(freqs_amaj7[currentNote]);
    double filtered = filter.lores(note, 1000, 0.8);
    output[0] = filtered * 0.3;
    output[1] = output[0];
    return;
  }

  if (buttonState3 == LOW) {
    // Play full Amaj7 chord using individual oscillators
    double chord = (
      oscOne.sawn(220.00) +     // A
      oscTwo.sawn(277.18) +     // C#
      oscThree.sawn(329.63) +     // E
      oscFour.sawn(415.30)       // G#
    ) / 4.0;

    double filtered = filter.lores(chord, 1000, 0.8);
    output[0] = filtered * 0.3;
    output[1] = output[0];
    return;
  }
}

void loop() {
  maximilian.copy();  // Call the audio processing callback

  // Read the button states
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
}

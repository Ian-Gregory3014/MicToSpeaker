#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputAnalog         adc1;           //xy=191,217
AudioEffectWaveshaper    waveshape1;     //xy=479,215
AudioOutputMQS           mqs1;           //xy=792,215
AudioConnection          patchCord1(adc1, waveshape1);
AudioConnection          patchCord2(waveshape1, 0, mqs1, 0);
AudioConnection          patchCord3(waveshape1, 0, mqs1, 1);
// GUItool: end automatically generated code
// Waveshaper table (simple distortion curve)
#define NUM_STEPS 8
float waveTable[256];

void setup() {
  pinMode(16, INPUT);
  // Fill a simple waveshaper curve (example: hard clipping)
  for (int i = 0; i < 256; i++) {
    float x = (i - 128) / 128.0;   // -1 to 1
    float stepped = round(x * (NUM_STEPS - 1)) / (NUM_STEPS - 1);
    waveTable[i] = stepped;
  }
  waveshape1.shape(waveTable, 256);

  // Start audio engine
  AudioMemory(10);
}

void loop() {
  Serial.println("Hello from Teensy!");
  delay(1000);
  int a2_raw = analogRead(A2);
  
  Serial.println(a2_raw);
}
const int CHANNEL = 0;

bool keys[13];

void setup() {
  for (int key = 0; key < 13; key++) {
    keys[key] = false;
    pinMode(key, INPUT);
  }

  usbMIDI.begin();
}

void loop() {
  for (int key = 0; key < 13; key++)
  {
    if (digitalRead(key) != keys[key]) // key has been pressed or released
    { 
      if (digitalRead(dataPin))
        usbMIDI.sendNoteOn(key + 60, 100, CHANNEL); // 60-key offset starts on C_4
      else
        usbMIDI.sendNoteOff(key + 60, 100, CHANNEL);
      keys[key] = !keys[key]; // Flip in memory
    }
  }
}

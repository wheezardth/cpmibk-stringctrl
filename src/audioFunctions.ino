void initAudio()
{
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.45);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

  // Start playing the file.  This sketch continues to
  // run while the file plays.
  playWav1.play(filename);

  // A brief delay for the library read WAV info
  delay(5);

  while(playWav1.isPlaying()){ /*don't do shit*/ }
}

void playEffect(byte _id)
{
  switch(_id)
  {
    
        case 1:
      playFile("01_ALM.WAV");
    break;

        case 2:
      playFile("08_STR.WAV");
    break;

        case 3:
      playFile("05_VOG.WAV");
    break;

        case 4:
      playFile("02_HRN.WAV");
    break;

        case 5:
      playFile("04_ARF.WAV");
    break;

        case 6:
      playFile("05_VOG.WAV");
    break;

        case 7:
      playFile("05_VOG.WAV");
    break;

        case 8:
      playFile("02_HRN.WAV");
    break;

        case 9:
      playFile("01_ALM.WAV");
    break;

        case 10:
      playFile("08_STR.WAV");
    break;

    default: break;
    }
  }

#include <DmxSimple.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <NewPing.h>
#include <elapsedMillis.h>

// #include <audioFunctions.h>
// #include <groupFunctions.h>
// #include <pulseFunctions.h>
// #include <scanningFunctions.h>

AudioPlaySdWav           playWav1;
AudioOutputI2S           audioOutput;
AudioConnection          patchCord1(playWav1, 0, audioOutput, 0);
AudioConnection          patchCord2(playWav1, 1, audioOutput, 1);
AudioControlSGTL5000     sgtl5000_1;

// Use these with the audio adaptor board
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

#define TX_A 0
#define TX_B 1
#define TX_C 2
#define enaTXA 4
#define enaTXB 21

#define sonicTX 17


#define RX_A 30
#define RX_B 31
#define RX_C 32
#define enaRXA 33
#define enaRXB 20

#define sonicRX 16


  int maxOut = 255;
  int animSpeed = 1000;
  unsigned long lastRefreshTime = 0;
  unsigned long animStartTime = 0;
  long refreshMillis = 1000/50;
  int numLeds = 38;

  byte values[] =
  {
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
  };

  byte channels[] =
  {
    1,2,3,4,5,6,7,8,9,10,
    11,12,13,14,15,16,17,18,19,20,
    21,22,23,24,25,26,27,28,29,30,
    31,32,33,34,35,36,37,38
  };

elapsedMillis reportTimeout;
elapsedMillis scanTimeout;

int maxRange = 150;
int minRange = 50;

NewPing sonar(sonicTX, sonicRX, maxRange);

unsigned int scanDelay = 50;
byte currentSensor = 0;
int currentReadout[11] = {};
byte closestDetection = 0;

void setup()
{
  Serial.begin(115200);

initPins();
initAudio();

  DmxSimple.usePin(3);
  DmxSimple.maxChannel(40);
  currentSensor = 0;
  setAnimation();
}


void loop(){

  Serial.print(".");
  lineScan();
  reportSensors();

  if(!checkPresence())
  {
    runPulse();
    if(!playWav1.isPlaying()){playWav1.play("00_IDL.WAV");}
  }else
  {
    for(int _goHell = 64; _goHell < 255; _goHell++){ setAll(_goHell); delayMicroseconds(2500); }
    blank();
    playWav1.stop();
    Serial.print("Someone at sensor ");
    closestDetection = identifyClosest();
    Serial.println(closestDetection); delay(1500);
    //activateGroup(closestDetection);
    Serial.println("Done!");
    lineScanBlocking();
    currentReadout[0] = maxRange;
  }
}


void reportSensors(){
  if(reportTimeout >= 500){
  for(byte i=0; i<=11; i++){
  if(currentReadout[i] < 10){Serial.print("00");}
  if(currentReadout[i] >= 10 && currentReadout[i] < 100){Serial.print("0");}
  Serial.print(currentReadout[i]); Serial.print("|");}
  reportTimeout = 0; Serial.println();
  }
}

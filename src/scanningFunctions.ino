void initPins()
{
  pinMode(TX_A, OUTPUT);
  pinMode(TX_B, OUTPUT);
  pinMode(TX_C, OUTPUT);
  pinMode(enaTXA, OUTPUT);
  pinMode(enaTXB, OUTPUT);
  //  pinMode(sonicTX, OUTPUT);

  pinMode(RX_A, OUTPUT);
  pinMode(RX_B, OUTPUT);
  pinMode(RX_C, OUTPUT);
  pinMode(enaRXA, OUTPUT);
  pinMode(enaRXB, OUTPUT);
  //  pinMode(sonicRX, INPUT);
}

void reportValues()
{
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int channelSelection = Serial.parseInt();

    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n'){
      for(byte i=1; i<=10; i++){
        if(currentReadout[i] < 10){Serial.print("00");}
        if(currentReadout[i] >= 10 && currentReadout[i] < 100){Serial.print("0");}
        Serial.print(currentReadout[i]); Serial.print("|");
        }
      Serial.println();
    }
  }
}

void chSel(byte channel)
{ // from B4-B8
  switch (channel)
  {
    case 1:
      digitalWriteFast(enaRXA, LOW);
      digitalWriteFast(enaRXB, HIGH);

      digitalWriteFast(RX_A, HIGH);
      digitalWriteFast(RX_B, HIGH);
      digitalWriteFast(RX_C, LOW);
      //////
      digitalWriteFast(enaTXA, LOW);
      digitalWriteFast(enaTXB, HIGH);

      digitalWriteFast(TX_A, HIGH);
      digitalWriteFast(TX_B, HIGH);
      digitalWriteFast(TX_C, LOW);
      //Serial.print("CHSEL: 01 | D3A");
      break;

    case 2:
      digitalWriteFast(enaRXA, LOW);
      digitalWriteFast(enaRXB, HIGH);

      digitalWriteFast(RX_A, LOW);
      digitalWriteFast(RX_B, LOW);
      digitalWriteFast(RX_C, HIGH);
      //////
      digitalWriteFast(enaTXA, LOW);
      digitalWriteFast(enaTXB, HIGH);

      digitalWriteFast(TX_A, LOW);
      digitalWriteFast(TX_B, LOW);
      digitalWriteFast(TX_C, HIGH);
      //Serial.print("CHSEL: 02 | D4A");
      break;

    case 3:
      digitalWriteFast(enaRXA, LOW);
      digitalWriteFast(enaRXB, HIGH);

      digitalWriteFast(RX_A, HIGH);
      digitalWriteFast(RX_B, LOW);
      digitalWriteFast(RX_C, HIGH);
      //////
      digitalWriteFast(enaTXA, LOW);
      digitalWriteFast(enaTXB, HIGH);

      digitalWriteFast(TX_A, HIGH);
      digitalWriteFast(TX_B, LOW);
      digitalWriteFast(TX_C, HIGH);
      //Serial.print("CHSEL: 03 | D5A");
      break;

    case 4:
      digitalWriteFast(enaRXA, LOW);
      digitalWriteFast(enaRXB, HIGH);

      digitalWriteFast(RX_A, LOW);
      digitalWriteFast(RX_B, HIGH);
      digitalWriteFast(RX_C, HIGH);
      //////
      digitalWriteFast(enaTXA, LOW);
      digitalWriteFast(enaTXB, HIGH);

      digitalWriteFast(TX_A, LOW);
      digitalWriteFast(TX_B, HIGH);
      digitalWriteFast(TX_C, HIGH);
      //Serial.print("CHSEL: 04 | D6A");
      break;

    case 5:
      digitalWriteFast(enaRXA, LOW);
      digitalWriteFast(enaRXB, HIGH);

      digitalWriteFast(RX_A, HIGH);
      digitalWriteFast(RX_B, HIGH);
      digitalWriteFast(RX_C, HIGH);
      //////
      digitalWriteFast(enaTXA, LOW);
      digitalWriteFast(enaTXB, HIGH);

      digitalWriteFast(TX_A, HIGH);
      digitalWriteFast(TX_B, HIGH);
      digitalWriteFast(TX_C, HIGH);
      //Serial.print("CHSEL: 05 | D7A");
      break;


    //////////////////////////////////////////

    case 6:
      digitalWriteFast(enaRXA, HIGH);
      digitalWriteFast(enaRXB, LOW);

      digitalWriteFast(RX_A, LOW);
      digitalWriteFast(RX_B, LOW);
      digitalWriteFast(RX_C, LOW);
      //////
      digitalWriteFast(enaTXA, HIGH);
      digitalWriteFast(enaTXB, LOW);

      digitalWriteFast(TX_A, LOW);
      digitalWriteFast(TX_B, LOW);
      digitalWriteFast(TX_C, LOW);
      //      Serial.print("CHSEL: 06 | D0B");
      break;

    case 7:
      digitalWriteFast(enaRXA, HIGH);
      digitalWriteFast(enaRXB, LOW);

      digitalWriteFast(RX_A, HIGH);
      digitalWriteFast(RX_B, LOW);
      digitalWriteFast(RX_C, LOW);
      //////
      digitalWriteFast(enaTXA, HIGH);
      digitalWriteFast(enaTXB, LOW);

      digitalWriteFast(TX_A, HIGH);
      digitalWriteFast(TX_B, LOW);
      digitalWriteFast(TX_C, LOW);
      //      Serial.print("CHSEL: 07 | D1B");
      break;

    case 8:
      digitalWriteFast(enaRXA, HIGH);
      digitalWriteFast(enaRXB, LOW);

      digitalWriteFast(RX_A, LOW);
      digitalWriteFast(RX_B, HIGH);
      digitalWriteFast(RX_C, LOW);
      //////
      digitalWriteFast(enaTXA, HIGH);
      digitalWriteFast(enaTXB, LOW);

      digitalWriteFast(TX_A, LOW);
      digitalWriteFast(TX_B, HIGH);
      digitalWriteFast(TX_C, LOW);
      //      Serial.print("CHSEL: 08 | D2B");
      break;

    case 9:
      digitalWriteFast(enaRXA, HIGH);
      digitalWriteFast(enaRXB, LOW);

      digitalWriteFast(RX_A, HIGH);
      digitalWriteFast(RX_B, HIGH);
      digitalWriteFast(RX_C, LOW);
      //////
      digitalWriteFast(enaTXA, HIGH);
      digitalWriteFast(enaTXB, LOW);

      digitalWriteFast(TX_A, HIGH);
      digitalWriteFast(TX_B, HIGH);
      digitalWriteFast(TX_C, LOW);
      //      Serial.print("CHSEL: 09 | D3B");
      break;

    case 10:
      digitalWriteFast(enaRXA, HIGH);
      digitalWriteFast(enaRXB, LOW);

      digitalWriteFast(RX_A, LOW);
      digitalWriteFast(RX_B, LOW);
      digitalWriteFast(RX_C, HIGH);
      //////
      digitalWriteFast(enaTXA, HIGH);
      digitalWriteFast(enaTXB, LOW);

      digitalWriteFast(TX_A, LOW);
      digitalWriteFast(TX_B, LOW);
      digitalWriteFast(TX_C, HIGH);
      //      Serial.print("CHSEL: 10 | D4B");

      break;

      default:
        Serial.println();
      break;
  }
}


void lineScan()
{
  if (scanTimeout >= scanDelay && currentSensor <= 10)
  {
    chSel(currentSensor); delay(1);
    currentReadout[currentSensor] = sonar.ping_cm();
    currentSensor++;
    scanTimeout = 0;
  }
  if(currentSensor >= 10){currentSensor = 1;}
}


void lineScanBlocking()
{
  for(byte sensor = 1; sensor < 11; sensor++)
  {
    chSel(sensor); delay(1);
    currentReadout[sensor] = sonar.ping_cm();
   }
}


byte identifyClosest(){
  for (byte i = 1; i < 11; i++)
  {
    if (currentReadout[0] > currentReadout[i])
        currentReadout[0] = currentReadout[i];
  }

  for (byte i = 1; i < 11; i++)
  {
    if (currentReadout[i] == currentReadout[0]) {return i;}
  }
}
/*
boolean checkPresence(){
byte thresholdNear = minRange;  //eg. 20
if(
    currentReadout[1] < thresholdNear &&
    currentReadout[2] < thresholdNear &&
    currentReadout[3] < thresholdNear &&
    currentReadout[4] < thresholdNear &&
    currentReadout[5] < thresholdNear &&
    currentReadout[6] < thresholdNear &&
    currentReadout[7] < thresholdNear &&
    currentReadout[8] < thresholdNear &&
    currentReadout[9] < thresholdNear &&
    currentReadout[10] < thresholdNear
   ){return 0;}else{return 1;}
}
*/
boolean checkPresence()
  { byte checksum = 0;
    if(currentReadout[1] > minRange){checksum++;}
    if(currentReadout[2] > minRange){checksum++;}
    if(currentReadout[3] > minRange){checksum++;}
    if(currentReadout[4] > minRange){checksum++;}
    if(currentReadout[5] > minRange){checksum++;}
    if(currentReadout[6] > minRange){checksum++;}
    if(currentReadout[7] > minRange){checksum++;}
    if(currentReadout[8] > minRange){checksum++;}
    if(currentReadout[9] > minRange){checksum++;}
    if(currentReadout[10] > minRange){checksum++;}
    //Serial.print("Checksum = ");
    Serial.print(checksum);
    if(checksum != 0){return 1;} else {return 0;}
  }

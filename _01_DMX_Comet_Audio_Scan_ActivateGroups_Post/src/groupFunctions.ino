/*
 * void activateGroup(byte sensorID){
  Serial.println(sensorID);

  switch(sensorID){
    case 1:
    playWav1.stop();
    playWav1.play("01_ALM.WAV");
    delay(5);
    for(
    break;

    default:
    break;
    }
}

*/

void activateGroup(byte sensorID){
Serial.print("Activating group "); Serial.println(sensorID);
for(int _bri = 255; _bri > 0; _bri--){ dimGroup(sensorID, _bri); delay(4); }
playEffect(sensorID);
for(int _bri = 0; _bri < 255; _bri++){ dimGroup(sensorID, _bri); delay(4); }
}


void dimGroup(byte group, byte _brightness){
int _briNeigh = _brightness; // map(_brightness, 0, 255, 127, 255);
  switch(group){
    case 1:
          DmxSimple.write(1, _briNeigh);
          DmxSimple.write(2, _brightness);
          DmxSimple.write(3, _brightness);
          DmxSimple.write(4, _briNeigh);
    break;

        case 2:
          DmxSimple.write(5, _briNeigh);
          DmxSimple.write(6, _brightness);
          DmxSimple.write(7, _brightness);
          DmxSimple.write(8, _briNeigh);
    break;

        case 3:
          DmxSimple.write(9, _briNeigh);
          DmxSimple.write(10, _brightness);
          DmxSimple.write(11, _brightness);
          DmxSimple.write(12, _briNeigh);
    break;

        case 4:
          DmxSimple.write(13, _briNeigh);
          DmxSimple.write(14, _brightness);
          DmxSimple.write(15, _brightness);
          DmxSimple.write(16, _briNeigh);
    break;

        case 5:
          DmxSimple.write(17, _briNeigh);
          DmxSimple.write(18, _brightness);
          DmxSimple.write(19, _brightness);
          DmxSimple.write(20, _briNeigh);
    break;

        case 6:
          DmxSimple.write(21, _briNeigh);
          DmxSimple.write(22, _brightness);
          DmxSimple.write(23, _brightness);
          DmxSimple.write(24, _briNeigh);
    break;

        case 7:
          DmxSimple.write(25, _briNeigh);
          DmxSimple.write(26, _brightness);
          DmxSimple.write(27, _brightness);
          DmxSimple.write(28, _briNeigh);
    break;

        case 8:
          DmxSimple.write(29, _briNeigh);
          DmxSimple.write(30, _brightness);
          DmxSimple.write(31, _brightness);
          DmxSimple.write(32, _briNeigh);
    break;

        case 9:
          DmxSimple.write(33, _briNeigh);
          DmxSimple.write(34, _brightness);
          DmxSimple.write(35, _brightness);
          DmxSimple.write(36, _briNeigh);
    break;

        case 10:
          DmxSimple.write(37, _briNeigh);
          DmxSimple.write(38, _brightness);
    break;
        
        default:
    break;
  }
}

void blank(){for(byte i=0; i<=38; i++){DmxSimple.write(i, 255);}}

void setAll(int _bri){for(byte i=0; i<=38; i++){DmxSimple.write(i, _bri);}}

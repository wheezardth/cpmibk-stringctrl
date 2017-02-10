import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sensor_emulator extends PApplet {

/* @Desc: Accepts "SETDATA=x:y" Strings via Serial from Arduino and draws
 *
 * DONT EAT YELLOW SNOW
 *
 */



//globs
Serial myPort;

public void setup() {
  
  //Connect Arduino
  //println(Serial.list()); //List ports
  String portname = "COM3"; //TODO: enter portname
  myPort = new Serial(this, portname, 115200); //TODO: Baudrate
  background(0);
  colorMode(HSB,255);
   drawLightsInit(); //Draw all Lights
}

public void draw()
{
   pollData(); //Read Data from Arduino serial Port and update Graphics
}

public void pollData() {
  try
  {
    while (myPort.available() > 0) {
      String inBuffer = myPort.readStringUntil('\n');
      if (inBuffer != null) {
         //Split String "SETLIGHT x y\n" into int variables and send to updateLights(x,y)
         String[] tokens = splitTokens(inBuffer, " ");
         if(tokens.length == 3 && tokens[0].equals("SETLIGHT")) {
           updateLights(PApplet.parseInt(trim(tokens[1])),PApplet.parseInt(trim(tokens[2]))); //INT conv.
           print("SET=> GROUP: "+ tokens[1] + " BRIGHT: "+tokens[2]);
         }
      }
    }
  } catch(Exception e) {
    println("ATE YELLOW SNOW :F");
    e.printStackTrace();
  }
}

public void updateLights(int id, int _brightness){

int increment = 100;

if(_brightness < 0) //prevent color t-bagging xD
  _brightness = 0;

if(id>=1&&id<=4)
  doRectangle(10,10,_brightness);

else if(id>=5&&id<=8)
  doRectangle(10+1*increment,10,_brightness);

else if(id>=9&&id<=12)
  doRectangle(10+2*increment,10,_brightness);

else if(id>=13&&id<=16)
  doRectangle(10+3*increment,10,_brightness);

else if(id>=17&&id<=20)
  doRectangle(10+4*increment,10,_brightness);

else if(id>=21&&id<=24)
  doRectangle(10+5*increment,10,_brightness);

else if(id>=25&&id<=28)
  doRectangle(10+6*increment,10,_brightness);

else if(id>=29&&id<=32)
  doRectangle(10+7*increment,10,_brightness);

else if(id>=33&&id<=36)
  doRectangle(10+8*increment,10,_brightness);

else if(id>=37&&id<=38)
  doRectangle(10+9*increment,10,_brightness);

return;
}

public void doRectangle(int x, int y, int brightness) {
  fill(brightness);
  //println(brightness);
  rect(x,y,80,780, 10);
}

public void drawLightsInit() {
  for(int i=1;i<=10; i++) {
    updateLights(i, 33);
  }
}
  public void settings() {  size(1000,800); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sensor_emulator" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

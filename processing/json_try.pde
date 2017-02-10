import processing.serial.*;

JSONArray jsonread;
Serial myPort;
int datacount = 0;

//TESTDATA def
int[] testData = { 90, 150, 30, 70, 19, 20, 100 };
String[] testJSONdata = { "100", "400", "200" };

void setup() {
  size(700,300);
  //Connect to the Arduino
  //println(Serial.list()); //List ports
  String portname = "COM3"; //TODO: enter portname
  myPort = new Serial(this, portname, 9600); //TODO: Baudrate
  //myPort.bufferUntil("\n");
}

void draw()
{
   background(255);
   fill(0);
   pullData(); //Read Data from Arduino serial Port
   //drawRectangles(testData); //Draw corresponding rectangles from testarray
   drawRectangles(jsonread); //Draw corresponding rectangles from testJSONdata or serial data
}

void pullData() {
  //init json pull array
  jsonread = new JSONArray();
  //read JSON from serial port
  try
  {
    while (myPort.available() > 0) {
      String inBuffer = myPort.readStringUntil('\n');
      //inBuffer = inBuffer.replace("$","");
      if (inBuffer != null) {
         println(inBuffer);

          JSONObject item = parseJSONObject(inBuffer);
          jsonread.setJSONObject(datacount, item);
          datacount++;
          println(item.toString());
      }
    }
  } catch(Exception e) {
    println("Non_JSON_String_found");
    e.printStackTrace();
  }
}

void drawRectangles(JSONArray lights) {

  for (int i = 0; i < lights.size(); i++) {
    JSONArray jsonarr = new JSONArray();
    JSONObject item = new JSONObject();
    println("JSON pass: "+ lights.toString());
try {
    if(lights.getJSONObject(i) != null) {
       jsonarr = lights.getJSONArray(i);
       item = jsonarr.getJSONObject(i);
       item = lights.getJSONObject(i);
    }
} catch (Exception e) {
  e.printStackTrace();
}
    int id = item.getInt("id");
    int data  = (int)map(item.getInt("data"), 0, 32000, 1, 255); //start1, stop1, start2, stop2
    //println(id + ", " + data); //debug output testdata

    color(data);
    fill(data);
    rect(50+i*50, 10, 25, 280); //draw data colored graphics
  }
}

/**************** CRAP COPY BLOCK ***************

//  json.setInt("id", 0);
//  json.setString("species", "Panthera leo");
//  json.setString("name", "Lion");
//  saveJSONObject(json, "data/new.json");

jsonread = loadJSONArray("");
//byte[] dataArray = json.getByte("bytewise");

for (int i = 0; i < jsonread.size(); i++) {

 JSONObject dataArray = jsonread.getJSONObject(i);

 int id = animal.getInt("id");
 String species = animal.getString("species");
 String name = animal.getString("name");

 println(id + ", " + species + ", " + name);
}

//jsonread = myPort.read(); //one byte.

//pushing daisies

for (int i = 0; i < testJSONdata.length; i++) {

  JSONObject data = new JSONObject();

  data.setInt("id", i);
  data.setString("data", testJSONdata[i]);

  jsonread.setJSONObject(i, data);
}
*/

/* This example will read all channels from the AS7341 and print out reported values */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_AS7341.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeSerif12pt7b.h>
Adafruit_AS7341 as7341;
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void setup() {
  Serial.begin(115200);

  if (!as7341.begin()){
    Serial.println("Could not find AS7341");
    while (1) { delay(10); }
  }

  as7341.setATIME(100);
  as7341.setASTEP(999);
  as7341.setGain(AS7341_GAIN_256X);

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display();
  delay(500); // Pause for half second

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);

}

void loop() {

      byte scale;

  // Read all channels at the same time and store in as7341 object
  if (!as7341.readAllChannels()){
    Serial.println("Error reading all channels!");
    return;
  }
  display.clearDisplay();
  display.setCursor(0,0);


  //scale = as7341.getChannel(AS7341_CHANNEL_415nm_F1)+as7341.getChannel(AS7341_CHANNEL_445nm_F2)+as7341.getChannel(AS7341_CHANNEL_480nm_F3)+as7341.getChannel(AS7341_CHANNEL_515nm_F4)+as7341.getChannel(AS7341_CHANNEL_555nm_F5)+as7341.getChannel(AS7341_CHANNEL_590nm_F6)+as7341.getChannel(AS7341_CHANNEL_630nm_F7)+as7341.getChannel(AS7341_CHANNEL_680nm_F8);
  scale=as7341.getChannel(AS7341_CHANNEL_555nm_F5);
  // Print out the stored values for each channel
  //display.print("415   515    630 NIR");
  //display.fillRect(0,10,5,log10(as7341.getChannel(AS7341_CHANNEL_415nm_F1))*10, SSD1306_WHITE);
 // display.drawRect(5,10,5,log10(as7341.getChannel(AS7341_CHANNEL_445nm_F2))*10, SSD1306_WHITE);
 // display.drawRect(10,10,5,log10(as7341.getChannel(AS7341_CHANNEL_480nm_F3))*10, SSD1306_WHITE);
 // display.drawRect(15,10,5,log10(as7341.getChannel(AS7341_CHANNEL_515nm_F4))*10, SSD1306_WHITE);
 // display.drawRect(20,10,5,log10(as7341.getChannel(AS7341_CHANNEL_555nm_F5))*10, SSD1306_WHITE);
  //display.drawRect(25,10,5,log10(as7341.getChannel(AS7341_CHANNEL_590nm_F6))*10, SSD1306_WHITE);
  //display.drawRect(30,10,5,log10(as7341.getChannel(AS7341_CHANNEL_630nm_F7))*10, SSD1306_WHITE);00
  //display.drawRect(35,10,5,log10(as7341.getChannel(AS7341_CHANNEL_680nm_F8))*10, SSD1306_WHITE);
  //display.drawRect(40,10,5,log10(as7341.getChannel(AS7341_CHANNEL_NIR))*10, SSD1306_WHITE);

 // display.drawRect(40,10,5,log10(as7341.getChannel(AS7341_CHANNEL_NIR))*10, SSD1306_WHITE);

  
  //display.fillTriangle(0,0,(as7341.getChannel(AS7341_CHANNEL_415nm_F1))/6410,4,0,8, SSD1306_WHITE);
  //display.fillTriangle(0,8,(as7341.getChannel(AS7341_CHANNEL_445nm_F2))/64,12,0,16, SSD1306_WHITE);
  //display.fillTriangle(0,16,(as7341.getChannel(AS7341_CHANNEL_480nm_F3))/64,20,0,24, SSD1306_WHITE);
 // display.fillTriangle(0,24,(as7341.getChannel(AS7341_CHANNEL_515nm_F4))/64,28,0,32, SSD1306_WHITE);
  //display.fillTriangle(0,32,(as7341.getChannel(AS7341_CHANNEL_555nm_F5))/64,36,0,40, SSD1306_WHITE);
  //display.fillTriangle(0,40,(as7341.getChannel(AS7341_CHANNEL_590nm_F6))/64,44,0,48, SSD1306_WHITE);
  //display.fillTriangle(0,48,(as7341.getChannel(AS7341_CHANNEL_630nm_F7))/64,52,0,56, SSD1306_WHITE);
  //display.fillTriangle(0,56,(as7341.getChannel(AS7341_CHANNEL_680nm_F8))/64,60,0,64, SSD1306_WHITE);
 // display.drawRect(40,10,5,log10(as7341.getChannel(AS7341_CHANNEL_NIR))*10, SSD1306_WHITE);


  //display.fillRect(0,0,log10(as7341.getChannel(AS7341_CHANNEL_415nm_F1))*8,3, SSD1306_WHITE);
  //display.fillRect(0,4,log10(as7341.getChannel(AS7341_CHANNEL_445nm_F2))*8,3, SSD1306_WHITE);
  //display.fillRect(0,8,log10(as7341.getChannel(AS7341_CHANNEL_480nm_F3))*8,3, SSD1306_WHITE);
 // display.fillRect(0,12,log10(as7341.getChannel(AS7341_CHANNEL_515nm_F4))*8,3, SSD1306_WHITE);
 // display.fillRect(0,16,log10(as7341.getChannel(AS7341_CHANNEL_555nm_F5))*8,3, SSD1306_WHITE);
 // display.fillRect(0,20,log10(as7341.getChannel(AS7341_CHANNEL_590nm_F6))*8, 3,SSD1306_WHITE);
 // display.fillRect(0,24,log10(as7341.getChannel(AS7341_CHANNEL_630nm_F7))*8, 3,SSD1306_WHITE);
 // display.fillRect(0,28,log10(as7341.getChannel(AS7341_CHANNEL_680nm_F8))*8,3, SSD1306_WHITE);
  //display.drawRect(0,32,5,log10(as7341.getChannel(AS7341_CHANNEL_NIR))*10, SSD1306_WHITE);
  //display.fillRect(0,0,as7341.getChannel(AS7341_CHANNEL_415nm_F1)/10,4,SSD1306_WHITE);
  display.fillRect(58,0,(as7341.getChannel(AS7341_CHANNEL_415nm_F1))/500,5, SSD1306_WHITE);
  display.fillRect(58,6,(as7341.getChannel(AS7341_CHANNEL_445nm_F2))/500,5, SSD1306_WHITE);
  display.fillRect(58,12,(as7341.getChannel(AS7341_CHANNEL_480nm_F3))/500,5, SSD1306_WHITE);
  display.fillRect(58,18,(as7341.getChannel(AS7341_CHANNEL_515nm_F4))/500,5, SSD1306_WHITE);
  display.fillRect(58,24,(as7341.getChannel(AS7341_CHANNEL_555nm_F5))/500,5, SSD1306_WHITE);
  display.fillRect(58,30,(as7341.getChannel(AS7341_CHANNEL_590nm_F6))/500, 5,SSD1306_WHITE);
  display.fillRect(58,36,(as7341.getChannel(AS7341_CHANNEL_630nm_F7))/500, 5,SSD1306_WHITE);
  display.fillRect(58,42,(as7341.getChannel(AS7341_CHANNEL_680nm_F8))/500,5, SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("415:");
  display.println(as7341.getChannel(AS7341_CHANNEL_415nm_F1));
  display.setCursor(0,8);
  display.print("445:");
  display.println(as7341.getChannel(AS7341_CHANNEL_445nm_F2));
  display.setCursor(0,16);
  display.print("480:");
  display.println(as7341.getChannel(AS7341_CHANNEL_480nm_F3));
  display.setCursor(0,24);
  display.print("515:");
  display.println(as7341.getChannel(AS7341_CHANNEL_515nm_F4));
  display.setCursor(0,32);
  display.print("555:");
  display.println(as7341.getChannel(AS7341_CHANNEL_555nm_F5));
  display.setCursor(0,40);
  display.print("590:");
  display.println(as7341.getChannel(AS7341_CHANNEL_590nm_F6));
  display.setCursor(0,48);
  display.print("630:");
  display.println(as7341.getChannel(AS7341_CHANNEL_630nm_F7));
  display.setCursor(0,56);
  display.print("680:");
  display.println(as7341.getChannel(AS7341_CHANNEL_680nm_F8));
  display.setCursor(58,48);
  display.print("NIR:");
  display.println(as7341.getChannel(AS7341_CHANNEL_NIR));
  display.setCursor(58,56);
  display.print("Clear:");
  display.println(as7341.getChannel(AS7341_CHANNEL_CLEAR));
  display.display();
  
  Serial.print("Matt:");
  Serial.println((as7341.getChannel(AS7341_CHANNEL_515nm_F4)/scale)*64);





 




  
  Serial.print("415nm : ");
  Serial.print(as7341.getChannel(AS7341_CHANNEL_415nm_F1));
  Serial.println("  Clear");
  Serial.print("445nm : ");
  Serial.print(as7341.getChannel(AS7341_CHANNEL_445nm_F2));
  Serial.print("  ");
  Serial.println(as7341.getChannel(AS7341_CHANNEL_CLEAR));
  Serial.print("480nm : ");
  Serial.println(as7341.getChannel(AS7341_CHANNEL_480nm_F3));
  Serial.print("515nm : ");
  Serial.println(as7341.getChannel(AS7341_CHANNEL_515nm_F4));
  Serial.print("555nm : ");
  Serial.println(as7341.getChannel(AS7341_CHANNEL_555nm_F5));
  Serial.print("590nm : ");
  Serial.print(as7341.getChannel(AS7341_CHANNEL_590nm_F6));
  Serial.println("   NIR");
  Serial.print("630nm : ");
  Serial.print(as7341.getChannel(AS7341_CHANNEL_630nm_F7));
  Serial.print("  ");
  Serial.println(as7341.getChannel(AS7341_CHANNEL_NIR));
  Serial.print("680nm : ");
  Serial.println(as7341.getChannel(AS7341_CHANNEL_680nm_F8));
  Serial.println(scale);
  //Serial.println(as7341.getChannel(AS7341_CHANNEL_415nm_F1));
  display.display();
}

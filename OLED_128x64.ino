#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup()   
{                
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("AJ . Wasan...");
  display.setTextColor(BLACK, WHITE);
  display.setTextSize(1);
  display.println("Arduino Step");
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.println("Apply Physics");
  display.drawCircle(64,48,15,WHITE);
  display.drawTriangle(0,63,64,32,127,63,WHITE);
  display.fillTriangle(50,48,64,33,79,48,WHITE);
  
  display.display();
} 

void loop() {
  
}

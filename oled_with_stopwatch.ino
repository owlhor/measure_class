#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

unsigned long start,finished,elapsed;
int buf = 0;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,0);
  display.println("..TIME..");
  display.display();
  pinMode(2, INPUT_PULLUP); // start
  pinMode(3, INPUT_PULLUP); // stop
}

void displayResult()
{
  float h,m,s,ms;
  unsigned long over;

  elapsed = finished-start;

  buf = 0;

  h = int(elapsed/3600000);
  over = elapsed % 3600000;
  m = int(over/60000);
  over = over % 60000;
  s = int(over / 1000);
  ms = over % 1000;
  Serial.print("Raw elapsed time: ");
  Serial.println(elapsed);
  Serial.print("Elapsed time: ");
  Serial.print(h, 0);
  Serial.print(" h ");
  Serial.print(m, 0);
  Serial.print(" m ");
  Serial.print(s, 0);
  Serial.print(" s ");
  Serial.print(ms, 0);
  Serial.println(" ms ");
  Serial.println();
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,0);
  display.println("..TIME..");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,32);
  display.print(m,0); display.print(":");  display.print(s,0); display.print(":");   display.println(ms,0);
  display.display();
}

void loop() {
  
  if (digitalRead(2)== LOW)
  {
    start = millis();
    delay(200); //debounce
    Serial.println("Started...");
    buf = 1;

    //display.clearDisplay();
    /*display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(15,17);
    display.println("Start Counting.");
    display.display();
  */
  }
  if (digitalRead(3)== LOW)
  {
    finished = millis();
    delay(200); //debounce
    displayResult();
  }

  if (buf == 1){
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(20,0);
    display.println("..TIME..");
    display.setTextSize(1);
    
    display.setTextColor(WHITE);
    display.setCursor(15,17);
    display.println("Start Counting.");
    display.display();
    delay(100);

    //----------------------------------
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(20,0);
    display.println("..TIME..");
  
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(15,17);
    display.println("Start Counting..");
    display.display();
    delay(100);

    //----------------------------------
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(20,0);
    display.println("..TIME..");
    
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(15,17);
    display.println("Start Counting...");
    display.display();
    delay(100);
    }

}

// stop watch

#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SH1106.h"
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);
int a=10,b=2,c=1000; // c = delay(millisec)
char diss;

unsigned long start,finished,elapsed;

void setup() {
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // start
  pinMode(3, INPUT_PULLUP); // stop
}

void displayResult()
{
  float h,m,s,ms;
  unsigned long over;

  elapsed = finished-start;

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

  display.print("Raw elapsed time: ");
  display.println(elapsed);
  display.print("Elapsed time: ");
  display.print(h, 0);
  display.print(" h ");
  display.print(m, 0);
  display.print(" m ");
  display.print(s, 0);
  display.print(" s ");
  display.print(ms, 0);
  display.println(" ms ");
  display.println();
}

void loop() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(a, b);     //  range from left,range from up
  display.println("Timer Stopwatch...");
  
  if (digitalRead(2)== LOW)
  {
    start = millis();
    delay(200); //debounce
    Serial.println("Started...");
    display.print("Started...");
  }
  if (digitalRead(3)== LOW)
  {
    finished = millis();
    delay(200); //debounce
    displayResult();
  }

}

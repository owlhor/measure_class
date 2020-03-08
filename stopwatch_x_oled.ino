// stop watch
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);
//int a=10,b=2,c=1000; // c = delay(millisec)

unsigned long start,finished,elapsed;

void setup() {
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // start
  pinMode(3, INPUT_PULLUP); // stop
  pinMode(7, OUTPUT);

  digitalWrite(7, HIGH) ;

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 2);     //  range from left,range from up
  //display.println("Timer");
  //display.println("Stopwatch...");
  display.display();
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
  /*
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
*/
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 2);     //  range from left,range from up
  display.println("Timer Stopwatch...");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,27);
  display.print(m,0); display.print(":");  display.print(s,0); display.print(":");   display.println(ms,0);
  display.setTextSize(1);
  display.setCursor(45,45);
  display.println(elapsed);
  display.display();

}

void loop() {
  
  
  if (digitalRead(2)== LOW)
  {
    start = millis();
    digitalWrite(7,LOW) ;
    delay(200); //debounce
    Serial.println("Started...");

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(10, 2);     //  range from left,range from up
    display.println("Timer Stopwatch...");
    display.setTextSize(1);
    display.setCursor(25, 12);
    display.print("counting...");
    display.display();

    digitalWrite(7, HIGH) ;
  }
  if (digitalRead(3)== LOW)
  {
    finished = millis();
    delay(200); //debounce
    displayResult();
  }

}

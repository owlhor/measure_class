#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

int a=10,b=5;

float CountPulse;
int Calc, Calc2 ,Calc3;
int hallsensor = 2; //The pin location of the sensor
 
void rpm () //This is the function that the interupt calls 
{
  CountPulse++; //This function measures the rising and falling edge of the hall effect sensors signal;
}

void setup()
{
pinMode(hallsensor, INPUT); //initializes digital pin 2 as an input
Serial.begin(9600); //This is the setup function where the serial port is initialised,
attachInterrupt(0, rpm, RISING); //and the interrupt is attached

display.begin(SH1106_SWITCHCAPVCC, 0x3C);
}

void loop ()
{
CountPulse = 0; //Set NbTops to 0 ready for calculations
sei(); //Enables interrupts
delay (1000); //Wait 1 second
cli(); //Disable interrupts
Calc = (CountPulse * 60 / 5.5); //(Pulse frequency x 60) / 5.5Q, = flow rate in L/hour
Calc2 = (CountPulse ); // 450 = pluse in 1 second/ 1 litre
Calc3 = (CountPulse / 450 * 3600); // 450 = pluse in 1 second/ 1 litre
Serial.print (Calc2, DEC); //Prints the number calculated above
Serial.print ("  Pulse/sec\r\n"); //Prints "L/hour" and returns a new line
Serial.print (Calc3, DEC); //Prints the number calculated above
Serial.print (" L/hour\r\n"); //Prints "L/hour" and returns a new line
Serial.println ("-------------------------");

//displayer();
}

void displayer(){

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(a, b);     //  range from left,range from up

  display.setTextSize(2);
  display.println("Arduin");
  display.setTextSize(1);
  display.println("...OLED 1.3 TESTER...");
//display.println("->->->->->->->->->->-");
  display.display();

  }

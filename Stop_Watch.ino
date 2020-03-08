
void setup()
{
  Serial.begin(9600);
  
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(3, INPUT);
  digitalWrite(3, HIGH);
}
double i = 0;
double a = millis();
double c ;

void loop()
{
  
 if(digitalRead(2) == LOW)
 {
 a = millis();
   while(digitalRead(3) == HIGH)
   {
   
     c = millis();
   i = (c - a) / 1000;
   Serial.println(i);
   delay(100);
   }
   
   if(digitalRead(3) == LOW)
   {
     while(digitalRead(2) == HIGH)
     {
       Serial.println(i);
     }
   }
 }
}

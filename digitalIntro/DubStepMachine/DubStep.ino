void setup()
{
  
 pinMode(9,OUTPUT); 
}

void loop()
{

//Usage:
//tone(SpeakerPin, Frequency, Max Duration in ms);
//delay( milliseconds before next line);
tone(9, 100, 1000);
delay(1000); 
tone(9, 150, 1000);
delay(1000);
  
tone(9, 200, 1000);
delay(1000);
delay(1000);
tone(9, 250, 500);
delay(500);
tone(9, 230, 5000);
delay(5000);

}

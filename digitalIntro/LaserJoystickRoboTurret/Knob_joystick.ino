// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
Servo myservo2;
 
int potpin = A0;
int potpin2 = A1;// analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
int val2; 
 
void setup() 
{ 
  myservo.attach(9);
  myservo2.attach(11);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  val = analogRead(potpin);  // reads the value of the potentiometer (value between 0 and 1023) 
  val2 = analogRead(potpin2);
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  val2 = map(val2, 0, 1023, 0, 179);
  myservo.write(val);   // sets the servo position according to the scaled value 
  myservo2.write(val2);
  delay(15);                           // waits for the servo to get there 
} 

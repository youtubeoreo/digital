/*
  
  Emic 2 Text-to-Speech Module: Basic Demonstration       
                                                         
  Author: Joe Grand [www.grandideastudio.com]             
  Contact: support@parallax.com                            
  
  Program Description:
  
  This program provides a simple demonstration of the Emic 2 Text-to-Speech
  Module. Please refer to the product manual for full details of system 
  functionality and capabilities.

  Revisions:
  
  1.0 (February 13, 2012): Initial release
  
*/

// include the SoftwareSerial library so we can use it to talk to the Emic 2 module
#include <SoftwareSerial.h>

#define rxPin 2    // Serial input (connects to Emic 2 SOUT)
#define txPin 3    // Serial output (connects to Emic 2 SIN)
#define ledPin 13  // Most Arduino boards have an on-board LED on this pin

// set up a new serial port
SoftwareSerial emicSerial =  SoftwareSerial(rxPin, txPin);



// This code is based on a program called "Sweep"
// by BARRAGAN <http://barraganstudio.com> 
// (which is an example placed in the public domain found under the example menu of the Arduino IDE)
// and we also utilize the Servo.h Library

//Creative commons license for my modifications
//
//I created additional functions created for handling continuous-rotation-servos as motors
//Forward, Backward, Stop, Stop, and attachServo
//by Gregory Kielian  < www.kielian.net > 
//Special thanks to Chris Newton for his mentoring and help debugging the first drafts


#include <Servo.h> 
 
Servo LeftWheel;  // create servo object to control a servo 
Servo RightWheel;  // create servo object to control a servo 

// Note: a maximum of eight servo objects can be created 

int LWPin = 9; //set the pin number for your left servo-motors (just change the number if not pin 9)
int RWPin = 10; //right-wheel control pin

 







void setup()  // Set up code called once on start-up
{
  // define pin modes
  LeftWheel.attach( LWPin );  //  Connects LeftWheel to the pin LWPin
  RightWheel.attach( RWPin );  // Connects another wheel to be controlled by the pin RWPin

  pinMode(ledPin, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  
  // set the data rate for the SoftwareSerial port
  emicSerial.begin(9600);

  digitalWrite(ledPin, LOW);  // turn LED off
  
  /*
    When the Emic 2 powers on, it takes about 3 seconds for it to successfully
    intialize. It then sends a ":" character to indicate it's ready to accept
    commands. If the Emic 2 is already initialized, a CR will also cause it
    to send a ":"
  */
  emicSerial.print('\n');             // Send a CR in case the system is already up
  while (emicSerial.read() != ':');   // When the Emic 2 has initialized and is ready, it will send a single ':' character, so wait here until we receive it
  delay(10);                          // Short delay
  emicSerial.flush();                 // Flush the receive buffer
}
a
void loop()  // Main code, to run repeatedly
{
  // Speak some text
  emicSerial.print('S');
  //emicSerial.print("Hello. My name is the Emic 2 Text-to-Speech module. I would like to sing you a song.");  // Send the desired string to convert to speech
  emicSerial.print("I don't know what to say whatever greg.");
  
  emicSerial.print('\n');
  digitalWrite(ledPin, HIGH);         // Turn on LED while Emic is outputting audio
  while (emicSerial.read() != ':');   // Wait here until the Emic 2 responds with a ":" indicating it's ready to accept the next command
  digitalWrite(ledPin, LOW);
    
  delay(500);    // 1/2 second delay
    
         Rotate(30); // rotate at 30% power
     delay(2000); // keep on doing this for 2 seconds or 2000 milliseconds


     Rotate(-30); // Rotate the other way
     delay(1000); // for 1 second


     Forward(100); // Full steam ahead!
     delay(3000); // for 3 seconds


     Backward(50); // 50% power backwards
     delay(500); // for half-a-second

 
     Stop(); // stop the wheels
     delay(4000); // for 4 seconds
  // Sing a song
  emicSerial.print("D3\n");
  digitalWrite(ledPin, HIGH);         // Turn on LED while Emic is outputting audio
  while (emicSerial.read() != ':');   // Wait here until the Emic 2 responds with a ":" indicating it's ready to accept the next command
  digitalWrite(ledPin, LOW);

 
}






void Forward(int speed)
{
    attachServos(); //in case we disconnected them
     
    speed = (int) (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    LeftWheel.write(speed);             
    RightWheel.write(-speed); // Right wheel is backwards    
}



void Backward (int speed)
{
    attachServos(); //in case we disconnected them
     
    speed = (int) (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    LeftWheel.write(-speed);             
    RightWheel.write(speed); // Right wheel is backwards    
}



void Rotate (int speed)
{
    attachServos(); //in case we disconnected them
     
    speed = (int) (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    LeftWheel.write(speed);             
    RightWheel.write(speed); // Right wheel is backwards    
}


void Stop()
{
  LeftWheel.detach();
  RightWheel.detach();
}







void attachServos()
{
   LeftWheel.attach(LWPin);
   RightWheel.attach(RWPin);

}

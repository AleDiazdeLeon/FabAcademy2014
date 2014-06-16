
//SERVO
#include <SoftwareServo.h>
#include <Arduino.h> 
SoftwareServo servo1;
//int time;

//INPUTS
const int buttonPin = 2;     // the number of the SELECTOR 1
//const int buttonPin = 2;     // the number of the SELECTOR 2
//const int buttonPin = 1;     // the number of the SELECTOR 3

//OUTPUTS
//const int ledPin = 8;      // the number of the LED
//int servo1 = 10;   // the number of the servo
//const int speakerPin = 7;      // the number of the speaker

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int pos = 0;    // variable to store the servo position 

 
void setup()
{
  servo1.attach(10);
 pinMode(pos, OUTPUT);
 pinMode(buttonPin, INPUT); 
 digitalWrite (buttonPin, HIGH);
  
}

void loop(){
  // read the state of the pushbutton value:
  int buttonState = 0;

if (digitalRead(buttonPin) == LOW);

  for(pos = 0; pos < 90; pos += 90)  // goes from 0 degrees to 90 degrees 
  {                                  // in steps of  degree 
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
                          // waits 1s for the servo to reach the position 
  }

if (digitalRead(buttonPin) == HIGH)
  
  for(pos = 90; pos>=90; pos-=90)     // goes from 90 degrees to 0 degrees 
  {                                
     servo1.write(pos);              // tell servo to go to position in variable 'pos' 
  delay(50);                             // waits 50ms for the servo to reach the position 
 }
  SoftwareServo::refresh();
  }
 
  




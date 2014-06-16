#include <Boards.h>
#include <Firmata.h>

/* Knock Sensor
 * ----------------
 *
 * Programa que utiliza un piezoeléctrico como si fuese un sensor
 * de golpes
 *
 * Básicamente escuchamos al pin analógico y detectamos
 * si la señal está por encima de un determinado umbral.
 * Escribimos "knock" al puerto serie si el umbral es sobrepasado
 * y encenderá el led del pin 13.
 *
 * (cleft) 2005 D. Cuartielles for K3
 */
/*
This is the code to make a LED blink with the music.
You have to set the threshold so it' sensible enough to make the led blink.
 
You connect an LED to PIN13 and the Sound Sensor to Analog Pin 0
 */
 
int led = 13;
int threshold = 500; //Change This
int volume;
byte val = 0;
int THRESHOLD = 100;
int statePin = LOW;


void setup() {                
  Serial.begin(9600); // For debugging
  pinMode(led, OUTPUT);     
}
 
void loop() {
  
  volume = analogRead(A0); // Reads the value from the Analog PIN A0
  /*
    //Debug mode
    Serial.println(volume);
    delay(100);
  */
  
  if(volume>=threshold){
    digitalWrite(led, HIGH); //Turn ON Led
    Serial.println("Listening!");   //Send word to 
  }  
  else{
    digitalWrite(led, LOW); // Turn OFF Led

  }
   val = analogRead(volume);     
  if (val >= THRESHOLD) {
    statePin = !statePin;
    digitalWrite(led, statePin);
    Serial.println("Listening!");
 
}
}

/**
 *
 *Based on Tickle example. 
 * 
 * The word "tickle" jitters when serial data arrives from serial port
 *
 */
import processing.serial.*;
String portname = "COM12";  
Serial port; 
PFont font;
int micro = 0;
float x = (500); // X-coordinate of text
float y = (350); // Y-coordinate of text

void setup() 
{
  size(1200, 700);
  font = loadFont("Ebrima-48.vlw");
  textFont(font);
  noStroke();
  port = new Serial(this, portname, 57600);
}

void draw() 
{
  fill(247,236,7);
  rect(0, 0, width, height);
  fill(0);

  if (port.available() > 0) {  
    micro = port.read();  
    port.clear();   

    x = x + random(-12, 12) + random(-2,2)*micro/2 ;
    y = y + random(-12, 12) + random(-2,2)*micro/2;

  }
  text("Queen", constrain(x,0,width-30), constrain(y,0,height));
  if (x>width || y > height || y < 0 || x < 0 ){
    x = (500); // X-coordinate of text
    y = (350); // Y-coordinate of text
  }
}
void mousePressed() {

  x = (500); // X-coordinate of text
  y = (350); // Y-coordinate of text
}


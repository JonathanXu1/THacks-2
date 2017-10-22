/*The servo program
 *Moves the servo to a variety of positions
 *Jonathan Xu
 *January 25, 2017
*/

#include<Servo.h>
Servo platform;

void setup() {
  // put your setup code here, to run once:
  platform.attach(10);
  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x=0; x<=180; x+=5) {
    platform.write(x);
    delay(250);
  }
  for (int x=180; x>=0; x-=5) {
    platform.write(x);
    delay(250);
  }
}


/*The servo program
 *Moves the servo to a variety of positions
 *Jonathan Xu
 *January 25, 2017
*/

#include<Servo.h>
Servo base;
Servo pull;

void setup() {
  // put your setup code here, to run once:
  base.attach(10);
  pull.attach(9);
  pull.write(180);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x=75; x<=180; x+=5) {
      for (int y=0; y<=180; y+=5) {
      base.write(y);
      //
      delay(250);
    }
    
    pull.write(x);
    delay(250);
  }
}


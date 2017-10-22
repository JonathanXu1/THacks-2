/*The servo program
 *Moves the servo to a variety of positions
*/

#include<Servo.h>
Servo base;
Servo pull;

const int trigPin = 7;
const int echoPin = 6;

long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  base.attach(10);
  pull.attach(9);
  pull.write(0);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x=0; x<=150; x+=5) {
      for (int y=0; y<=180; y+=5) {
      base.write(y);
      Serial.print("Base position: ");
      Serial.println(y);
      Serial.print("Arm position: ");
      Serial.println(x);
      Serial.print("Distance: ");
      Serial.print(ping());
      Serial.println("cm");
      delay(250);
    }
    pull.write(x);
    delay(250);
  }
}

int ping() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;

  return distance;
}


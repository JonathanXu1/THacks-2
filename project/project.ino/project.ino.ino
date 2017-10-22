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
  pull.write(170);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Welcome to Mapsonic");
  Serial.println("Hit any key to start...");
  while(Serial.available() == 0){};
  
  // put your main code here, to run repeatedly:
  for (int x=170; x>=70; x-=5) {
    if (x%10 == 0){
      for (int y=0; y<=180; y+=5) {
        base.write(y);
        Serial.print("Distance: ");
        ping();
        Serial.print("Base position: ");
        Serial.println(y);
        Serial.print("Arm position: ");
        Serial.println(x);
        
        delay(250);       
      }
    }
    else {
      for (int y=180; y>=0; y-=5) {
        base.write(y);
        Serial.print("Distance: ");
        ping();
        Serial.print("Base position: ");
        Serial.println(y);
        Serial.print("Arm position: ");
        Serial.println(x);
        delay(250);
      }
    }
    delay(250);
    pull.write(x);
  }
  Serial.println("Job done!");
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

  if (distance > 10){
    //Serial.println ("NO OBJECT");
    Serial.print (distance);
    Serial.println("cm");
  }
  else{
    Serial.print (distance);
    Serial.println("cm");
  }
}


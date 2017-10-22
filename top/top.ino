/*The servo program
 *Moves the servo to a variety of positions
 *Jonathan Xu
 *January 25, 2017
*/

const int trigPin = 8;
const int echoPin = 9;

long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("Distance: ");
    Serial.print(ping());
    Serial.println("cm");
    delay(250);
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


// defines pins numbers
const int trigPin = 4;
const int echoPin = 5;
const int Relay = 6;
const int ledPin = 7;
 
// defines variables
long period;
int dist;
int safetyDist;
 
 
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(Relay, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
 
 
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
period = pulseIn(echoPin, HIGH);
 
// Calculating the distance
dist= period*0.034/2;
 
safetyDist = dist;
if (safetyDist <=0.25){
  digitalWrite(Relay, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(Relay, LOW);
  digitalWrite(ledPin, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(dist);
}

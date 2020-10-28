#define echoPin 9
#define trigPin 10 
#define LEDPin 13

// defines variables
long duration; 
int distance; 
int toggle = 0;


void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // 
  pinMode(echoPin, INPUT); // 
  Serial.begin(9600); // // 
}
void loop() {
  Serial.println("Loop started over");
  // Clears the trigPin condition
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 20) {
    Serial.println("We have received a toggle notification");
    toggle = !toggle;
    Serial.println(toggle); // Will return a 0 and a 1 upon going under 20 cm
    if (toggle = 0) { // This is the part of the code that won't work for some damn reason
      digitalWrite(LEDPin, LOW);
    if (toggle = 1) {
      digitalWrite(LEDPin, HIGH);
    }
    } // End part of code that won't work
  }
  
  delay(1500);
}
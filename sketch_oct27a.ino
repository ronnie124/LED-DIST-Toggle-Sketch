#define echoPin 9
#define trigPin 10 
#define LEDPin 13

// defines variables
long duration; 
int distance; 
int toggle;


void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // 
  pinMode(echoPin, INPUT); // 
  Serial.begin(9600); // // 
  toggle = 0;
}
void loop() {
  Serial.println("Loop started over");
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(toggle);
  if (distance < 20) {
    Serial.println("We have received a toggle notification");
    toggle = !toggle;
    Serial.println(toggle); // Will return a 0 and a 1 upon going under 20 cm
    if (toggle == 0) { // This is the part of the code that won't work for some damn reason
      digitalWrite(LEDPin, LOW);
      Serial.println("It's off");
    if (toggle == 1) {
      Serial.println("It's on");
      digitalWrite(LEDPin, HIGH);
    }
    } // End part of code that won't work
  }
  
  delay(1500);
}
}

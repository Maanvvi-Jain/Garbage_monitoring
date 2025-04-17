// Define the pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Define the threshold distance for considering the mug as full (in centimeters)
const float fullThreshold = 5.0; // Adjust this value based on your setup

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Define the sensor pins as input/output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger the ultrasonic sensor to send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the time taken for the pulse to return
  float duration = pulseIn(echoPin, HIGH);
  
  // Convert the duration to distance in centimeters
  float distance = duration * 0.034 / 2;
  
  // Print the measured distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if the dustbin is full
  if (distance <= fullThreshold) {
    Serial.println("Dustbin is Full");
    // Perform actions or send signals as needed when the mug is full
  } else {
    Serial.println("Dustbin is Not Full");
    // Perform actions or send signals as needed when the mug is not full
  }

  // Add a delay before the next measurement to avoid rapid readings
  delay(1000); // Adjust the delay duration as needed
}

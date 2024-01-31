// Define the pin connected to the OUTPUT pin of the motion sensor
const int MOTION_SENSOR_PIN = 6;

// Define the pin connected to the LED
const int LED_PIN = 2;

// Store the current state of the motion sensor's pin
int motionStateCurrent = LOW;

// Store the previous state of the motion sensor's pin
int motionStatePrevious = LOW;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set Arduino pin connected to the motion sensor to input mode
  pinMode(MOTION_SENSOR_PIN, INPUT);

  // Set Arduino pin connected to the LED to output mode
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Store the old state of the motion sensor
  motionStatePrevious = motionStateCurrent;

  // Read the new state of the motion sensor
  motionStateCurrent = digitalRead(MOTION_SENSOR_PIN);

  // Check if there is a change from LOW to HIGH (Motion detected)
  if (motionStatePrevious == LOW && motionStateCurrent == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
  }
  // Check if there is a change from HIGH to LOW (Motion stopped)
  else if (motionStatePrevious == HIGH && motionStateCurrent == LOW) {
    Serial.println("Motion stopped!");
    digitalWrite(LED_PIN, LOW); // Turn off the LED
  }
}

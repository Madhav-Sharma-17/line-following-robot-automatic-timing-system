// ir sensor 1 is to be placed at the start and ir sensor 2 is to be placed at the end
const int irSensor1 = 15;  // GPIO pin for IR sensor 1
const int irSensor2 = 4;  // GPIO pin for IR sensor 2

bool objectDetected1 = false;
bool timerRunning = false;
unsigned long startTime = 0;
unsigned long elapsedTime = 0;

void setup() {
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  Serial.begin(115200);
}

void loop() {
  // Read the IR sensor values
  int sensor1State = digitalRead(irSensor1);  // Reading state of IR sensor 1
  int sensor2State = digitalRead(irSensor2);  // Reading state of IR sensor 2

  // IR Sensor 1: Start the stopwatch when the object leaves (assume LOW means object is detected)
  if (sensor1State == HIGH && !timerRunning && objectDetected1) {
    timerRunning = true;
    startTime = millis();
    Serial.println("Stopwatch started.");
  }
  
  // Update detection status of IR Sensor 1
  if (sensor1State == LOW) {
    objectDetected1 = true;
  }

  // IR Sensor 2: Stop the stopwatch when an object is detected
  if (sensor2State == LOW && timerRunning) {
    timerRunning = false;
    elapsedTime = millis() - startTime;
    Serial.print("Stopwatch stopped. Time elapsed: ");
    Serial.print(elapsedTime / 1000.0, 3);  // Display time in seconds
    Serial.println(" seconds.");
    objectDetected1 = false;  // Reset detection for next measurement
  }

  delay(1);  // Small delay to avoid rapid reading
}

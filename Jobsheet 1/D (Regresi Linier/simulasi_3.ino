// Job 1 D(Langkah 12)
// Evan, Hendra, Bima, Ery

int average = 0; // the average
float vs = 0; //sensor voltage
float moisture = 0;
int inputPin = 2;
void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}
void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;
  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.println(average);
  delay(1); // delay in between reads for stability
  vs = (3.3 / 4095) * average;
  moisture = ax + b;
  Serial.println(vs);
  Serial.println(moisture);
}

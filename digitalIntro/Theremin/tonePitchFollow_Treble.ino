void setup() {
Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A0);
  Serial.println(sensorReading);
  
  int thisPitch = map(sensorReading, 30, 130, 50, 100);

  // play the pitch:
  tone(9, thisPitch, 10);
  delay(1);        // delay in between reads for stability
}

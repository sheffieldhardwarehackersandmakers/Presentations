void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT); //We're going to use Pin 9 as an output
  Serial.begin(9600); //We're going to send data over the Serial connection at baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // read the sensor:
  int sensorReading = analogRead(A0);
  int loopDelay = sensorReading / 10 - 3

  // print the delay factor we've calculated
  Serial.println(loopDelay);

  //Turn the pin on, wait for the correct time
  digitalWrite(9, HIGH);
  delay(loopDelay);
  
  //...Then turn it back off, and wait again
  digitalWrite(9, LOW);
  delay(loopDelay);

  //...now the loop has finished, we're going back to the start  
}

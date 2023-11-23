int sensorPin = A0;
int sensorThreshold = 300;

void setup() {
   Serial.begin(9600);
   pinMode(sensorPin, INPUT);
}

void loop() {
   if (analogRead(sensorPin) > sensorThreshold) {
      Serial.println("Gas concentration too high!");
   } else {
      Serial.println("Gas concentration in control");
   }
}

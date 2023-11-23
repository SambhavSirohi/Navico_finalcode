const int trigPin = 9;
const int echoPin = 10;
int sensorPin = A0;
int sensorThreshold = 300;
long duration;
int distance;
int sound_sensor = A2;
int led = 13;
int vs = A1;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
pinMode(vs, INPUT); 
pinMode(sensorPin, INPUT);
Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(300);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
   if (analogRead(sensorPin) > sensorThreshold) {
      Serial.println("Gas concentration too high!");
   } else {
      Serial.println("Gas concentration in control");
      delay(1000);
   }
  int soundValue = 0; 
  for (int i = 0; i < 32; i++) 
  { soundValue += analogRead(sound_sensor);  } 
  soundValue >>= 5; 
  Serial.print("Sound Produced:");
  Serial.println(soundValue); 
  if (soundValue > 500) { 
    Serial.println("         ||        ");
    Serial.println("       ||||||      ");
    Serial.println("     |||||||||     ");
    Serial.println("   |||||||||||||   ");
    Serial.println(" ||||||||||||||||| ");
    Serial.println("   |||||||||||||   ");
    Serial.println("     |||||||||     ");
    Serial.println("       ||||||      ");
    Serial.println("         ||        ");
  }
  delay(1000);
  long measurement =vibration();
  delay(1000);
  Serial.print("Vibrations Produced:");
  Serial.println(measurement);
  if (measurement > 50){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW); 
  }
}
long vibration(){
  long measurement=pulseIn (vs, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
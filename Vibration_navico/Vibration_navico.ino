int led = 13;
int vs = A1;
 
void setup(){
  pinMode(led, OUTPUT);
  pinMode(vs, INPUT); 
  Serial.begin(9600); 
 
}
void loop(){
  long measurement =vibration();
  delay(50);
  Serial.println(measurement);
  if (measurement > 50){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW); 
  }
}
 
long vibration(){
  long measurement=pulseIn (vs, HIGH);  
  return measurement;
}

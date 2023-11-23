int sound_sensor = A2;
 
void setup() 
{
  Serial.begin(9600);
}
 
void loop()
{
  int soundValue = 0;
  for (int i = 0; i < 32; i++) 
  { soundValue += analogRead(sound_sensor);  } 
 
  soundValue >>= 5; 
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
  delay(50); 
}

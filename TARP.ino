

int trig = 12;
int echo = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  pinMode(7,OUTPUT);
}

void loop()
{
  long t = 0, h = 0, hp = 0;
  
  // Transmitting pulse
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Waiting for pulse
  t = pulseIn(echo, HIGH);
  
  // Calculating distance 
  h = t / 58;
 
  h = h - 6;  // offset correction
  h = 50 - h;  // water height, 0 - 50 cm
  
  hp = 2 * h;  // distance in %, 0-100 %
  
  if(hp < 25 )
  {
    digitalWrite(7,HIGH);
    Serial.begin(38400); // Default communication rate of the Bluetooth module

  }
  
  delay(1000);
}

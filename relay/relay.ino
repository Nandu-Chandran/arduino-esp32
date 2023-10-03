int relayPin=7;
const unsigned long SECOND = 1000;
const unsigned long HOUR = 3600*SECOND;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin,OUTPUT);
  
}

void loop() {
  Serial.println("Waiting for timer");
  delay(10*SECOND);
  Serial.println("Timer ended");
  drivePump();
}

int drivePump(){
  digitalWrite(relayPin,HIGH);
  Serial.println("pump started");
  delay(10*SECOND);
  digitalWrite(relayPin,LOW);
  Serial.println("pump stopped");
  
  }

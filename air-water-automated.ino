const int relayPin1 = 7; // air pump
const int relayPin2 = 8; // water pump
unsigned long waterPumpStartTime = 0;
const unsigned long waterPumpOffTime = 28800000; // 8 hours

void setup()
{
  pinMode(relayPin1, OUTPUT); // set the relay pin as an output - air pump
  pinMode(relayPin2, OUTPUT); // set the relay pin as an output - water pump
}

void loop()
{
  waterPumpStartTime = 0;
  digitalWrite(relayPin2, LOW);
  waterPumpStartTime = millis(); // start time

  while(millis() - waterPumpStartTime < waterPumpOffTime)
  {
    // air pump
    digitalWrite(relayPin1, HIGH);
    delay(1800000); // 30 mins on
    digitalWrite(relayPin1, LOW);
    delay(1800000); // 30 mins off
  }

  digitalWrite(relayPin2, HIGH);
  delay(60000); // 1 min on
  digitalWrite(relayPin2, LOW);
}

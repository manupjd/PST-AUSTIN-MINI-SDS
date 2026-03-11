const int signalPin = 2;

int lastState = LOW;
unsigned long lastChangeTime = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(signalPin, INPUT);
  Serial.println("=== Detection signal ecran / buzzer Valeo ===");
}

void loop()
{
  int state = digitalRead(signalPin);

  if (state != lastState)
  {
    unsigned long now = millis();

    Serial.print(now);
    Serial.print(" ms -> etat : ");
    Serial.println(state);

    if (lastChangeTime != 0)
    {
      Serial.print("Intervalle depuis le changement precedent : ");
      Serial.print(now - lastChangeTime);
      Serial.println(" ms");
    }

    lastChangeTime = now;
    lastState = state;
  }
}
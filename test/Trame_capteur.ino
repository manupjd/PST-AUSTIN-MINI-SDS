byte frame[8];

void setup()
{
  Serial.begin(115200);
  Serial1.begin(19200);

  Serial.println("Lecture trames Valeo");
}

void loop()
{
  if (Serial1.available())
  {
    byte b = Serial1.read();

    if (b == 0xF8)   // début trame
    {
      frame[0] = b;

      for (int i = 1; i < 8; i++)
      {
        while (!Serial1.available());
        frame[i] = Serial1.read();
      }

      Serial.print("TRAME: ");

      for (int i = 0; i < 8; i++)
      {
        Serial.print(frame[i], HEX);
        Serial.print(" ");
      }

      Serial.println();
    }
  }
}
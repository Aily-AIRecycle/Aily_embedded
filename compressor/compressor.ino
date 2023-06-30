#include "mas001.h"
#include "dmd150.h"

MAS001 myShield;
DMD150 myMotor;

String cmd;
int val;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  val = myShield.getPot();

  while (Serial.available()) // mySerial에 전송된 값이 있으면
  {
    cmd = Serial.readStringUntil('\n');
    Serial.println(cmd);

    Serial.println("start");

    if (cmd == "1")
    {
      myMotor.rotation(val / 4);
      Serial.println("Go");
    }
    else if (cmd == "2")
    {
      myMotor.rotation(-val / 4);
      Serial.println("Back");
    }
    else if (cmd == "0")
    {
      myMotor.rotation(0);
      Serial.println("Stop");
    }
  }
}
#include <Servo.h>
#include <SoftwareSerial.h>

#define BT_RXD 7
#define BT_TXD 6
#define servoPin1 12
#define servoPin2 13

SoftwareSerial BtSerial(BT_TXD, BT_RXD); // 블루투스 설정 BTSerial(Tx, Rx)

Servo MG995_Left;  // Create a servo object for the left servo
Servo MG995_Right; // Create a servo object for the right servo

String btcmd;
String cmd;

void setup()
{
  Serial.begin(9600);
  BtSerial.begin(9600);
  MG995_Left.attach(servoPin1);
  MG995_Right.attach(servoPin2);
}

void loop()
{
  if (BtSerial.available() || Serial.available())
  {
    btcmd = BtSerial.read();
    cmd = Serial.read();
    Serial.println(btcmd);
    Serial.println(cmd);

    if (btcmd == "49" || cmd == "49")
    {
      MG995_Left.write(0);    // clockwise
      MG995_Right.write(180); // counter clockwise
      delay(425);
      MG995_Left.write(90);  // stop
      MG995_Right.write(90); // stop
      delay(1000);
      MG995_Left.write(180); // counter clockwise
      MG995_Right.write(0);  // clockwise
      delay(425);
      MG995_Left.write(90);  // stop
      MG995_Right.write(90); // stop
      delay(1000);
    }
    else
    {
      MG995_Left.write(90);
      MG995_Right.write(90);
      delay(1000);
    }
  }
}
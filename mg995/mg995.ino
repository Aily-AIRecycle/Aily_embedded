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

// #include <SoftwareSerial.h>

// //블루투스모듈 HC-06(슬래이브만가능)으로 진행함
// //블루투스모듈 HC-05(슬레이브 마스터둘다가능)는 조금 코드가 다르다
// //HC-06 시리얼창에서 "line ending 없음" 설정할것

// int Tx = 6; //전송 보내는핀
// int Rx = 7; //수신 받는핀

// SoftwareSerial BtSerial(Tx,Rx);

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);

//   Serial.println("hello");
//   BtSerial.begin(9600);

// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   if (BtSerial.available()) {
//     Serial.write(BtSerial.read());
//   }
//   if (Serial.available()) {
//     BtSerial.write(Serial.read());
//   }
// }
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define dirPin1 2
#define stepPin1 3
#define dirPin2 4
#define stepPin2 5
#define secPerDis 16000 // 16 seconds per 15cm

RF24 radio(7, 8);
const byte address[6] = "00001";

String cmd;
unsigned long t1, t2;

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  // Declare pins as output:
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    cmd = Serial.readStringUntil('\n');
    Serial.println(cmd);
    // 일반 = 1, 플라스틱 = 2, 캔 = 3
    if (cmd == "1") // 일반
    {
      delay(9000); // 9초 대기 중 압축(Serial신호)

      const char rdcmd[] = "throw";
      radio.write(&rdcmd, sizeof(rdcmd));
      delay(2000); // 2초 대기 중 바닥 열림(RF신호)
    }
    else if (cmd == "2") // 플라스틱
    {
      delay(9000); // 9초 대기 중 압축(Serial신호)

      t1 = millis();
      digitalWrite(dirPin1, HIGH);
      digitalWrite(dirPin2, HIGH);
      while (1) // 이동
      {
        t2 = millis();
        go();
        if ((t2 - t1) > 32000)
          break;
      }

      const char rdcmd[] = "throw";
      radio.write(&rdcmd, sizeof(rdcmd));
      delay(2000); // 2초 대기 중 바닥 열림(RF신호)

      digitalWrite(dirPin1, LOW);
      digitalWrite(dirPin2, LOW);
      while (1) // 복귀
      {
        t2 = millis();
        go();
        if ((t2 - t1) > 32000)
          break;
      }
    }
    else if (cmd == "3") // 캔
    {
      delay(9000); // 9초 대기 중 압축(Serial신호)

      t1 = millis();
      digitalWrite(dirPin1, HIGH);
      digitalWrite(dirPin2, HIGH);
      while (1) // 이동
      {
        t2 = millis();
        go();
        if ((t2 - t1) > 64000)
          break;
      }

      const char rdcmd[] = "throw";
      radio.write(&rdcmd, sizeof(rdcmd));
      delay(2000); // 2초 대기 중 바닥 열림(RF신호)

      digitalWrite(dirPin1, LOW);
      digitalWrite(dirPin2, LOW);
      while (1) // 복귀
      {
        t2 = millis();
        go();
        if ((t2 - t1) > 64000)
          break;
      }
    }
    else
    {
      stop();
    }
  }
}

void go()
{
  digitalWrite(stepPin1, HIGH);
  digitalWrite(stepPin2, HIGH);
  delayMicroseconds(7);
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  delayMicroseconds(7);
}

void stop()
{
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
}
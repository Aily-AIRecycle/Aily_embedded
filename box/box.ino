#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define servoPin_Left 2
#define servoPin_Right 3

Servo MG995_Left;  // Create a servo object for the left servo
Servo MG995_Right; // Create a servo object for the right servo

RF24 radio(7, 8);                // SPI 버스에 nRF24L01 라디오를 설정하기 위해 CE, CSN 선언.
const byte address[6] = "00001"; // 주소값을 5가지 문자열로 변경할 수 있으며, 송신기과 수신기가 동일한 주소로 해야됨.

void setup()
{
    Serial.begin(9600);
    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN); // 전원공급에 관한 파워레벨을 설정합니다. 모듈 사이가 가까우면 최소로 설정합니다.
    // 거리가 가까운 순으로 RF24_PA_MIN / RF24_PA_LOW / RF24_PA_HIGH / RF24_PA_MAX 등으로 설정할 수 있습니다.
    // 높은 레벨(거리가 먼 경우)은 작동하는 동안 안정적인 전압을 가지도록 GND와 3.3V에 바이패스 커패시터 사용을 권장함
    radio.startListening(); // 모듈을 수신기로 설정
    MG995_Left.attach(servoPin_Left);
    MG995_Right.attach(servoPin_Right);
}

void loop()
{
    if (radio.available())
    {
        char rdcmd;
        radio.read(&rdcmd, sizeof(rdcmd));
        Serial.println(rdcmd);
        Serial.println("start");

        if (rdcmd == 't')
        {
            Serial.println("go");
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

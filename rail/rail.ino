#include <SoftwareSerial.h>
#include <HCMotor.h>

#define DIR_PIN 8               // Step motor driver DIR connection pin
#define CLK_PIN 9               // Step motor driver CLK connection pin
#define DIR_PIN2 7              // Step motor driver 2 DIR2 connection pin
#define CLK_PIN2 6              // Step motor driver 2 CLK2 connection pin
SoftwareSerial bluetooth(2, 3); // tx 2 rx 3

/* Create HCMotor library instances */
HCMotor HCMotor1;
HCMotor HCMotor2;

int Speed = 9; // 10으로 올리면 더 느려짐

String cmd;

void setup()
{
  Serial.begin(9600);
  /* Library initialization */
  HCMotor1.Init();
  HCMotor2.Init();

  /* Set motor 1 as a stepper motor and specify the connected pins */
  HCMotor1.attach(0, STEPPER, CLK_PIN, DIR_PIN);

  /* Set motor 2 as a stepper motor and specify the connected pins */
  HCMotor2.attach(1, STEPPER, CLK_PIN2, DIR_PIN2);

  /* Set the motors to continuous operation mode */
  HCMotor1.Steps(0, CONTINUOUS);
  HCMotor2.Steps(1, CONTINUOUS);
  bluetooth.begin(9600);
}

void loop()
{
  if (bluetooth.available())
  {

    Serial.write(bluetooth.read());
  }

  if (Serial.available())
  {

    bluetooth.write(Serial.read());
  }

  if (Serial.available())
  {
    cmd = Serial.readStringUntil('\n');
    Serial.println(cmd);

    // if (cmd == "1")
    // {
    //   HCMotor1.DutyCycle(0, Speed);
    //   HCMotor2.DutyCycle(1, Speed);
    //   HCMotor1.Direction(0, FORWARD);     // 모터쪽으로 가는게 포워드임
    //   HCMotor2.Direction(1, FORWARD);
    //   delay(3000);
    //   HCMotor1.DutyCycle(0, 0);
    //   HCMotor2.DutyCycle(1, 0);
    // }
    // if (cmd == "2")
    // {
    //   HCMotor1.DutyCycle(0, Speed);
    //   HCMotor2.DutyCycle(1, Speed);
    //   HCMotor1.Direction(0, REVERSE);
    //   HCMotor2.Direction(1, REVERSE);
    //   delay(3000);
    //   HCMotor1.DutyCycle(0, 0);
    //   HCMotor2.DutyCycle(1, 0);
    // }
    // else
    // {
    //   HCMotor1.DutyCycle(0, 0);
    //   HCMotor2.DutyCycle(1, 0);
    //   delay(3000);
    // }

    // 레일 조정용 코드
    if (cmd == "0")
    {
      Serial.println("stop");
      HCMotor1.DutyCycle(0, 0);
      HCMotor2.DutyCycle(1, 0);
    }
    if (cmd == "1")
    {
      Serial.println("go forward");
      HCMotor1.DutyCycle(0, Speed);
      HCMotor1.Direction(0, FORWARD);
      HCMotor2.DutyCycle(1, Speed);
      HCMotor2.Direction(1, FORWARD);
    }
    if (cmd == "2")
    {
      Serial.println("go backward");
      HCMotor1.DutyCycle(0, Speed);
      HCMotor1.Direction(0, REVERSE);
      HCMotor2.DutyCycle(1, Speed);
      HCMotor2.Direction(1, REVERSE);
    }
  }
}

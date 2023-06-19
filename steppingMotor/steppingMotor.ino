#include <HCMotor.h>

#define DIR_PIN 8     // Step motor driver DIR connection pin
#define CLK_PIN 9     // Step motor driver CLK connection pin
#define DIR_PIN2 7    // Step motor driver 2 DIR2 connection pin
#define CLK_PIN2 6    // Step motor driver 2 CLK2 connection pin

/* Create HCMotor library instances */
HCMotor HCMotor1;
HCMotor HCMotor2;

int Speed = 9;

void setup()
{
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

  /* Set speed for both motors */
  HCMotor1.DutyCycle(0, Speed);
  HCMotor2.DutyCycle(1, Speed);
}

void loop()
{
  /* Move both motors forward */
  HCMotor1.Direction(0, FORWARD);
  HCMotor2.Direction(1, FORWARD);
  delay(3000);

  /* Move both motors in reverse */
  HCMotor1.Direction(0, REVERSE);
  HCMotor2.Direction(1, REVERSE);
  delay(3000);
}

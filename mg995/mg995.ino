#include <Servo.h>

Servo mg995_1;  // Create a servo object for the first servo
Servo mg995_2;  // Create a servo object for the second servo

const int servoPin1 = 12;  // Pin for the first servo
const int servoPin2 = 13;  // Pin for the second servo

void setup()
{
  mg995_1.attach(servoPin1);
  mg995_2.attach(servoPin2);
}

void loop()
{
  // Rotate both servos 90 degrees clockwise
  mg995_1.write(0);    // Set the first servo position to the minimum angle (0 degrees)
  mg995_2.write(0);    // Set the second servo position to the minimum angle (0 degrees)
  delay(1000);         // Delay for servos to reach the positions
  
  // Rotate both servos back to the original position (90 degrees)
  mg995_1.write(90);   // Set the first servo position to the original angle (90 degrees)
  mg995_2.write(90);   // Set the second servo position to the original angle (90 degrees)
  delay(1000);         // Delay for servos to reach the positions

  // Rotate both servos 90 degrees counterclockwise
  mg995_1.write(180);  // Set the first servo position to the maximum angle (180 degrees)
  mg995_2.write(180);  // Set the second servo position to the maximum angle (180 degrees)
  delay(1000);         // Delay for servos to reach the positions
  
  // Rotate both servos back to the original position (90 degrees)
  mg995_1.write(90);   // Set the first servo position to the original angle (90 degrees)
  mg995_2.write(90);   // Set the second servo position to the original angle (90 degrees)
  delay(1000);         // Delay for servos to reach the positions
}

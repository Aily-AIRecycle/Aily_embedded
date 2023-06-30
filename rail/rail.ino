#define dirPin1 2
#define stepPin1 3
#define dirPin2 4
#define stepPin2 5

String cmd;

void setup()
{
  Serial.begin(9600);
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
    if (cmd == "1")
    {
      forward();
    }
    else if (cmd == "2")
    {
      backward();
    }
  }
}

void forward()
{
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  digitalWrite(stepPin1, HIGH);
  digitalWrite(stepPin2, HIGH);
  delayMicroseconds(7);
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  delayMicroseconds(7);
}

void backward()
{
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  digitalWrite(stepPin1, HIGH);
  digitalWrite(stepPin2, HIGH);
  delayMicroseconds(7);
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  delayMicroseconds(7);
}
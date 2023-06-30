#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 16000

String cmd;
unsigned long t1, t2;

void setup()
{
    Serial.begin(9600);
    // Declare pins as output:
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

void loop()
{
    if (Serial.available())
    {
        cmd = Serial.readStringUntil('\n');
        Serial.println("ready");
        if (cmd == "1")
        {
            t1 = millis();

            Serial.println("1");
            digitalWrite(dirPin, HIGH);
            while (1)
            {
                t2 = millis();

                digitalWrite(stepPin, HIGH);
                delayMicroseconds(7);
                digitalWrite(stepPin, LOW);
                delayMicroseconds(7);
                if ((t2 - t1) > 200)
                    break;
            }
        }
        else if (cmd == "2")
        {
            t1 = millis();

            Serial.println("2");
            digitalWrite(dirPin, LOW);

            while (1)
            {
                t2 = millis();
                digitalWrite(stepPin, HIGH);
                delayMicroseconds(7);
                digitalWrite(stepPin, LOW);
                delayMicroseconds(7);
                if ((t2 - t1) > 5000)
                    break;
            }
        }
        else if (cmd == "0")
        {
            Serial.println("0");
            digitalWrite(dirPin, LOW);
            digitalWrite(stepPin, LOW);
        }
    }
}
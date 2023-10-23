// 1번 모터 핀 정의
#define IN1_PIN1  3
#define IN2_PIN1  5
#define PWM_PIN1  6

// // 2번 모터 핀 정의
#define IN1_PIN2  9
#define IN2_PIN2  10
#define PWM_PIN2  11

String cmd;


void setup() {
  Serial.begin(9600);
  // 1번 모터 핀 설정
  pinMode(IN1_PIN1, OUTPUT);
  pinMode(IN2_PIN1, OUTPUT);
  pinMode(PWM_PIN1, OUTPUT);

  // // 2번 모터 핀 설정
  pinMode(IN1_PIN2, OUTPUT);
  pinMode(IN2_PIN2, OUTPUT);
  pinMode(PWM_PIN2, OUTPUT);
}

void loop() {
  if (Serial.available())
  {
    cmd = Serial.readStringUntil('\n');
    Serial.println(cmd);
    if (cmd == "1")
    {
      // 1번 모터는 정방향, 2번 모터는 역방향으로 회전
      rotation(IN1_PIN1, IN2_PIN1, PWM_PIN1, -255);
      rotation(IN1_PIN2, IN2_PIN2, PWM_PIN2, 255);
      delay(1400);

      // 두 모터를 동시에 정지
      // 내려갔다가 멈추고 올라올 때의 멈추는 상태 : 딜레이를 짧게 줌
      brake(IN1_PIN1, IN2_PIN1, PWM_PIN1);
      brake(IN1_PIN2, IN2_PIN2, PWM_PIN2);
      delay(1000);

      // // 1번 모터는 역방향, 2번 모터는 정방향으로 회전
      rotation(IN1_PIN1, IN2_PIN1, PWM_PIN1, 255);
      rotation(IN1_PIN2, IN2_PIN2, PWM_PIN2, -255);
      delay(1400);

      brake(IN1_PIN1, IN2_PIN1, PWM_PIN1);
      brake(IN1_PIN2, IN2_PIN2, PWM_PIN2);
      delay(1000);

    }
    
    else if (cmd == "2")
    {
      delay(36000);
      // 1번 모터는 정방향, 2번 모터는 역방향으로 회전
      rotation(IN1_PIN1, IN2_PIN1, PWM_PIN1, -255);
      rotation(IN1_PIN2, IN2_PIN2, PWM_PIN2, 255);
      delay(1400);

      // 두 모터를 동시에 정지
      // 내려갔다가 멈추고 올라올 때의 멈추는 상태 : 딜레이를 짧게 줌
      brake(IN1_PIN1, IN2_PIN1, PWM_PIN1);
      brake(IN1_PIN2, IN2_PIN2, PWM_PIN2);
      delay(1000);

      // // 1번 모터는 역방향, 2번 모터는 정방향으로 회전
      rotation(IN1_PIN1, IN2_PIN1, PWM_PIN1, 255);
      rotation(IN1_PIN2, IN2_PIN2, PWM_PIN2, -255);
      delay(1400);

      brake(IN1_PIN1, IN2_PIN1, PWM_PIN1);
      brake(IN1_PIN2, IN2_PIN2, PWM_PIN2);
      delay(1000);
    }
    else if (cmd == "3")
    {
      delay(68000);
      // 1번 모터는 정방향, 2번 모터는 역방향으로 회전
      rotation(IN1_PIN1, IN2_PIN1, PWM_PIN1, -255);
      rotation(IN1_PIN2, IN2_PIN2, PWM_PIN2, 255);
      delay(1400);

      // 두 모터를 동시에 정지
      // 내려갔다가 멈추고 올라올 때의 멈추는 상태 : 딜레이를 짧게 줌
      brake(IN1_PIN1, IN2_PIN1, PWM_PIN1);
      brake(IN1_PIN2, IN2_PIN2, PWM_PIN2);
      delay(1000);

      // // 1번 모터는 역방향, 2번 모터는 정방향으로 회전
      rotation(IN1_PIN1, IN2_PIN1, PWM_PIN1, 255);
      rotation(IN1_PIN2, IN2_PIN2, PWM_PIN2, -255);
      delay(1400);

      brake(IN1_PIN1, IN2_PIN1, PWM_PIN1);
      brake(IN1_PIN2, IN2_PIN2, PWM_PIN2);
      delay(1000);

    }
    else if (cmd == "10")
    {
      rotation(IN1_PIN1, IN2_PIN1, PWM_PIN1, 255);
      delay(100);
      brake(IN1_PIN1, IN2_PIN1, PWM_PIN1);
      delay(1000);
    }
    else if (cmd == "20")
    {
      rotation(IN1_PIN2, IN2_PIN2, PWM_PIN2, 255);
      delay(100);
      brake(IN1_PIN2, IN2_PIN2, PWM_PIN2);
      delay(1000);
    }
  }
  
}

void brake(int IN1, int IN2, int PWM) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(PWM, 0);
}

void rotation(int IN1, int IN2, int PWM, int16_t spd) {
  if (spd > 255) spd = 255;
  else if (spd < -255) spd = -255;

  if (spd > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWM, spd);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(PWM, -spd);
  }
}

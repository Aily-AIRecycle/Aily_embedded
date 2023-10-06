#include "dmd150.h"

#define IN1_PIN	5
#define IN2_PIN	6
#define PWM_PIN	9

DMD150::DMD150(){
	pinMode(IN1_PIN, OUTPUT);
	pinMode(IN2_PIN, OUTPUT);
	pinMode(PWM_PIN, OUTPUT);
}

void DMD150::brake(){
	digitalWrite(IN1_PIN, LOW);
	digitalWrite(IN2_PIN, LOW);
	analogWrite(PWM_PIN, 0);
}

void DMD150::floating(){
	digitalWrite(IN1_PIN, HIGH);
	digitalWrite(IN2_PIN, HIGH);
	analogWrite(PWM_PIN, 0);	
}

void DMD150::rotation(int16_t spd){
	if(spd > 255) spd = 255; //스피드가 255보다 크면 스피드는 255로 => speed 의 max_value를 255로 고정
	else if(spd < -255) spd = -255; //스피드가 -255보다 작으면 스피드는 -255로 => speed 의 min_value를 -255로 고정

	if(spd > 0){ // 스피드가 음수이면, 각 StepMotor Input_value에 HIGH 와 LOW를 제어해서 스피드를 기준으로 들어갔다 나왔다를 제어함
		digitalWrite(IN1_PIN, HIGH);
		digitalWrite(IN2_PIN, LOW);
		analogWrite(PWM_PIN, spd); //PWM => 펄스를 analogWrite로 읽어서 speed 속도로 움직임
	}else{
		digitalWrite(IN1_PIN, LOW);
		digitalWrite(IN2_PIN, HIGH);
		analogWrite(PWM_PIN, -spd);		
	}
	
}
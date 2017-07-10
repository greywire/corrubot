#include <Arduino.h>

/*

v 1.1
*/

const int motor_left_forward = 3;
const int motor_left_backward = 5;
//const int motor_left_enable = 4;
const int motor_right_forward = 9;
const int motor_right_backward = 6;
//const int motor_right_enable = 7;
const int bumper_left = 4;
const int bumper_right = 7;

const int ir_l = 0;
const int ir_c = 1;
const int ir_r = 2;


class motor {
};

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int switchState = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);

  pinMode(motor_left_forward, OUTPUT);
  pinMode(motor_left_backward, OUTPUT);
  pinMode(motor_right_forward, OUTPUT);
  pinMode(motor_right_backward, OUTPUT);
  //pinMode(motor_right_enable, OUTPUT);
  //pinMode(motor_left_enable, OUTPUT);

  pinMode(bumper_left, INPUT);
  pinMode(bumper_right, INPUT);

  pinMode(ir_l, INPUT);
  pinMode(ir_c, INPUT);
  pinMode(ir_r, INPUT);

}

void motorSpeed(int motorf, int motorb, int speed) {
  if (speed > 0) {
    analogWrite(motorf, speed);
    analogWrite(motorb, 0);
  } else if (speed < 0) {
    analogWrite(motorb, abs(speed));
    analogWrite(motorf, 0);
  } else {
    analogWrite(motorb, speed);
    analogWrite(motorf, speed);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  bool left_forward;
  bool right_forward;
  bool left_bump;
  bool right_bump;
  int right_ir;
  int center_ir;
  int left_ir;

  left_bump = digitalRead(bumper_left);
  right_bump = digitalRead(bumper_right);
  right_ir = analogRead(ir_r);
  center_ir = analogRead(ir_c);
  left_ir = analogRead(ir_l);

  if (left_bump) {
    Serial.print("Left Bump\n");
    //motorSpeed(motor_right_forward,motor_right_backward, 8);
	//motorSpeed(motor_left_forward,motor_left_backward, 8);
    //delay(250);
	motorSpeed(motor_right_forward,motor_right_backward, 0);
	motorSpeed(motor_left_forward,motor_left_backward, -80);
    delay(250);
	//motorSpeed(motor_right_forward,motor_right_backward, 8);
	//motorSpeed(motor_left_forward,motor_left_backward, 8);

  } else if (right_bump) {
    Serial.print("Right Bump\n");
    //motorSpeed(motor_right_forward,motor_right_backward, 8);
	//motorSpeed(motor_left_forward,motor_left_backward, 8);
    //delay(250);
	motorSpeed(motor_right_forward,motor_right_backward, -80);
	motorSpeed(motor_left_forward,motor_left_backward, 0);
    delay(250);
	//motorSpeed(motor_right_forward,motor_right_backward, 8);
	//motorSpeed(motor_left_forward,motor_left_backward, 8);
} /*else if (right_ir) {
    Serial.print("Right IR\n");

	motorSpeed(motor_right_forward,motor_right_backward, -8);
	motorSpeed(motor_left_forward,motor_left_backward, 0);
    delay(25);
  } else if (center_ir) {
    Serial.print("Center IR\n");

	motorSpeed(motor_right_forward,motor_right_backward, -8);
	motorSpeed(motor_left_forward,motor_left_backward, 0);
    delay(25);

  } else if (left_ir) {
    Serial.print("Left IR\n");

	motorSpeed(motor_right_forward,motor_right_backward, -8);
	motorSpeed(motor_left_forward,motor_left_backward, 0);
    delay(25);

  }*/ else {
	motorSpeed(motor_right_forward,motor_right_backward, 120);
	motorSpeed(motor_left_forward,motor_left_backward, 120);
  }
}

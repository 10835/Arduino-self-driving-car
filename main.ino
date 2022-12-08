/*
AFMotor: https://github.com/adafruit/Adafruit-Motor-Shield-library
Ultrasonic Eric
*/

#include <AFMotor.h>
#include <Ultrasonic.h>

AF_DCMotor left_motor(1,MOTOR12_64KHZ); //FORWARD = GO FORWARD
AF_DCMotor right_motor(2,MOTOR12_64KHZ); //FORWARD = GO BACKWARD
Ultrasonic ultrasonic(A0, A1);

int distance;
int detected_d = 15;
int rotating_speed = 150;

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Stepper test!");
  left_motor.setSpeed(rotating_speed);
  right_motor.setSpeed(rotating_speed);
}


void loop(){
  distance = ultrasonic.read(); //不加參數就是輸出CM，可用read(INC)輸出英寸
  if(distance > detected_d)
  {
    Serial.print("ON:  ");
    Serial.println(distance);
    left_motor.run(FORWARD);
    right_motor.run(FORWARD);
  }
  
  else
  {
    Serial.print("OFF: ");
    Serial.println(distance);
    left_motor.run(BACKWARD);
    right_motor.run(BACKWARD);
    delay(400);
    turn_left(500);
  }
}

void turn_left(int millisecond)
{
  left_motor.run(FORWARD);
  right_motor.run(BACKWARD);
  delay(millisecond);
}

void turn_right(int millisecond)
{
  left_motor.run(BACKWARD);
  right_motor.run(FORWARD);
  delay(millisecond);
}

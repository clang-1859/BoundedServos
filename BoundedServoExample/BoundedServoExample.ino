/*
 * BoundedServoExample
 * Extends Servo.h functionality with min and max bounds
 * Also provides easy methods to set a servo's position or to rotate by a certain amount
 */

#include<BoundedServo.h>

//create the BoundedServo
BoundedServo servo;

//turn the servo by a certain amount
int turnAmount = 5;

void setup()
{
  //open serial port at 9600baud
  Serial.begin(9600);
  
  //set the PWM pin to be used to control the servo
  servo.attach(11);

  //set the minimum and maximum values the servo can turn to
  //by default, the min and max are 0 and 180, respectively
  servo.setBounds(40,120);

  //getMin() and getMax() return the servo's min and max, respectively
  char bounds[100];
  sprintf(bounds, "Min Bound: %d, Max Bound: %d\n", servo.getMin(), servo.getMax());
  Serial.println(bounds);

  //use set to set the current position of the servo
  //target must be within the bounds you set
  servo.set(90);
}

void loop(){}

//runs when serial data is recieved
void serialEvent()
{
  //get input
  int val = Serial.read();

  //turn the servo based on key press
  //use move to rotate the servo by a certain amount
  switch (val)
  {
    case 'w':
      servo.move(turnAmount);
      break;
    case 's':
      servo.move(-turnAmount);
      break;
  }

  //getPosition() returns the current position of the servo
  char angle[50];
  sprintf(angle, "Current Position: %d\n", servo.getPosition());
  Serial.println(angle);
}

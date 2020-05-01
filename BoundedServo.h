#ifndef BoundedServo_h
#define BoundedServo_h

#include<Servo.h>
#include<Arduino.h>

class BoundedServo
{
  public:
	void attach(int pin); //attaches pin to the servo object
	void setBounds(int min, int max); //set maximum and minimum value for servo
    int getMax(); //returns maximum value
    int getMin(); //returns minimum value
	int getPosition(); //returns current position of servo
	void move(int i); //turn servo by specified number of degrees
	void set(int i); //move servo to specified angle
	
  private:
	Servo _ser; //servo object
	int _max = 180; //maximum bound for servo movement. defaults to 180
	int _min = 0; //minimum bound for servo movement. defaults to 0
};

#endif

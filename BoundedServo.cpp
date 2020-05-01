#include "Servo.h"
#include "Arduino.h"
#include "BoundedServo.h"

//sets the PWM pin for the servo
void BoundedServo::attach(int pin)
{
	_ser.attach(pin);
}

void BoundedServo::setBounds(int min, int max)
{  
    //set minimum value of servo, making sure it is between 0 and 180
    if (min < 0)
    {
        _min = 0;
    }
    else if (min > 180)
    {
        _min = 180;
    }
    else
    {
        _min = min;
    }
  
    //set maximum value of servo, making sure it is between 0 and 180
    if (max < 0)
    {
        _max = 0;
    }
    else if (max > 180)
    {
        _max = 180;
    }
    else
    {
        _max = max;
    }
}

//return maximum value
int BoundedServo::getMax()
{
    return _max;
}

//return minimum value
int BoundedServo::getMin()
{
    return _min;
}

//return current position of servo
int BoundedServo::getPosition()
{
    return _ser.read();
}

//move servo by specified number of degrees
//use both positive and negative to control direction of turn
void BoundedServo::move(int i)
{
	int pos = _ser.read() + i;
	
	if (pos > 180)
		pos = 180;
	else if (pos < 0)
		pos = 0;
	
	set(pos);
}

//move servo to specified position
void BoundedServo::set(int i)
{
	if (i >= _min && i <= _max)
	{
		_ser.write(i);;
	}
}


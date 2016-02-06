#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *driveJoy, *auxJoy;
	JoystickButton *b1, *b2, *b3, *b4, *b5, *b6, *b7, *b8, *b9, *b10, *b11;
public:
	OI();
	Joystick *GetDriveJoy();
	Joystick *GetAuxJoy();
};

#endif

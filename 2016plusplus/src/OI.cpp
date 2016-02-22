#include "OI.h"
#include "Commands/ContinuousDrive.h"
#include "Commands/ArmForward.h"
#include "Commands/ArmBackward.h"
#include "Commands/TimedLinearDrive.h"
#include "Commands/CTTurn.h"

OI::OI()
{
	// Process operator interface input here.
	driveJoy = new Joystick(0);
	auxJoy = new Joystick(1);

	b1 = new JoystickButton(driveJoy, 1);
	b2 = new JoystickButton(driveJoy, 2);
	b3 = new JoystickButton(driveJoy, 3);
	b4 = new JoystickButton(driveJoy, 4);
	b5 = new JoystickButton(driveJoy, 5);
	b6 = new JoystickButton(driveJoy, 6);
	b7 = new JoystickButton(driveJoy, 7);
	b8 = new JoystickButton(driveJoy, 8);
	b9 = new JoystickButton(driveJoy, 9);
	b10 = new JoystickButton(driveJoy, 10);
	b11= new JoystickButton(driveJoy, 11);


	b1->WhileHeld(new ArmForward());
	b2->WhileHeld(new ArmBackward());
//	b4->WhileHeld(new CTTurn(leftRev));
//	b5->WhileHeld(new CTTurn(rightForw));
//
//	b6->WhileHeld(new CTTurn(leftForw));
//	b7->WhileHeld(new CTTurn(leftRev));
//	b11->WhileHeld(new CTTurn(rightForw));
//	b10->WhileHeld(new CTTurn(rightRev));
}

Joystick *OI::GetDriveJoy()
{
	return driveJoy;
}

Joystick *OI::GetAuxJoy()
{
	return auxJoy;
}

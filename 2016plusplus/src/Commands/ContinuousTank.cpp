#include "ContinuousTank.h"

ContinuousTank::ContinuousTank()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void ContinuousTank::Initialize()
{
	chassis->Stop();
}

// Called repeatedly when this Command is scheduled to run
void ContinuousTank::Execute()
{
	Joystick *left = oi->GetDriveJoy();
	Joystick *right = oi->GetAuxJoy();
	chassis->TankDrive(left->GetY(),right->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool ContinuousTank::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ContinuousTank::End()
{
	chassis->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ContinuousTank::Interrupted()
{
	End();
}

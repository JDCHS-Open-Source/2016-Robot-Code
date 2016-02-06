#include "TimedLinearDrive.h"

TimedLinearDrive::TimedLinearDrive(double timeout, LinearDirection direction)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
	SetTimeout(timeout);
	dir = direction;
}

// Called just before this Command runs the first time
void TimedLinearDrive::Initialize()
{
	chassis->Stop();
	if (dir == forward) {
		chassis->DriveForward();
	} else { // dir == backward
		chassis->DriveBackward();
	}
}

// Called repeatedly when this Command is scheduled to run
void TimedLinearDrive::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool TimedLinearDrive::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void TimedLinearDrive::End()
{
	chassis->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedLinearDrive::Interrupted()
{
	End();
}

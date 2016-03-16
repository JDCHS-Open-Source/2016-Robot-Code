#include "TimedLinearDrive.h"

TimedLinearDrive::TimedLinearDrive(double timeout, float pow, LinearDirection direction)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
	SetTimeout(timeout);
	dir = direction;
	power = pow;
}

// Called just before this Command runs the first time
void TimedLinearDrive::Initialize()
{
	SmartDashboard::PutString("Drive Status", "Timed Linear");
	chassis->Stop();
}

// Called repeatedly when this Command is scheduled to run
void TimedLinearDrive::Execute()
{
//	chassis->Stop();
	if (dir == forward) {
		chassis->DriveForward(power);
	} else { // dir == backward
		chassis->DriveBackward(power);
	}
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

#include "ArmForward.h"

ArmForward::ArmForward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(robotArm);
}

// Called just before this Command runs the first time
void ArmForward::Initialize()
{
	robotArm->Stop();
}

// Called repeatedly when this Command is scheduled to run
void ArmForward::Execute()
{
	robotArm->ArmOut();
}

// Make this return true when this Command no longer needs to run execute()
bool ArmForward::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmForward::End()
{
	robotArm->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmForward::Interrupted()
{
	End();
}

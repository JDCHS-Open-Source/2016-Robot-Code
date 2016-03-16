#include "ArmForward.h"

ArmForward::ArmForward(double timeout)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(robotArm);
	SetTimeout(timeout);
}

// Called just before this Command runs the first time
void ArmForward::Initialize()
{
	robotArm->Stop();
	SmartDashboard::PutString("Arm Status", "Arm Engaged Forward");
}

// Called repeatedly when this Command is scheduled to run
void ArmForward::Execute()
{
	robotArm->ArmOut();
}

// Make this return true when this Command no longer needs to run execute()
bool ArmForward::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void ArmForward::End()
{
	robotArm->Stop();
	SmartDashboard::PutString("Arm Status", "Arm Disabled");

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmForward::Interrupted()
{
	End();
}

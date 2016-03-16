#include "ArmBackward.h"

ArmBackward::ArmBackward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(robotArm);
}

// Called just before this Command runs the first time
void ArmBackward::Initialize()
{
	robotArm->Stop();
	SmartDashboard::PutString("Arm Status", "Arm Engaged Forward");
}

// Called repeatedly when this Command is scheduled to run
void ArmBackward::Execute()
{
	robotArm->ArmIn();
}

// Make this return true when this Command no longer needs to run execute()
bool ArmBackward::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmBackward::End()
{
	robotArm->Stop();
	SmartDashboard::PutString("Arm Status", "Arm Disabled");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmBackward::Interrupted()
{
	End();
}

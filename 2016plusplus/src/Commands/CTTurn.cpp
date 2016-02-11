#include "CTTurn.h"
#include "../CommandBase.h"

CTTurn::CTTurn(TurnDirection d, float p, double timeout = 0.0)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
	power = p;
	dir = d;
	if(timeout == 0) {
	SetTimeout(timeout);
	}
}

// Called just before this Command runs the first time
void CTTurn::Initialize()
{
	chassis->Stop();
	chassis->SetTurn(dir, power, power);
}

// Called repeatedly when this Command is scheduled to run
void CTTurn::Execute()
{
	chassis->SetTurn(dir, power, power);
}

// Make this return true when this Command no longer needs to run execute()
bool CTTurn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CTTurn::End()
{
	chassis->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CTTurn::Interrupted()
{
	End();
}

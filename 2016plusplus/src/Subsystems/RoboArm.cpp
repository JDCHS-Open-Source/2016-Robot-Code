#include "RoboArm.h"
#include "../RobotMap.h"

RoboArm::RoboArm() :
		Subsystem("ExampleSubsystem")
{
	roboArm = new Talon(ROBOTARM);
}

void RoboArm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void RoboArm::ArmIn()
{
	roboArm->Set(-1);
}

void RoboArm::ArmOut()
{
	roboArm->Set(1);
}

void RoboArm::Stop()
{
	roboArm->Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

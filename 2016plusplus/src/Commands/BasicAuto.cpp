#include "BasicAuto.h"
#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "ArmForward.h"
#include "TimedLinearDrive.h"

BasicAuto::BasicAuto()
{
	float armTime = SmartDashboard::GetNumber("DB/Slider 0", 0.2);
	float driveTime = SmartDashboard::GetNumber("DB/Slider 1", 2);
	AddSequential(new ArmForward(armTime));
	AddSequential(new TimedLinearDrive(driveTime, forward));
}

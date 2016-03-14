#include "BasicAuto.h"
#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "ArmForward.h"
#include "TimedLinearDrive.h"

BasicAuto::BasicAuto()
{
	AddSequential(new ArmForward(0.2));
	AddSequential(new TimedLinearDrive(1.0,0.25, forward));
}

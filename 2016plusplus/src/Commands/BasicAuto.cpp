#include "BasicAuto.h"
#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "ArmForward.h"
#include "TimedLinearDrive.h"

BasicAuto::BasicAuto()
{
	AddSequential(new ArmForward(0.3));
	AddSequential(new TimedLinearDrive(2,0.5, forward));
}

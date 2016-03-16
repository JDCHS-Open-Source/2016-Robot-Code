#include "CommandBase.h"
#include "Subsystems/DriveMotors.h"
#include "Subsystems/RoboArm.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveMotors* CommandBase::chassis = NULL;
RoboArm* CommandBase::robotArm = NULL;
OI* CommandBase::oi = NULL;
Grabber* CommandBase::grabber = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{

}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	chassis = new DriveMotors();
	robotArm = new RoboArm();
	grabber = new Grabber();
	oi = new OI();
}

#ifndef RoboArm_H
#define RoboArm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class RoboArm: public Subsystem
{
private:
	Talon *roboArm;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	RoboArm();
	void InitDefaultCommand();
	void ArmIn();
	void ArmOut();
	void Stop();
};

#endif

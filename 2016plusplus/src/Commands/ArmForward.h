#ifndef ArmForward_H
#define ArmForward_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmForward: public CommandBase
{
public:
	ArmForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef ArmBackward_H
#define ArmBackward_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmBackward: public CommandBase
{
public:
	ArmBackward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

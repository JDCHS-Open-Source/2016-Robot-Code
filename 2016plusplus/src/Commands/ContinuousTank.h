#ifndef ContinuousTank_H
#define ContinuousTank_H

#include "../CommandBase.h"
#include "WPILib.h"

class ContinuousTank: public CommandBase
{
public:
	ContinuousTank();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

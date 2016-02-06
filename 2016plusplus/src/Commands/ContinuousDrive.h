#ifndef ContinuousDrive_H
#define ContinuousDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class ContinuousDrive: public CommandBase
{
private:
//	Joystick *stick;
public:
	ContinuousDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

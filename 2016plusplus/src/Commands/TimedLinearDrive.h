#ifndef TimedLinearDrive_H
#define TimedLinearDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

enum LinearDirection {
	forward = 0,
	backward = 1
};


class TimedLinearDrive: public CommandBase
{
private:
	LinearDirection dir;
public:
	TimedLinearDrive(double timeout, LinearDirection direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

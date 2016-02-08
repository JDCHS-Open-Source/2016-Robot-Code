#ifndef CTTurn_H
#define CTTurn_H

#include "../CommandBase.h"
#include "WPILib.h"

enum TurnDirection {
	rightForw = 0,
	rightRev = 1,
	leftForw = 2,
	leftRev = 3
};


class CTTurn: public CommandBase
{
private:
	TurnDirection dir;
	float power;
public:
	CTTurn(TurnDirection d, float p);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

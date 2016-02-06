#ifndef ContinuousSetPower_H
#define ContinuousSetPower_H

#include "../CommandBase.h"
#include "WPILib.h"

class ContinuousSetPower: public CommandBase
{
private:
	float sliderToPower(float slider);
	float powerToSlider(float power);
public:
	ContinuousSetPower();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

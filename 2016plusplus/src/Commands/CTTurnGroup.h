#ifndef CTTurnGroup_H
#define CTTurnGroup_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "CTTurn.h"

class CTTurnGroup: public CommandGroup
{
public:
	CTTurnGroup(TurnDirection dir);
};

#endif

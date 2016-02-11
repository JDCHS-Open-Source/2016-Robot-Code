#include "CTTurnGroup.h"
#include "CTTurn.h"

CTTurnGroup::CTTurnGroup(TurnDirection dir)
{
	AddSequential(new CTTurn(dir, 0.1, 2));
	AddSequential(new CTTurn(dir, 0.4, 0.3));
	AddSequential(new CTTurn(dir, 0.6, 0.3));
	AddSequential(new CTTurn(dir, 0.8, 0.3));
	AddSequential(new CTTurn(dir, 1));
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}

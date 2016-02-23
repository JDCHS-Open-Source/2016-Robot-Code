#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/BasicAuto.h"
#include "Commands/RampUpAuto.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *chooser;

	void RobotInit()
	{
		CommandBase::init();

		chooser = new SendableChooser();
		chooser->AddDefault("Rough Terrain, Moat", new TimedLinearDrive(2.0,0.5,forward));
		chooser->AddObject("Rock Wall, Ramparts", new RampUpAuto());
		chooser->AddObject("LowBar", new BasicAuto());
		SmartDashboard::PutData("Auto Mode", chooser);

		autonomousCommand = new BasicAuto();
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autonomousCommand = (Command *) chooser->GetSelected();
		autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);


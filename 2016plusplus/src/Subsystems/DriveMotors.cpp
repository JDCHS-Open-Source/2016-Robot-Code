#include "DriveMotors.h"
#include "../RobotMap.h"
#include "../Commands/ContinuousDrive.h"
#include "../Commands/ContinuousTank.h"
#include "../Commands/ContinuousSetPower.h"

DriveMotors::DriveMotors() :
		Subsystem("DriveMotors")
{
	leftFront = new Talon(LEFTFRONT);
	rightFront = new Talon(RIGHTFRONT);
 	leftBack = new Talon(LEFTBACK);
	rightBack = new Talon(RIGHTBACK);
	drive = new RobotDrive(leftFront, leftBack, rightFront, rightBack);
	//drive->SetInvertedMotor(1, true);
	//drive->SetInvertedMotor(3, true);
}

void DriveMotors::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	Command *c = new ContinuousDrive();
	SetDefaultCommand(c);
}

void DriveMotors::DriveForward(float power)
{
	leftFront->Set(power);
	rightFront->Set(-power);
	leftBack->Set(power);
	rightBack->Set(-power);
}

void DriveMotors::DriveBackward(float power)
{
	leftFront->Set(power);
	rightFront->Set(-power);
	leftBack->Set(power);
	rightBack->Set(-power);
}

void DriveMotors::Stop()
{
	leftFront->Set(0);
	rightFront->Set(0);
	leftBack->Set(0);
	rightBack->Set(0);
}

void DriveMotors::ArcadeDrive(float x, float y)
{
	drive->ArcadeDrive(-y,-x,true);
}

void DriveMotors::TankDrive(float left, float right)
{
	drive->TankDrive(left, right);
}

void DriveMotors::Set(float fL, float fR, float bL, float bR)
{
	leftFront->Set(fL);
	rightFront->Set(fR);
	leftBack->Set(bL);
	rightBack->Set(bR);
}

//void DriveMotors::SetTurn(TurnDirection direction, float front, float back)
//{
//	switch (direction) {
//	case leftRev:
//		leftFront->Set(-1);
//		leftBack->Set(-0.5);
//		break;
//	case rightForw:
//		rightFront->Set(-0.5);
//		rightBack->Set(-1);
//		break;
//	case rightRev:
//		rightFront->Set(1);
//		rightBack->Set(0.5);
//		break;
//	case leftForw:
//		leftFront->Set(0.5);
//		leftBack->Set(1);
//		break;
//	}
//}
//// Put methods for controlling this subsystem
// here. Call these from Commands.

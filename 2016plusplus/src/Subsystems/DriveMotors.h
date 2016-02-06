#ifndef DriveMotors_H
#define DriveMotors_H

#include "Commands/Subsystem.h"
#include "../Commands/CTTurn.h"
#include "WPILib.h"

class DriveMotors: public Subsystem
{
private:
	Talon *leftFront;
	Talon *rightFront;
	Talon *leftBack;
	Talon *rightBack;
	RobotDrive *drive;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveMotors();
	void InitDefaultCommand();
	void DriveForward();
	void DriveBackward();
	void Stop();
	void ArcadeDrive(float x, float y);
	void TankDrive(float left, float right);
	void Set(float fL, float fR, float bL, float bR);
	void SetTurn(TurnDirection d, float front, float back);
};

#endif

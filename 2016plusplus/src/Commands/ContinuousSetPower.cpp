#include "ContinuousSetPower.h"

ContinuousSetPower::ContinuousSetPower()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

float ContinuousSetPower::powerToSlider(float power)
{
	return (power + 1) *5/2;
}

float ContinuousSetPower::sliderToPower(float slider)
{
	return (slider *2/5) - 1;
}

// Called just before this Command runs the first time
void ContinuousSetPower::Initialize()
{
	chassis->Stop();
	float zero = powerToSlider(0.0);
	SmartDashboard::PutNumber("DB/Slider 0", zero);
	SmartDashboard::PutNumber("DB/Slider 1", zero);
	SmartDashboard::PutNumber("DB/Slider 2", zero);
	SmartDashboard::PutNumber("DB/Slider 3", zero);
}

// Called repeatedly when this Command is scheduled to run
void ContinuousSetPower::Execute()
{
	float frontL = sliderToPower((float) SmartDashboard::GetNumber("DB/Slider 0", powerToSlider(0.0)));
	float frontR = sliderToPower((float) SmartDashboard::GetNumber("DB/Slider 1", powerToSlider(0.0)));
	float backL =sliderToPower( (float) SmartDashboard::GetNumber("DB/Slider 2", powerToSlider(0.0)));
	float backR = sliderToPower((float) SmartDashboard::GetNumber("DB/Slider 3", powerToSlider(0.0)));
	chassis->Set(frontL, frontR, backL, backR);
}

// Make this return true when this Command no longer needs to run execute()
bool ContinuousSetPower::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ContinuousSetPower::End()
{
	chassis->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ContinuousSetPower::Interrupted()
{
	End();
}

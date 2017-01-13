#include "stdafx.h"
#include "ControlCar.h"
#include "Car.h"

using namespace std::placeholders;

CControlCar::CControlCar(CCar & car, istream & input, ostream & output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ 
			{ "Info", bind(&CControlCar::Info, this, _1) },
			{ "EngineOn", bind(&CControlCar::EngineOn, this, _1) },
			{ "EngineOff", bind(&CControlCar::EngineOff, this, _1) },
			{ "SetGear", bind(&CControlCar::SetGear, this, _1) },
			{ "SetSpeed", bind(&CControlCar::SetSpeed, this, _1) }
		})
{
}

bool CControlCar::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CControlCar::Info(istream & args)
{
	string info;
	if (m_car.IsTurnedOn())
	{
		info += "Engine is turned on\n";
	}
	else
	{
		info += "Engine is turned off\n";
	}

	info += "Car ";

	if (m_car.GetDirection() == Direction::BACK)
	{
		info += "moves back\n";
	}
	else if (m_car.GetDirection() == Direction::STANDING_STILL)
	{
		info += "standing still\n";
	}
	else if (m_car.GetDirection() == Direction::FORWARD)
	{
		info += "moves forward\n";
	}

	info += "Speed " + to_string(m_car.GetSpeed()) + " km/h\n";

	info += to_string(m_car.GetGear()) + " gear\n";
	
	m_output << info;
	return true;
}

bool CControlCar::EngineOn(istream & args)
{
	if (m_car.TurnOnEngine())
	{
		m_output << "Engine is turned on\n";
	}
	else
	{
		m_output << "Could not start the engine\n";
	}
	return true;
}

bool CControlCar::EngineOff(istream & args)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine is turned off\n";
	}
	else
	{
		m_output << "Could not turn off the engine\n";
	}
	return true;
}

bool CControlCar::SetGear(istream & args)
{
	string info;

	int gear;
	args >> gear;

	if (!m_car.SetGear(gear))
	{
		info = "Could not enable gear\n";
	}
	else
	{
		info = "Enabled " + to_string(gear) + " gear\n";
	}

	m_output << info;
	return true;
}

bool CControlCar::SetSpeed(istream & args)
{
	string info;

	int speed;
	args >> speed;

	if (!m_car.SetSpeed(speed))
	{
		info = "Failed to set the speed\n";
	}
	else
	{
		info = "Speed is changed, it is now " + to_string(speed) + " km/h\n";
	}

	m_output << info;
	return true;
}
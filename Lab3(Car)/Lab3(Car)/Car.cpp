#include "stdafx.h"
#include "Car.h"

CCar::CCar()
{
	bool m_isOn = false;
	Gear m_gear = Gear::NEUTRAL;
	int m_speed = 0;
	Direction m_direction = Direction::STANDING_STILL;
}

bool CCar::IsTurnedOn() const
{
	return m_isOn;
}

Direction CCar::GetDirection() const
{
	return m_direction;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

Gear CCar::GetGear() const
{
	return m_gear;
}

bool CCar::TurnOnEngine()
{
	if (m_isOn)
	{
		return false;
	}
	m_isOn = true;
	return true;
}

bool CCar::TurnOffEngine()
{
	if (!m_isOn || !(m_speed == 0 && m_gear == Gear::NEUTRAL))
	{
		return false;
	}
	m_isOn = false;
	return true;
}

bool CCar::SetGear(int gear)
{	
	auto rangeSpeedForGear = SpeedRangeForGears.find(gear);

	if (rangeSpeedForGear == SpeedRangeForGears.end() ||
		!m_isOn && gear != 0 ||
		m_speed < rangeSpeedForGear->second.minSpeed || m_speed > rangeSpeedForGear->second.maxSpeed ||
		gear < 0 && m_direction == Direction::FORWARD ||
		gear > 0 && m_direction == Direction::BACK)
	{
		return false;
	}
	m_gear = static_cast<Gear>(gear);
	return true;
}

bool CCar::SetSpeed(int speed)
{
	auto rangeSpeedForGear = SpeedRangeForGears.find(m_gear);

	if (rangeSpeedForGear == SpeedRangeForGears.end() ||
		!m_isOn ||
		speed < 0 ||
		m_gear == Gear::NEUTRAL && speed > m_speed ||
		speed < rangeSpeedForGear->second.minSpeed || speed > rangeSpeedForGear->second.maxSpeed)
	{
		return false;
	}

	m_speed = speed;

	if (m_speed > 0)
	{
		if (m_gear == Gear::REAR)
		{
			m_direction = Direction::BACK;
		}
		else if (m_gear != Gear::NEUTRAL)
		{
			m_direction = Direction::FORWARD;
		}
	}
	else
	{
		m_direction = Direction::STANDING_STILL;
	}

	return true;
}

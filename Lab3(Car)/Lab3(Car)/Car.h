#pragma once

#include <map>

using namespace std;

const int MIN_SPEED = 0;
const int MAX_SPEED = 150;

struct RangeSpeed
{
	int minSpeed;
	int maxSpeed;
};

enum Gear {REAR = -1, NEUTRAL, FIRST, SECOND, THIRD, FOURTH, FIFTH};

enum Direction {BACK = -1, STANDING_STILL, FORWARD};

class CCar
{
public:
	CCar();
	bool IsTurnedOn()const;
	Direction GetDirection()const;
	int GetSpeed()const;
	Gear GetGear()const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	~CCar() = default;
private:
	map <int, RangeSpeed> SpeedRangeForGears
	{
		{-1, {MIN_SPEED, 20}},
		{0, {MIN_SPEED, MAX_SPEED}},
		{1, {MIN_SPEED, 30}},
		{2, {20, 50}},
		{3, {30, 60}},
		{4, {40, 90}},
		{5, {50, MAX_SPEED}},
	};
	bool m_isOn = false;
	Gear m_gear = Gear::NEUTRAL;
	int m_speed = 0;
	Direction m_direction = Direction::STANDING_STILL;
};


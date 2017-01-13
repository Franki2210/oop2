#pragma once
#include <boost/noncopyable.hpp>

using namespace std;

class CCar;

class CControlCar : boost::noncopyable
{
public:
	CControlCar(CCar & car, istream & input, ostream & output);
	bool HandleCommand();
private:
	bool Info(istream & args);
	bool EngineOn(istream & args);
	bool EngineOff(istream & args);
	bool SetGear(istream & args);
	bool SetSpeed(istream & args);

	typedef map<string, function<bool(istream & args)>> ActionMap;
	CCar & m_car;
	istream & m_input;
	ostream & m_output;
	const ActionMap m_actionMap;
};


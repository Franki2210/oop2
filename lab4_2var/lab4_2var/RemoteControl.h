#pragma once
#include "stdafx.h"
#include <boost/noncopyable.hpp>
#include "Point.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

class IShape;

class CRemoteControl : boost::noncopyable
{
public:
	CRemoteControl(ifstream & input, ostream & output);
	bool HandleCommand();
	void Info() const;
private:
	bool CreateLine(istream & args);
	bool CreateCircle(istream & args);
	bool CreateRectangle(istream & args);
	bool CreateTriangle(istream & args);
	vector<string> GetParameters(string const& shapeSpecification) const;
private:
	typedef map<string, function<bool(istream & args)>> ActionMap;
	vector<shared_ptr<IShape>> m_shapes;
	istream & m_input;
	ostream & m_output;
	const ActionMap m_actionMap;
};
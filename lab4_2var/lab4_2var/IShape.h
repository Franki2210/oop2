#pragma once

using namespace std;

class IShape
{
public:
	IShape(string const& type, string const& outlineColor);
	virtual ~IShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual string ToString() const;
	string GetOutlineColor() const;
protected:
	virtual void AppendProperties(ostream & strm) const = 0;
private:
	string m_type;
	string m_outlineColor;
};


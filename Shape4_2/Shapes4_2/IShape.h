#pragma once
#include <string>
#include "ICanvasDrawable.h"

using namespace std;

class IShape: public ICanvasDrawable
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual string ToString() const = 0;
	virtual string GetOutlineColor() const = 0;
	virtual ~IShape() = default;
};
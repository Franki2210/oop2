#include "stdafx.h"
#include "RemoteControl.h"
#include "IShape.h"
#include "Color.h"

using namespace std;
using namespace placeholders;

CRemoteControl::CRemoteControl(ifstream & input, ostream & output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "Line", bind(&CRemoteControl::CreateLine, this, _1) },
		{ "Triangle", bind(&CRemoteControl::CreateTriangle, this, _1) },
		{ "Rectangle", bind(&CRemoteControl::CreateRectangle, this, _1) },
		{ "Circle", bind(&CRemoteControl::CreateCircle, this, _1) }
})
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);
	string action;
	strm >> action;
	if (strm.eof() && action.empty())
	{
		return true;
	}
	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}
	return false;
}

vector<string> CRemoteControl::GetParameters(string const& shapeSpecification) const
{
	vector<string> parameters;
	const boost::char_separator<char> delimiters(", ");
	boost::tokenizer<boost::char_separator<char>> tokenizer(shapeSpecification, delimiters);
	copy(tokenizer.begin(), tokenizer.end(), back_inserter(parameters));
	return parameters;
}

void CRemoteControl::Info() const
{
	if (!m_shapes.empty())
	{
		auto shapeWithMinPerimeter = min_element(m_shapes.begin(), m_shapes.end(), [&]
		(shared_ptr<IShape> const& firstShape, shared_ptr<IShape> const& secondShape)
		{
			return firstShape->GetPerimeter() < secondShape->GetPerimeter();
		});
		m_output << "Shape with minimum perimeter:\n";
		m_output << (*shapeWithMinPerimeter)->ToString() << "\n";

		auto shapeWithMaxArea = max_element(m_shapes.begin(), m_shapes.end(), [&]
		(shared_ptr<IShape> const& firstShape, shared_ptr<IShape> const& secondShape)
		{
			return firstShape->GetArea() < secondShape->GetArea();
		});
		m_output << "The shape with the largest area:\n";
		m_output << (*shapeWithMaxArea)->ToString() << "\n";

		m_output << "Shapes:\n";
		for (auto const& shape : m_shapes)
		{
			m_output << ">" << shape->ToString() << "\n";
		}
	}
}

bool CRemoteControl::CreateLine(istream & args)
{
	string shapeSpecification;
	getline(args, shapeSpecification);
	vector<string> parameters = GetParameters(shapeSpecification);
	if (parameters.size() != 5)
	{
		m_output << "Invalid number of parameters!!!\n"
			<< "Usage: <x1> <y1> <x2> <y2> <colorOutline>\n";
		return false;
	}
	Point startPoint, endPoint;
	try
	{
		startPoint.x = boost::lexical_cast<double>(parameters[0]);
		startPoint.y = boost::lexical_cast<double>(parameters[1]);
		endPoint.x = boost::lexical_cast<double>(parameters[2]);
		endPoint.y = boost::lexical_cast<double>(parameters[3]);
	}
	catch (boost::bad_lexical_cast const& error)
	{
		m_output << error.what() << "\n";
		return false;
	}
	Color outlineColor;
	if (HexToRGB(parameters[4], outlineColor))
	{
		m_shapes.push_back(make_shared<CLineSegment>(CLineSegment(startPoint, endPoint, parameters[4])));
		return true;
	}
	return false;
}

bool CRemoteControl::CreateCircle(istream & args)
{
	string shapeSpecification;
	getline(args, shapeSpecification);
	vector<string> parameters = GetParameters(shapeSpecification);
	if (parameters.size() != 5)
	{
		m_output << "Invalid number of parameters!!!\n"
			<< "Usage: <x1> <y1> <radius> <colorOutline> <fillColor>\n";
		return false;
	}
	Point position;
	double radius;
	try
	{
		position.x = boost::lexical_cast<double>(parameters[0]);
		position.y = boost::lexical_cast<double>(parameters[1]);
		radius = boost::lexical_cast<double>(parameters[2]);
	}
	catch (boost::bad_lexical_cast const& error)
	{
		m_output << error.what() << "\n";
		return false;
	}
	Color outlineColor;
	Color fillColor;
	if (HexToRGB(parameters[3], outlineColor) && HexToRGB(parameters[4], fillColor))
	{
		m_shapes.push_back(make_shared<CCircle>(CCircle(position, radius, parameters[3], parameters[4])));
		return true;
	}
	return false;
}

bool CRemoteControl::CreateRectangle(istream & args)
{
	string shapeSpecification;
	getline(args, shapeSpecification);
	vector<string> parameters = GetParameters(shapeSpecification);
	if (parameters.size() != 6)
	{
		m_output << "Invalid number of parameters!!!\n"
			<< "Usage: <x1> <y1> <width> <height> <colorOutline> <fillColor>\n";
		return false;
	}
	Point position;
	double width;
	double height;
	try
	{
		position.x = boost::lexical_cast<double>(parameters[0]);
		position.y = boost::lexical_cast<double>(parameters[1]);
		width = boost::lexical_cast<double>(parameters[2]);
		height = boost::lexical_cast<double>(parameters[3]);
	}
	catch (boost::bad_lexical_cast const& error)
	{
		m_output << error.what() << "\n";
		return false;
	}
	Color outlineColor;
	Color fillColor;
	if (HexToRGB(parameters[4], outlineColor) && HexToRGB(parameters[5], fillColor))
	{
		m_shapes.push_back(make_shared<CRectangle>(CRectangle(position, width, height, parameters[4], parameters[5])));
		return true;
	}
	return false;
}

bool CRemoteControl::CreateTriangle(istream & args)
{
	string shapeSpecification;
	getline(args, shapeSpecification);
	vector<string> parameters = GetParameters(shapeSpecification);
	if (parameters.size() != 8)
	{
		m_output << "Invalid number of parameters!!!\n"
			<< "Usage: <x1> <y1> <x2> <y2> <x3> <y3> <colorOutline> <fillColor>\n";
		return false;
	}
	Point vertex1;
	Point vertex2;
	Point vertex3;
	Color outlineColor;
	Color fillColor;
	if (HexToRGB(parameters[6], outlineColor) && HexToRGB(parameters[7], fillColor))
	{
		m_shapes.push_back(make_shared<CTriangle>(CTriangle(vertex1, vertex2, vertex3, parameters[6], parameters[7])));
		return true;
	}
	return false;
}
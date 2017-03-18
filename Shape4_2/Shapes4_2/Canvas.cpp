#include "stdafx.h"
#include "Canvas.h"

#define _USE_MATH_DEFINES
#include "math.h"

CCanvas::CCanvas(sf::VideoMode videoMode, sf::String windowTitle)
{
	m_window.create(videoMode, windowTitle);
}

void CCanvas::AddShapes(std::vector<std::shared_ptr<IShape>> const& shapes)
{
	for (auto shape : shapes)
	{
		shape->Draw(*this);
	}
}

void CCanvas::DrawShapes()
{
	sf::RenderStates states;
	draw(m_window, states);
}

void CCanvas::DrawLine(CPoint const& startPoint, CPoint const& endPoint, sf::Color const& outlineColor)
{
	sf::VertexArray line(sf::Lines);
	line.append(sf::Vertex(sf::Vector2f(float(startPoint.x), float(startPoint.y)), outlineColor));
	line.append(sf::Vertex(sf::Vector2f(float(endPoint.x), float(endPoint.y)), outlineColor));
	m_shapes.push_back(line);
}

void CCanvas::FillPolygon(std::vector<CPoint> const vertices, sf::Color const& fillColor)
{
	sf::VertexArray polygon;
	polygon.resize(vertices.size());
	if (vertices.size() == 3)
	{
		polygon.setPrimitiveType(sf::Triangles);
	}
	else if (vertices.size() == 4)
	{
		polygon.setPrimitiveType(sf::Quads);
	}
	for (size_t i = 0; i < polygon.getVertexCount(); ++i)
	{
		polygon[i].position = sf::Vector2f(float(vertices[i].x), float(vertices[i].y));
		polygon[i].color = fillColor;
	}
	m_shapes.push_back(polygon);
}

void CCanvas::DrawCircle(CPoint const& center, double radius, sf::Color const& outlineColor)
{
	double angle = 0;
	sf::VertexArray circle;
	circle.setPrimitiveType(sf::TrianglesFan);
	for (size_t i = 0; i < 7 * radius; ++i)
	{
		circle.append(sf::Vertex(sf::Vector2f(float(radius * cos(angle) + center.x), float(radius * sin(angle) + center.y)), outlineColor));
		angle = angle + ((2 * M_PI) / (7 * radius));
	}
	m_shapes.push_back(circle);
}

void CCanvas::DrawInnerCircle(CPoint const& center, double radius)
{
	double angle = 0;
	sf::VertexArray circle;
	circle.setPrimitiveType(sf::TrianglesFan);
	for (size_t i = 0; i < 7 * radius; ++i)
	{
		circle.append(sf::Vertex(sf::Vector2f(float((radius - 1) * cos(angle) + center.x), float((radius - 1) * sin(angle) + center.y))));
		angle = angle + ((2 * M_PI) / (7 * radius));
	}
	m_shapes.push_back(circle);
}

void CCanvas::FillCircle(CPoint const& center, double radius, sf::Color const& fillColor)
{
	DrawInnerCircle(center, radius);
	for (size_t i = 0; i < m_shapes[m_shapes.size() - 1].getVertexCount(); ++i)
	{
		m_shapes[m_shapes.size() - 1][i].color = fillColor;
	}
}

void CCanvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto shape : m_shapes)
	{
		target.draw(shape);
	}
}

bool CCanvas::IsOpen() const
{
	return m_window.isOpen();
}

void CCanvas::Clear(sf::Color color)
{
	m_window.clear(color);
}

void CCanvas::Display()
{
	m_window.display();
}

bool CCanvas::PollEvent(sf::Event &event)
{
	return m_window.pollEvent(event);
}

void CCanvas::Close()
{
	return m_window.close();
}
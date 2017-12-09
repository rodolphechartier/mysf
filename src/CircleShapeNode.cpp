#include "CircleShapeNode.hpp"

namespace mysf
{
	CircleShapeNode::CircleShapeNode(float radius, std::size_t pointCount)
		: ShapeNode(_circle)
		, _circle(radius, pointCount)
	{

	}

	CircleShapeNode::~CircleShapeNode()
	{

	}

	void CircleShapeNode::setRadius(float radius)
	{
		_circle.setRadius(radius);
	}

	float CircleShapeNode::getRadius() const
	{
		return _circle.getRadius();
	}

	void CircleShapeNode::setPointCount(std::size_t count)
	{
		_circle.setPointCount(count);
	}

	std::size_t CircleShapeNode::getPointCount() const
	{
		return _circle.getPointCount();
	}

	sf::Vector2f CircleShapeNode::getPoint(std::size_t index) const
	{
		return _circle.getPoint(index);
	}

	void CircleShapeNode::updateCurrent(const sf::Time & /* deltaTime */, const Event & /* event */)
	{

	}

	void CircleShapeNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(_circle, states);
	}
}

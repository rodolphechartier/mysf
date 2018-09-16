#include "ConvexShapeNode.hpp"

namespace mysf
{
	ConvexShapeNode::ConvexShapeNode(std::size_t pointCount)
		: ShapeNode(_convex)
		, _convex(pointCount)
	{

	}

	ConvexShapeNode::~ConvexShapeNode()
	{

	}

	void ConvexShapeNode::setPointCount(std::size_t count)
	{
		_convex.setPointCount(count);
	}

	void ConvexShapeNode::setPoint(std::size_t index, const sf::Vector2f & point)
	{
		_convex.setPoint(index, point);
	}

	std::size_t ConvexShapeNode::getPointCount() const
	{
		return _convex.getPointCount();
	}

	sf::Vector2f ConvexShapeNode::getPoint(std::size_t index) const
	{
		return _convex.getPoint(index);
	}
}

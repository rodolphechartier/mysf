#include "RectangleShapeNode.hpp"

namespace mysf
{
	RectangleShapeNode::RectangleShapeNode(const sf::Vector2f & size)
		: ShapeNode(_rectangle)
		, _rectangle(size)
	{

	}

	RectangleShapeNode::~RectangleShapeNode()
	{

	}

	void RectangleShapeNode::setSize(const sf::Vector2f & size)
	{
		_rectangle.setSize(size);
	}

	const sf::Vector2f & RectangleShapeNode::getSize() const
	{
		return _rectangle.getSize();
	}

	std::size_t RectangleShapeNode::getPointCount() const
	{
		return _rectangle.getPointCount();
	}

	sf::Vector2f RectangleShapeNode::getPoint(std::size_t index) const
	{
		return _rectangle.getPoint(index);
	}
}

#include "ShapeNode.hpp"

namespace mysf
{
	ShapeNode::ShapeNode(sf::Shape & shape)
		: _shape(shape)
	{

	}

	ShapeNode::~ShapeNode()
	{

	}

	void ShapeNode::setTexture(const sf::Texture * texture, bool resetRect)
	{
		_shape.setTexture(texture, resetRect);
	}

	void ShapeNode::setTextureRect(const sf::IntRect & rect)
	{
		_shape.setTextureRect(rect);
	}

	void ShapeNode::setFillColor(const sf::Color & color)
	{
		_shape.setFillColor(color);
	}

	void ShapeNode::setOutlineColor(const sf::Color & color)
	{
		_shape.setOutlineColor(color);
	}

	void ShapeNode::setOutlineThickness(float thickness)
	{
		_shape.setOutlineThickness(thickness);
	}

	const sf::Texture * ShapeNode::getTexture() const
	{
		return _shape.getTexture();
	}

	const sf::IntRect & ShapeNode::getTextureRect() const
	{
		return _shape.getTextureRect();
	}

	const sf::Color & ShapeNode::getFillColor() const
	{
		return _shape.getFillColor();
	}

	const sf::Color & ShapeNode::getOutlineColor() const
	{
		return _shape.getOutlineColor();
	}

	float ShapeNode::getOutlineThickness() const
	{
		return _shape.getOutlineThickness();
	}

	std::size_t ShapeNode::getPointCount() const
	{
		return _shape.getPointCount();
	}

	sf::Vector2f ShapeNode::getPoint(std::size_t index) const
	{
		return _shape.getPoint(index);
	}

	sf::FloatRect ShapeNode::getLocalBounds() const
	{
		return _shape.getLocalBounds();
	}

	sf::FloatRect ShapeNode::getGlobalBounds() const
	{
		return _shape.getGlobalBounds();
	}

	void ShapeNode::updateCurrent(const sf::Time & /* deltaTime */, const Event & /* event */)
	{

	}

	void ShapeNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(_shape, states);
	}
}

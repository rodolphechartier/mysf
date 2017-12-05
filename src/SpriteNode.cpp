#include "SpriteNode.hpp"

namespace mysf
{
  SpriteNode::SpriteNode()
  {

  }

  SpriteNode::SpriteNode(const sf::Texture & texture)
    : _sprite(texture)
  {

  }

  SpriteNode::SpriteNode(const sf::Texture & texture, const sf::IntRect & rectangle)
    : _sprite(texture, rectangle)
  {

  }

  SpriteNode::~SpriteNode()
  {

  }

  void SpriteNode::setTexture(const sf::Texture & texture, bool resetRect)
  {
    _sprite.setTexture(texture, resetRect);
  }

  void SpriteNode::setTextureRect(const sf::IntRect & rectangle)
  {
    _sprite.setTextureRect(rectangle);
  }

  void SpriteNode::setColor(const sf::Color & color)
  {
    _sprite.setColor(color);
  }

  const sf::Texture * SpriteNode::getTexture() const
  {
    return _sprite.getTexture();
  }

  const sf::IntRect & SpriteNode::getTextureRect() const
  {
    return _sprite.getTextureRect();
  }

  void SpriteNode::setSize(const sf::Vector2f & size)
  {
	const sf::Vector2f & currSize(getSize());

	if (currSize.x && currSize.y)
	  setScale(sf::Vector2f(size.x / currSize.x, size.y / currSize.y));
  }

  sf::Vector2f SpriteNode::getSize() const
  {
	const sf::FloatRect & rect(getLocalBounds());

	return sf::Vector2f(rect.width, rect.height);
  }

  const sf::Color & SpriteNode::getColor() const
  {
    return _sprite.getColor();
  }

  sf::FloatRect SpriteNode::getLocalBounds() const
  {
    return _sprite.getLocalBounds();
  }

  sf::FloatRect SpriteNode::getGlobalBounds() const
  {
    return getTransform().transformRect(getLocalBounds());
  }

  void SpriteNode::updateCurrent(const sf::Time & /* deltaTime */, const Event & /* event */)
  {

  }

  void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
  {
    target.draw(_sprite, states);
  }
}

#include "SpriteNode.hpp"

namespace mysf
{
  SpriteNode::SpriteNode()
    : SceneNode()
		, _texture(0)
  {

  }

  SpriteNode::SpriteNode(const sf::Texture & texture)
    : SceneNode()
		, _texture(0)
  {
		setTexture(texture);
  }

  SpriteNode::SpriteNode(const sf::Texture & texture, const sf::IntRect & rectangle)
    : SceneNode()
		, _texture(0)
  {
		setTexture(texture);
		setTextureRect(rectangle);
  }

  SpriteNode::~SpriteNode()
  {

  }

  void SpriteNode::setTexture(const sf::Texture & texture, bool resetRect)
	{
		if (resetRect || (!_texture && (_textureRect == sf::IntRect())))
      setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
    _texture = &texture;
	}

  void SpriteNode::setTextureRect(const sf::IntRect & rectangle)
	{
		if (_textureRect != rectangle)
    {
        _textureRect = rectangle;
        _updatePositions();
        _updateTexCoords();
    }
	}

  void SpriteNode::setColor(const sf::Color & color)
	{
    _vertices[0].color = color;
    _vertices[1].color = color;
    _vertices[2].color = color;
    _vertices[3].color = color;
	}

  const sf::Texture * SpriteNode::getTexture() const
	{
    return _texture;
	}

  const sf::IntRect & SpriteNode::getTextureRect() const
	{
    return _textureRect;
	}

  const sf::Color & SpriteNode::getColor() const
	{
		return _vertices[0].color;
	}

  sf::FloatRect SpriteNode::getLocalBounds() const
	{
		const float width = static_cast<float>(std::abs(_textureRect.width));
    const float height = static_cast<float>(std::abs(_textureRect.height));

    return sf::FloatRect(0.f, 0.f, width, height);
	}

  sf::FloatRect SpriteNode::getGlobalBounds() const
	{
		const float width = static_cast<float>(std::abs(_textureRect.width));
    const float height = static_cast<float>(std::abs(_textureRect.height));

		return sf::FloatRect(getWorldPosition(), sf::Vector2f(width, height));
	}

  void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
  {
    if (_texture)
      states.texture = _texture;
  	target.draw(_vertices, 4, sf::TriangleStrip, states);
  }

	void SpriteNode::_updatePositions()
	{
		sf::FloatRect bounds = getLocalBounds();

    _vertices[0].position = sf::Vector2f(0.f, 0.f);
    _vertices[1].position = sf::Vector2f(0.f, bounds.height);
    _vertices[2].position = sf::Vector2f(bounds.width, 0.f);
    _vertices[3].position = sf::Vector2f(bounds.width, bounds.height);
	}

	void SpriteNode::_updateTexCoords()
	{
		const float left   = static_cast<float>(_textureRect.left);
    const float right  = left + _textureRect.width;
    const float top    = static_cast<float>(_textureRect.top);
    const float bottom = top + _textureRect.height;

    _vertices[0].texCoords = sf::Vector2f(left, top);
    _vertices[1].texCoords = sf::Vector2f(left, bottom);
    _vertices[2].texCoords = sf::Vector2f(right, top);
    _vertices[3].texCoords = sf::Vector2f(right, bottom);
	}
}

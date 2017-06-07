#include "AnimSprite.hpp"

namespace mysf
{
	AnimSprite::AnimSprite()
		: _size(1, 1)
		, _speed(sf::seconds(1.f))
	{

	}

	AnimSprite::AnimSprite(const sf::Texture & texture)
		: _size(1, 1)
		, _speed(sf::seconds(1.f))
	{
		setTexture(texture);
	}

	AnimSprite::AnimSprite(const sf::Texture & texture, const sf::IntRect & rectangle)
		: _size(1, 1)
		, _speed(sf::seconds(1.f))
	{
		setTexture(texture);
		setTextureRect(rectangle);
	}

	void AnimSprite::setTexture(const sf::Texture & texture, bool resetRect)
	{
		if (resetRect || (!_texture && (_textureRect == sf::IntRect())))
      _textureRect = sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y);
    _texture = &texture;
		update();
	}

	void AnimSprite::setTextureRect(const sf::IntRect & rectangle)
	{
		if (_textureRect != rectangle)
		{
			_textureRect = rectangle;
			update();
		}
	}

	void AnimSprite::setColor(const sf::Color & color)
	{
		_color = color;
		for (unsigned int i = 0; i < _sprites.size(); ++i)
			_sprites[i].setColor(_color);
	}

	void AnimSprite::setSize(unsigned int x, unsigned int y)
	{
		setSize(sf::Vector2u(x, y));
	}

	void AnimSprite::setSize(const sf::Vector2u & size)
	{
		if (_size != size)
		{
			_size = size;
			update();
		}
	}

	void AnimSprite::setMargin(unsigned int x, unsigned int y)
	{
		setMargin(sf::Vector2u(x, y));
	}

	void AnimSprite::setMargin(const sf::Vector2u & margin)
	{
		if (_margin != margin)
		{
			_margin = margin;
			update();
		}
	}

	void AnimSprite::setSpeed(const sf::Time & speed)
	{
		_speed = speed;
	}

	const sf::Texture * AnimSprite::getTexture() const
	{
		return _texture;
	}

	const sf::IntRect & AnimSprite::getTextureRect() const
	{
		return _textureRect;
	}

	const sf::Color & AnimSprite::getColor() const
	{
		return _color;
	}

	sf::FloatRect AnimSprite::getLocalBounds() const
	{
		// TODO
	}

	sf::FloatRect AnimSprite::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}

	const sf::Vector2u & AnimSprite::getSize() const
	{
		return _size;
	}

	const sf::Vector2u & AnimSprite::getMargin() const
	{
		return _margin;
	}

	const sf::Time & AnimSprite::getSpeed() const
	{
		return _speed;
	}

	void AnimSprite::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		static sf::Time timer;

		for (timer += _clock.restart(); timer >= _speed; timer -= _speed)
			_index = (_index + 1) % _sprites.size();
		target.draw(_sprites[_index], states);
	}

	void AnimSprite::update()
	{
		_sprites.resize(_size.x * _size.y);
		for (unsigned int i = 0; i < _sprites.size(); ++i)
		{
			sf::IntRect rectangle;

			// no margin
			rectangle.width = _textureRect.width / (_size.x ? _size.x : 1);
			rectangle.height = _textureRect.height / (_size.y ? _size.y : 1);
			rectangle.left = rectangle.width * (i % (_size.x ? _size.x : 1));
			rectangle.top = rectangle.height * (i / (_size.y ? _size.y : 1));

			_sprites[i].setTexture(_texture);
			_sprites[i].setTextureRect(rectangle);
			_sprites[i].setColor(_color);
		}
	}
}

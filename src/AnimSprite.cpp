#include "AnimSprite.hpp"

namespace mysf
{
	const sf::Clock AnimSprite::_clock;

	AnimSprite::AnimSprite(unsigned int nb)
		: _texture(0)
		, _speed(sf::seconds(1.f))
		, _sprites(nb > 0 ? nb : 1)
		, _index(0)
	{

	}

	AnimSprite::AnimSprite(const sf::Texture & texture, unsigned int nb)
		: _speed(sf::seconds(1.f))
		, _sprites(nb > 0 ? nb : 1)
		, _index(0)
	{
		setTexture(texture);
	}

	AnimSprite::AnimSprite(const sf::Texture & texture, const sf::IntRect & rectangle, unsigned int nb)
		: _speed(sf::seconds(1.f))
		, _sprites(nb > 0 ? nb : 1)
		, _index(0)
	{
		setTexture(texture);
		setTextureRect(rectangle);
	}

	void AnimSprite::setTexture(const sf::Texture & texture, bool resetRect)
	{
		if (resetRect || (!_texture && (_textureRect == sf::IntRect())))
      _textureRect = sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y);
    _texture = &texture;
		for (unsigned int i = 0; i < _sprites.size(); ++i)
			_sprites[i].setTexture(*_texture);
	}

	void AnimSprite::setTextureRect(const sf::IntRect & rectangle)
	{
		if (_textureRect != rectangle)
		{
			_textureRect = rectangle;
			update();
		}
	}

	void AnimSprite::setNumber(unsigned int nb)
	{
		_sprites.resize(nb > 0 ? nb : 1);
		update();
	}

	void AnimSprite::setColor(const sf::Color & color)
	{
		_color = color;
		for (unsigned int i = 0; i < _sprites.size(); ++i)
			_sprites[i].setColor(_color);
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

	unsigned int AnimSprite::getNumber() const
	{
		return _sprites.size();
	}

	const sf::Color & AnimSprite::getColor() const
	{
		return _color;
	}

	const sf::Time & AnimSprite::getSpeed() const
	{
		return _speed;
	}

	sf::FloatRect AnimSprite::getLocalBounds() const
	{
		return _sprites[_index].getLocalBounds();
	}

	sf::FloatRect AnimSprite::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}

	void AnimSprite::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		static sf::Time timer;

		while (timer < _clock.getElapsedTime())
		{
			_index = (_index + 1) % _sprites.size();
			timer += _speed;
		}
		target.draw(_sprites[_index], states);
	}

	void AnimSprite::update()
	{
		const unsigned int size = _textureRect.width / _sprites.size();

		for (unsigned int i = 0; i < _sprites.size(); ++i)
		{
			sf::IntRect rectangle(_textureRect);

			rectangle.left += i * size;
			rectangle.width = size;
			_sprites[i].setTextureRect(rectangle);
		}
	}
}

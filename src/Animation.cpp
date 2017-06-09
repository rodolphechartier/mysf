#include "Animation.hpp"

namespace mysf
{
	const sf::Clock Animation::_clock;

	Animation::Animation(unsigned int nb)
		: _texture(0)
		, _speed(sf::seconds(1.f))
		, _sprites(nb > 0 ? nb : 1)
		, _index(0)
		, _isPaused(true)
	{

	}

	Animation::Animation(const sf::Texture & texture, unsigned int nb)
		: _speed(sf::seconds(1.f))
		, _sprites(nb > 0 ? nb : 1)
		, _index(0)
		, _isPaused(true)
	{
		setTexture(texture);
	}

	Animation::Animation(const sf::Texture & texture, const sf::IntRect & rectangle, unsigned int nb)
		: _speed(sf::seconds(1.f))
		, _sprites(nb > 0 ? nb : 1)
		, _index(0)
		, _isPaused(true)
	{
		setTexture(texture);
		setTextureRect(rectangle);
	}

	void Animation::setTexture(const sf::Texture & texture, bool resetRect)
	{
		if (resetRect || (!_texture && (_textureRect == sf::IntRect())))
      _textureRect = sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y);
    _texture = &texture;
		for (unsigned int i = 0; i < _sprites.size(); ++i)
			_sprites[i].setTexture(*_texture);
	}

	void Animation::setTextureRect(const sf::IntRect & rectangle)
	{
		if (_textureRect != rectangle)
		{
			_textureRect = rectangle;
			update();
		}
	}

	void Animation::setNumber(unsigned int nb)
	{
		_sprites.resize(nb > 0 ? nb : 1);
		update();
	}

	void Animation::setColor(const sf::Color & color)
	{
		_color = color;
		for (unsigned int i = 0; i < _sprites.size(); ++i)
			_sprites[i].setColor(_color);
	}

	void Animation::setSpeed(const sf::Time & speed)
	{
		_speed = speed;
	}

	const sf::Texture * Animation::getTexture() const
	{
		return _texture;
	}

	const sf::IntRect & Animation::getTextureRect() const
	{
		return _textureRect;
	}

	unsigned int Animation::getNumber() const
	{
		return _sprites.size();
	}

	const sf::Color & Animation::getColor() const
	{
		return _color;
	}

	const sf::Time & Animation::getSpeed() const
	{
		return _speed;
	}

	void Animation::reset()
	{
		_index = 0;
		_isPaused = true;
	}

	sf::FloatRect Animation::getLocalBounds() const
	{
		return _sprites[_index].getLocalBounds();
	}

	sf::FloatRect Animation::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}

	void Animation::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		static sf::Time timer;

		if (_isPaused)
		{
			timer = _clock.getElapsedTime();
			_isPaused = false;
		}
		else while (timer < _clock.getElapsedTime())
		{
			_index = (_index + 1) % _sprites.size();
			timer += _speed;
		}
		target.draw(_sprites[_index], states);
	}

	void Animation::update()
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

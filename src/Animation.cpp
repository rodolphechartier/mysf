#include "Animation.hpp"

namespace mysf
{
	Animation::Animation(unsigned int nb)
		: _texture(0)
		, _speed(sf::seconds(0.2f))
		, _isPlaying(false)
		, _isLooped(true)
		, _sprites(nb > 0 ? nb : 1)
		, _index(0)
	{

	}

	Animation::Animation(const sf::Texture & texture, unsigned int nb)
		: _speed(sf::seconds(0.2f))
		, _isPlaying(false)
		, _isLooped(true)
		, _sprites(nb > 0 ? nb : 1)
		, _index(0)
	{
		setTexture(texture);
	}

	Animation::Animation(const sf::Texture & texture, const sf::IntRect & rectangle, unsigned int nb)
		: _speed(sf::seconds(0.2f))
		, _isPlaying(false)
		, _isLooped(true)
		, _sprites(nb > 0 ? nb : 1)
		, _index(0)
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
			build();
		}
	}

	void Animation::setNumber(unsigned int nb)
	{
		_sprites.resize(nb > 0 ? nb : 1);
		build();
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

	void Animation::setLooped(bool isLooped)
	{
		_isLooped = isLooped;
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

	bool Animation::isPlaying() const
	{
		return _isPlaying;
	}

	bool Animation::isLooped() const
	{
		return _isLooped;
	}

	sf::FloatRect Animation::getLocalBounds() const
	{
		return _sprites[_index].getLocalBounds();
	}

	sf::FloatRect Animation::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}

	void Animation::play()
	{
		_isPlaying = true;
	}

	void Animation::pause()
	{
		_isPlaying = false;
	}

	void Animation::stop()
	{
		_isPlaying = false;
		_timer = sf::Time::Zero;
		_index = 0;
	}

	void Animation::update(const sf::Time & deltaTime)
	{
		if (!_isPlaying)
			return;
		_timer += deltaTime;
		while (_timer > _speed)
		{
			++_index;
			if (!_isLooped && _index == _sprites.size())
				stop();
			else
				_index %= _sprites.size();
			_timer -= _speed;
		}
	}

	void Animation::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(_sprites[_index], states);
	}

	void Animation::build()
	{
		const float size = _textureRect.width / _sprites.size();
		sf::FloatRect rectangle(_textureRect);

		rectangle.width = size;
		for (unsigned int i = 0; i < _sprites.size(); ++i)
		{
			_sprites[i].setTextureRect(sf::IntRect(rectangle));
			rectangle.left += size;
		}
	}
}

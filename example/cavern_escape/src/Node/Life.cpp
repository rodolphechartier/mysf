#include "Life.hpp"

Life::Life(unsigned int max)
	: _val(max)
	, _max(max)
{
	setFillColor(sf::Color::Green);
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(2.f);
}

Life::~Life()
{

}

void Life::add(unsigned int heal)
{
	_val = _val + heal >= _max ? _max : _val + heal;
	update();
}

void Life::sub(unsigned int damage)
{
	_val = _val <= damage ? 0 : _val - damage;
	update();
}

unsigned int Life::getValue() const
{
	return _val;
}

unsigned int Life::getMax() const
{
	return _max;
}

float Life::getRatio() const
{
	return static_cast<float>(_val) / _max;
}

Life::operator bool() const
{
	return static_cast<bool>(_val);
}

void Life::setSizeMax(const sf::Vector2f & size)
{
	_sizeMax = size;
}

const sf::Vector2f & Life::getSizeMax() const
{
	return _sizeMax;
}

void Life::update()
{
	const float ratio = getRatio();

	if (_val)
	{
		setSize(sf::Vector2f(_sizeMax.x, _sizeMax.y * ratio));
		setOrigin(getSize() / 2.f);
		setFillColor(sf::Color(255 * (1.f - ratio), 255 * ratio, 0));
	}
	else
	{
		setSize(sf::Vector2f(0.f, 0.f));
		setOutlineThickness(0.f);
	}
}

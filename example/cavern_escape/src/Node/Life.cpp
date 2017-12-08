#include "Life.hpp"

Life::Life(unsigned int max)
	: _val(max)
	, _max(max)
{
	_shape.setFillColor(sf::Color::Green);
	_shape.setOutlineColor(sf::Color::Black);
	_shape.setOutlineThickness(3.f);
}

Life::~Life()
{

}

void Life::add(unsigned int heal)
{
	float ratio;

	_val = _val + heal >= _max ? _max : _val + heal;
	ratio = static_cast<float>(_val) / _max;
	_shape.setSize(sf::Vector2f(_size.x * ratio, _size.y));
	_shape.setFillColor(sf::Color(255 * (1.f - ratio), 255 * ratio, 0));
}

void Life::sub(unsigned int damage)
{
	float ratio;

	_val = _val <= damage ? 0 : _val - damage;
	ratio = static_cast<float>(_val) / _max;
	_shape.setSize(sf::Vector2f(_size.x * ratio, _size.y));
	_shape.setFillColor(sf::Color(255 * (1.f - ratio), 255 * ratio, 0));
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

void Life::setSize(const sf::Vector2f & size)
{
	float ratio;

	_size = size;
	ratio = static_cast<float>(_val) / _max;
	_shape.setSize(sf::Vector2f(_size.x * ratio, _size.y));
}

const sf::Vector2f & Life::getSize() const
{
	return _size;
}

void Life::updateCurrent(const sf::Time & /* deltaTime */, const mysf::Event & /* event */)
{

}

void Life::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_shape, states);
}

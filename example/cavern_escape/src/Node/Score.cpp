#include "Score.hpp"

Score::Score()
	: _val(0)
{
	_text.setFillColor(sf::Color::White);
	_text.setOutlineColor(sf::Color::Black);
	_text.setOutlineThickness(2.f);
	updateText();
}

Score::~Score()
{

}

void Score::sub(long int val)
{
	_val -= val;
	updateText();
}

void Score::add(long int val)
{
	_val += val;
	updateText();
}

long int Score::getValue() const
{
	return _val;
}

Score::operator long int() const
{
	return _val;
}

void Score::setCharacterSize(unsigned int size)
{
	_text.setCharacterSize(size);
}

void Score::setFont(const sf::Font & font)
{
	_text.setFont(font);
}

unsigned int Score::getCharacterSize() const
{
	return _text.getCharacterSize();
}

const sf::Font * Score::getFont() const
{
	return _text.getFont();
}

void Score::updateText()
{
	_text.setString("Score: " + std::to_string(_val));
}

void Score::updateCurrent(const sf::Time & /* deltaTime */, const mysf::Event & /* event */)
{
	updateText();
}

void Score::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_text, states);
}

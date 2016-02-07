#include "Button.hpp"

Button::Button(Context & ctx, int & select, bool & check, const std::string & text, int id)
  : _ctx(ctx)
  , _select(select)
  , _check(check)
  , _text(text, ctx.fhl[Resource::Font::Gomoku], 50)
  , _id(id)
{

}

Button::~Button()
{

}

void Button::update(float /* deltaTime */, const Input & input)
{
  if (input.getMouse().isInside())
    {
      if (input.getMouse().getPos().x >= getPosition().x && input.getMouse().getPos().x < getPosition().x + getSize().x &&
	  input.getMouse().getPos().y >= getPosition().y && input.getMouse().getPos().y < getPosition().y + getSize().y)
	{
	  _select = _id;
	  if (input.getMouse().isDown(sf::Mouse::Left))
	    _check = true;
	}
    }
  if (_select == _id)
    {
      setFillColor(_colorSelected);
      _text.setColor(_textColorSelected);
    }
  else
    {
      setFillColor(_color);
      _text.setColor(_textColor);
    }
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
  target.draw(sf::RectangleShape(*this), states);
  states.transform *= getTransform();

  target.draw(_text, states);
}

void Button::setText(const std::string & text)
{
  _text.setString(text);
}

void Button::setFont(const sf::Font & font)
{
  _text.setFont(font);
}

void Button::setCharacterSize(unsigned int characterSize)
{
  _text.setCharacterSize(characterSize);
}

void Button::setColor(const sf::Color & color)
{
  _color = color;
}

void Button::setColorSelected(const sf::Color & color)
{
  _colorSelected = color;
}

void Button::setTextColor(const sf::Color & color)
{
  _textColor = color;
}

void Button::setTextColorSelected(const sf::Color & color)
{
  _textColorSelected = color;
}

const sf::String & Button::getText() const
{
  return _text.getString();
}

const sf::Text & Button::getText2() const
{
  return _text;
}

const sf::Font & Button::getFont() const
{
  return *_text.getFont();
}

unsigned int Button::getCharacterSize() const
{
  return _text.getCharacterSize();
}

const sf::Color & Button::getColor() const
{
  return _color;
}

const sf::Color & Button::getColorSelected() const
{
  return _colorSelected;
}

const sf::Color & Button::getTextColor() const
{
  return _textColor;
}

const sf::Color & Button::getTextColorSelected() const
{
  return _textColorSelected;
}

void Button::updateSize()
{
  unsigned int width, height;

  _text.setCharacterSize((height = getSize().y * 0.75f));
  width = _text.findCharacterPos(_text.getString().getSize()).x - _text.getPosition().x;
  _text.setPosition(sf::Vector2f((getSize().x / 2) - (width / 2), (getSize().y / 2) - (height * 0.66f)));
}

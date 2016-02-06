#include "Mouse.hpp"

Mouse::Mouse()
  : _down(sf::Mouse::ButtonCount, false)
  , _inside(false)
  , _wheelMoved(false)
  , _wheelTick(0)
  , _pos(0, 0)
{

}

Mouse::~Mouse()
{

}

void Mouse::update(const sf::Event & event)
{
  _wheelMoved = false;
  _mouseMoved = false;
  switch (event.type)
    {
    case sf::Event::MouseWheelMoved:
      _wheelMoved = true;
      _wheelTick = event.mouseWheel.delta;
      _pos.x = event.mouseWheel.x;
      _pos.y = event.mouseWheel.y;
      _inside = true;
      break;
    case sf::Event::MouseButtonPressed:
      _down[event.mouseButton.button] = true;
      _pos.x = event.mouseButton.x;
      _pos.y = event.mouseButton.y;
      _inside = true;
      break;
    case sf::Event::MouseButtonReleased:
      _down[event.mouseButton.button] = false;
      _pos.x = event.mouseButton.x;
      _pos.y = event.mouseButton.y;
      _inside = true;
      break;
    case sf::Event::MouseMoved:
      _pos.x = event.mouseMove.x;
      _pos.y = event.mouseMove.y;
      _inside = true;
      _mouseMoved = true;
      break;
    case sf::Event::MouseEntered:
      _inside = true;
      break;
    case sf::Event::MouseLeft:
      _inside = false;
      break;
    default:
      break;
    }
}

void Mouse::reset()
{
  for (unsigned int i = 0; i < _down.size(); ++i)
    _down[i] = false;
}

bool Mouse::isDown(sf::Mouse::Button button) const
{
  return _down[button];
}

bool Mouse::isInside() const
{
  return _inside;
}

bool Mouse::isMouseMoved() const
{
  return _mouseMoved;
}

bool Mouse::isWheelMoved() const
{
  return _wheelMoved;
}

int Mouse::getWheelTick() const
{
  return _wheelTick;
}

const sf::Vector2i & Mouse::getPos() const
{
  return _pos;
}

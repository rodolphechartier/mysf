#include "Input.hpp"

Input::Input()
  : _closed(false)
  , _focus(true)
{

}

Input::~Input()
{

}

void Input::update(const sf::Event & event)
{
  _key.update(event);
  _mouse.update(event);
  switch (event.type)
    {
    case sf::Event::Closed:
      _closed = true;
      break;
    case sf::Event::LostFocus:
      _focus = false;
      break;
    case sf::Event::GainedFocus:
      _focus = true;
      break;
    default:
      break;
    }
}

void Input::reset()
{
  _key.reset();
  _mouse.reset();
}

const Key & Input::getKey() const
{
  return _key;
}

const Mouse & Input::getMouse() const
{
  return _mouse;
}

bool Input::isClosed() const
{
  return _closed;
}

bool Input::isFocused() const
{
  return _focus;
}

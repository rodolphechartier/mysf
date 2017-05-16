#include "Input.hpp"

namespace mysf
{
  Input::Input()
    : _closed(false)
    , _focus(true)
  {

  }

  Input::Input(const Input & o)
    : _key(o._key)
    , _mouse(o._mouse)
    , _joysticks(o._joysticks)
    , _closed(o._closed)
    , _focus(o._focus)
  {

  }

  Input & Input::operator=(const Input & o)
  {
    if (this == &o)
      return *this;
    _key = o._key;
    _mouse = o._mouse;
    _joysticks = o._joysticks;
    _closed = o._closed;
    _focus = o._focus;
    return *this;
  }

  Input::~Input()
  {

  }

  void Input::update(const sf::Event & event)
  {
    _key.update(event);
    _mouse.update(event);
    _joysticks.update(event);

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
    _joysticks.reset();
  }

  const Key & Input::key() const
  {
    return _key;
  }

  const Mouse & Input::mouse() const
  {
    return _mouse;
  }

  const Joysticks & Input::joysticks() const
  {
    return _joysticks;
  }

  bool Input::isClosed() const
  {
    return _closed;
  }

  bool Input::isFocused() const
  {
    return _focus;
  }
}

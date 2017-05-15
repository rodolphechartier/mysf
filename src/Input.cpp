#include "Input.hpp"

namespace mysf
{
  Input::Input(bool isJoystick)
    : _closed(false)
    , _focus(true)
  {
    if (isJoystick)
    {
      for (unsigned int i = 0; i < sf::Joystick::Count; ++i)
        if (sf::Joystick::isConnected(i))
          _joysticks.push_back(Joystick(i));
    }
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
    for (unsigned int i = 0; i < _joysticks.size(); ++i)
      _joysticks[i].update();

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
    for (unsigned int i = 0; i < _joysticks.size(); ++i)
      _joysticks[i].reset();
  }

  const Key & Input::key() const
  {
    return _key;
  }

  const Mouse & Input::mouse() const
  {
    return _mouse;
  }

  const Joystick * Input::joystick(unsigned int idJoystick) const
  {
    for (unsigned int i = 0; i < _joysticks.size(); ++i)
      if (_joysticks[i].getID() == idJoystick)
        return &(_joysticks[i]);
    return 0;
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

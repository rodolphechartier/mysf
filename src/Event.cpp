#include "Event.hpp"

namespace mysf
{
  Event::Event()
    : _closed(false)
    , _focus(true)
  {

  }

  Event::Event(const Event & o)
    : _key(o._key)
    , _mouse(o._mouse)
    , _joysticks(o._joysticks)
    , _closed(o._closed)
    , _focus(o._focus)
  {

  }

  Event & Event::operator=(const Event & o)
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

  Event::~Event()
  {

  }

  void Event::update(const sf::Event & event)
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

	void Event::loop()
	{
		_key.loop();
		_mouse.loop();
		_joysticks.loop();
	}

  void Event::reset()
  {
    _key.reset();
    _mouse.reset();
    _joysticks.reset();
  }

  Key & Event::key()
  {
    return _key;
  }

	const Key & Event::key() const
  {
    return _key;
  }

	Mouse & Event::mouse()
  {
    return _mouse;
  }

  const Mouse & Event::mouse() const
  {
    return _mouse;
  }

	Joysticks & Event::joysticks()
  {
    return _joysticks;
  }

  const Joysticks & Event::joysticks() const
  {
    return _joysticks;
  }

  bool Event::isClosed() const
  {
    return _closed;
  }

  bool Event::isFocused() const
  {
    return _focus;
  }
}

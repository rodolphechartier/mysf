#include "Key.hpp"

namespace mysf
{
  Key::Key()
    : _update(EventType::EventTypeCount)
		, _eventType(EventType::Pressed)
		, _down(sf::Keyboard::KeyCount, false)
  {
		_update[EventType::Pressed] = &Key::_updatePressed;
		_update[EventType::Released] = &Key::_updateReleased;
		_update[EventType::OnPressed] = &Key::_updateOnPressed;
		_update[EventType::OnReleased] = &Key::_updateOnReleased;
  }

  Key::Key(const Key & o)
    : _update(EventType::EventTypeCount)
		, _eventType(o._eventType)
		, _down(o._down)
  {
		_update[EventType::Pressed] = &Key::_updatePressed;
		_update[EventType::Released] = &Key::_updateReleased;
		_update[EventType::OnPressed] = &Key::_updateOnPressed;
		_update[EventType::OnReleased] = &Key::_updateOnReleased;
  }

  Key & Key::operator=(const Key & o)
  {
    if (&o == this)
      return *this;
		_eventType = o._eventType;
    _down = o._down;
    return *this;
  }

  Key::~Key()
  {

  }

  void Key::update(const sf::Event & event)
  {
		(this->*_update[_eventType])(event);
  }

  void Key::reset()
  {
    for (unsigned int i = 0; i < _down.size(); ++i)
      _down[i] = false;
  }

	void Key::setEventType(const EventType & eventType)
	{
		_eventType = eventType;
		reset();
	}

	const EventType & Key::getEventType() const
	{
		return _eventType;
	}

  bool Key::isDown(sf::Keyboard::Key key) const
  {
    return _down[key];
  }

	void Key::_updatePressed(const sf::Event & event)
	{
		switch (event.type)
      {
      case sf::Event::KeyPressed:
      	_down[event.key.code] = true;
      	break;
      case sf::Event::KeyReleased:
      	_down[event.key.code] = false;
      	break;
      default:
	      break;
      }
	}

	void Key::_updateReleased(const sf::Event & event)
	{
		switch (event.type)
      {
      case sf::Event::KeyPressed:
      	_down[event.key.code] = false;
      	break;
      case sf::Event::KeyReleased:
      	_down[event.key.code] = true;
      	break;
      default:
	      break;
      }
	}

	void Key::_updateOnPressed(const sf::Event & event)
	{
		static sf::Keyboard::Key key = sf::Keyboard::Unknown;

		if (key != sf::Keyboard::Unknown)
			{
				_down[key] = false;
				key = sf::Keyboard::Unknown;
			}
		switch (event.type)
      {
      case sf::Event::KeyPressed:
				key = event.key.code;
      	_down[key] = true;
      	break;
      default:
	      break;
      }
	}

	void Key::_updateOnReleased(const sf::Event & event)
	{
		static sf::Keyboard::Key key = sf::Keyboard::Unknown;

		if (key != sf::Keyboard::Unknown)
			{
				_down[key] = false;
				key = sf::Keyboard::Unknown;
			}
		switch (event.type)
      {
      case sf::Event::KeyReleased:
				key = event.key.code;
      	_down[key] = true;
      	break;
      default:
	      break;
      }
	}


}

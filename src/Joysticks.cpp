#include "Joysticks.hpp"

namespace mysf
{
  Joysticks::Joystick::Joystick()
    : _isConnected(false)
    , _down(sf::Joystick::ButtonCount, false)
    , _axis(sf::Joystick::AxisCount, 0.f)
	{

	}

  Joysticks::Joystick::Joystick(const Joystick & o)
    : _isConnected(o._isConnected)
    , _down(o._down)
    , _axis(o._axis)
	{

	}

  Joysticks::Joystick & Joysticks::Joystick::operator=(const Joystick & o)
	{
    if (this == &o)
      return *this;
    _isConnected = o._isConnected;
    _down = o._down;
    _axis = o._axis;
    return *this;
	}

  Joysticks::Joystick::~Joystick()
	{

	}

  void Joysticks::Joystick::connect()
	{
    reset();
    _isConnected = true;
	}

  void Joysticks::Joystick::disconnect()
	{
    _isConnected = false;
	}

  bool Joysticks::Joystick::isConnected() const
	{
    return _isConnected;
	}

  void Joysticks::Joystick::reset()
	{
    for (unsigned int i = 0; i < _down.size(); ++i)
      _down[i] = false;
    for (unsigned int i = 0; i < _axis.size(); ++i)
      _axis[i] = 0.f;
	}

  void Joysticks::Joystick::setButton(unsigned int button, bool value)
  {
    _down[button] = value;
  }

  bool Joysticks::Joystick::operator[](unsigned int button) const
	{
    return _down[button];
	}

  float & Joysticks::Joystick::operator[](sf::Joystick::Axis axis)
	{
    return _axis[axis];
	}

  const float & Joysticks::Joystick::operator[](sf::Joystick::Axis axis) const
	{
    return _axis[axis];
	}

  Joysticks::Joysticks()
    : _joysticks()
    , _nbConnected(0)
  {

  }

  Joysticks::Joysticks(const Joysticks & o)
    : _joysticks(o._joysticks)
    , _nbConnected(o._nbConnected)
  {

  }

  Joysticks & Joysticks::operator=(const Joysticks & o)
  {
    if (&o == this)
      return *this;
    _joysticks = o._joysticks;
    _nbConnected = o._nbConnected;
    return *this;
  }

  Joysticks::~Joysticks()
  {

  }

  void Joysticks::update(const sf::Event & event)
  {
    switch (event.type)
      {
      case sf::Event::JoystickButtonPressed:
        checkConnect(event.joystickButton.joystickId);
        _joysticks[event.joystickButton.joystickId].setButton(event.joystickButton.button, true);
        break;
      case sf::Event::JoystickButtonReleased:
        checkConnect(event.joystickButton.joystickId);
        _joysticks[event.joystickButton.joystickId].setButton(event.joystickButton.button, false);
        break;
      case sf::Event::JoystickMoved:
        checkConnect(event.joystickMove.joystickId);
        _joysticks[event.joystickMove.joystickId][event.joystickMove.axis] = event.joystickMove.position;
        break;
      case sf::Event::JoystickConnected:
        connect(event.joystickConnect.joystickId);
      	break;
      case sf::Event::JoystickDisconnected:
        disconnect(event.joystickConnect.joystickId);
      	break;
      default:
	      break;
      }
  }

  void Joysticks::reset()
  {
    for (unsigned int i = 0; i < _joysticks.size(); ++i)
      _joysticks[i].reset();
  }

  const Joysticks::Joystick & Joysticks::operator[](unsigned int joystick) const
  {
    return _joysticks[joystick];
  }

  void Joysticks::checkConnect(unsigned int joystick)
  {
    if (!_joysticks.size())
      connect(joystick);
    else if (_joysticks[joystick].isConnected() == false)
      _joysticks[joystick].connect();
  }

  void Joysticks::connect(unsigned int joystick)
  {
    if (_joysticks.size() == 0)
      _joysticks.resize(sf::Joystick::Count);
    _joysticks[joystick].connect();
    ++_nbConnected;
  }

  void Joysticks::disconnect(unsigned int joystick)
  {
    _joysticks[joystick].disconnect();
    --_nbConnected;
    if (!_nbConnected)
      _joysticks.clear();
  }
}

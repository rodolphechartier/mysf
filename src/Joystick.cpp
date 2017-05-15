#include "Joystick.hpp"

namespace mysf
{
  Joystick::Joystick(unsigned int id)
    : _id(id)
    , _down(sf::Joystick::ButtonCount, false)
    , _axis(sf::Joystick::AxisCount, 0.f)
  {

  }

  Joystick::Joystick(const Joystick & o)
    : _id(o._id)
    , _down(o._down)
    , _axis(o._axis)
  {

  }

  Joystick & Joystick::operator=(const Joystick & o)
  {
    if (&o == this)
      return *this;
    _down = o._down;
    _axis = o._axis;
    return *this;
  }

  Joystick::~Joystick()
  {

  }

  void Joystick::update()
  {
    for (unsigned int i = 0; i < _down.size(); ++i)
      _down[i] = sf::Joystick::isButtonPressed(_id, i);
    for (unsigned int i = 0; i < _axis.size(); ++i)
      _axis[i] = sf::Joystick::getAxisPosition(_id, static_cast<sf::Joystick::Axis>(i));
  }

  void Joystick::reset()
  {
    for (unsigned int i = 0; i < _down.size(); ++i)
      _down[i] = false;
    for (unsigned int i = 0; i < _axis.size(); ++i)
      _axis[i] = 0.f;
  }

  unsigned int Joystick::getID() const
  {
    return _id;
  }

  bool Joystick::operator[](unsigned int button) const
  {
    return _down[button];
  }

  bool Joystick::isDown(unsigned int button) const
  {
    return _down[button];
  }

  bool Joystick::isDown(const std::vector<unsigned int> & buttons) const
  {
    for (unsigned int i = 0; i < buttons.size(); ++i)
      if (_down[buttons[i]])
	     return true;
    return false;
  }

  float Joystick::operator[](sf::Joystick::Axis axis) const
  {
    return _axis[axis];
  }

  float Joystick::getAxisPosition(sf::Joystick::Axis axis) const
  {
    return _axis[axis];
  }
}

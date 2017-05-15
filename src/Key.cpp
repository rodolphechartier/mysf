#include "Key.hpp"

namespace mysf
{
  Key::Key()
    : _down(sf::Keyboard::KeyCount, false)
  {

  }

  Key::Key(const Key & o)
    : _down(o._down)
  {

  }

  Key & Key::operator=(const Key & o)
  {
    if (&o == this)
      return *this;
    _down = o._down;
    return *this;
  }

  Key::~Key()
  {

  }

  void Key::update(const sf::Event & event)
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

  void Key::reset()
  {
    for (unsigned int i = 0; i < _down.size(); ++i)
      _down[i] = false;
  }

  bool Key::operator[](sf::Keyboard::Key key) const
  {
    return _down[key];
  }

  bool Key::isDown(sf::Keyboard::Key key) const
  {
    return _down[key];
  }

  bool Key::isDown(const std::vector<sf::Keyboard::Key> & keys) const
  {
    for (unsigned int i = 0; i < keys.size(); ++i)
      if (_down[keys[i]])
	     return true;
    return false;
  }
}

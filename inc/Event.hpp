#ifndef EVENT_HPP_
# define EVENT_HPP_

# include <SFML/Window.hpp>

# include "Key.hpp"
# include "Mouse.hpp"
# include "Joysticks.hpp"

namespace mysf
{
  class Event
  {
  public:
    Event();
    Event(const Event & o);
    Event & operator=(const Event & o);
    virtual ~Event();

    void	           	update(const sf::Event & event);
    void	           	reset();

    const Key &		    key() const;
    const Mouse &	    mouse() const;
    const Joysticks & joysticks() const;
    bool		          isClosed() const;
    bool		          isFocused() const;

  protected:
    Key		            _key;
    Mouse	            _mouse;
    Joysticks         _joysticks;
    bool	            _closed;
    bool              _focus;
  };
}

#endif // !EVENT_HPP_

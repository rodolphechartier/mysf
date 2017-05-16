#ifndef INPUT_HPP_
# define INPUT_HPP_

# include <SFML/Window.hpp>

# include "Key.hpp"
# include "Mouse.hpp"
# include "Joysticks.hpp"

namespace mysf
{
  class Input
  {
  public:
    Input();
    Input(const Input & o);
    Input & operator=(const Input & o);
    virtual ~Input();

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

#endif // !INPUT_HPP_

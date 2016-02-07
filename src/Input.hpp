#ifndef INPUT_HPP_
# define INPUT_HPP_

# include <SFML/Window.hpp>

# include "Key.hpp"
# include "Mouse.hpp"

class Input
{
public:
  Input();
  Input(const Input &);
  Input & operator=(const Input &);
  virtual ~Input();

  void			update(const sf::Event & event);
  void			reset();

  const Key &		getKey() const;
  const Mouse &		getMouse() const;
  bool			isClosed() const;
  bool			isFocused() const;

protected:
  Key			_key;
  Mouse			_mouse;
  bool			_closed;
  bool			_focus;
};

#endif // !INPUT_HPP_

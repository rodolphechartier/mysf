#ifndef MOUSE_HPP_
# define MOUSE_HPP_

# include <SFML/Window.hpp>

namespace mysf
{
  class Mouse
  {
  public:
    Mouse();
    Mouse(const Mouse & o);
    Mouse & operator=(const Mouse & o);
    virtual ~Mouse();

    void			update(const sf::Event & event);
    void			reset();

    bool			isDown(sf::Mouse::Button button) const;
    bool			isInside() const;
    bool			isMouseMoved() const;
    bool			isWheelMoved() const;
    int				getWheelTick() const;

    const sf::Vector2i &	getPos() const;

  protected:
    std::vector<bool>	_down;
    bool	           	_inside;
    bool	           	_wheelMoved;
    bool          		_mouseMoved;
    int	          		_wheelTick;
    sf::Vector2i    	_pos;
  };
}

#endif // !MOUSE_HPP_

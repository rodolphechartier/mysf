#ifndef MOUSE_HPP_
# define MOUSE_HPP_

# include <SFML/Window.hpp>

namespace mysf
{
  class Mouse
  {
	public:
		enum WheelDir
		{
			Up,
			Down,
			Right,
			Left
		};

  public:
    Mouse();
    Mouse(const Mouse & o);
    Mouse & operator=(const Mouse & o);
    virtual ~Mouse();

    void			update(const sf::Event & event);
    void			reset();

    bool			isDown(sf::Mouse::Button button) const;
    bool			isInside() const;
    bool			isMoved() const;
    bool			isScrolled() const;
    bool			isScrolled(WheelDir dir) const;

    const sf::Vector2i &	getPos() const;
    const sf::Vector2i &	getWheelTick() const;

  protected:
    std::vector<bool> 		_down;
    bool	           			_inside;
    bool          				_moved;
    bool	           			_scrolled;
    sf::Vector2i					_pos;
    sf::Vector2i       		_wheelTick;
  };
}

#endif // !MOUSE_HPP_

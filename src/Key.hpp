#ifndef KEY_HPP_
# define KEY_HPP_

# include <vector>

# include <SFML/Window.hpp>

namespace mysf
{
  class Key
  {
  public:
    Key();
    Key(const Key & o);
    Key & operator=(const Key & o);
    virtual ~Key();

    void	update(const sf::Event & event);
    void	reset();

    bool	isDown(sf::Keyboard::Key key) const;
    bool	isDown(const std::vector<sf::Keyboard::Key> & key) const;

  protected:
    std::vector<bool>	_down;
  };
}

#endif // !KEY_HPP_

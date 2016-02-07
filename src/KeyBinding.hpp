#ifndef KEYBINDING_HPP_
# define KEYBINDING_HPP_

# include <fstream>
# include <vector>
# include <string>
# include <map>

# include <SFML/Window.hpp>

namespace mysf
{
  class KeyBinding
  {
  public:
    KeyBinding();
    KeyBinding(const KeyBinding & o);
    KeyBinding & operator=(const KeyBinding & o);
    virtual ~KeyBinding();

    // syntax "action=key|... # comment"
    bool	load(const std::string & filename, std::map<std::string, unsigned int> & bind);

    std::vector<sf::Keyboard::Key> &		operator[](unsigned int action);
    const std::vector<sf::Keyboard::Key> &	operator[](unsigned int action) const;

  private:
    void	_eraseSpace(std::string & str);
    void	_initSfbind(std::map<std::string, sf::Keyboard::Key> & sfbind) const;

  protected:
    std::vector<std::vector<sf::Keyboard::Key> >	_bind;
  };
}

#endif // !KEYBINDING_HPP_

#ifndef UPDATABLE_HPP_
# define UPDATABLE_HPP_

# include <SFML/Graphics.hpp>

# include "Input.hpp"

class Updatable : public sf::RectangleShape
{
public:
  Updatable();
  explicit Updatable(const sf::Texture & texture);
  Updatable(const Updatable &);
  Updatable & operator=(const Updatable &);
  virtual ~Updatable();

  virtual void	update(float deltaTime, const Input & input);
};

#endif // !UPDATABLE_HPP_

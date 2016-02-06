#ifndef LAYER_HPP_
# define LAYER_HPP_

# include <list>

# include <SFML/Graphics.hpp>

# include "Updatable.hpp"
# include "Input.hpp"

class Layer
{
public:
  Layer();
  Layer(const Layer & o);
  Layer & operator=(const Layer & o);
  virtual ~Layer();

  void	update(float deltaTime, const Input & input);
  void	draw(sf::RenderTarget & target, sf::RenderStates states) const;

  void	add(Updatable * updatable);
  void	clear();

private:
  std::list<Updatable *>	_list;
};

#endif // !LAYER_HPP_

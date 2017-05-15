#ifndef LAYER_HPP_
# define LAYER_HPP_

# include <list>

# include <SFML/Graphics.hpp>

# include "SceneNode.hpp"
# include "Input.hpp"

namespace mysf
{
  class Layer
  {
  public:
    Layer();
    Layer(const Layer & o);
    Layer & operator=(const Layer & o);
    virtual ~Layer();

    void	update(const sf::Time & deltaTime, const Input & input);
    void	draw(sf::RenderTarget & target, sf::RenderStates states) const;

    void	add(SceneNode * node);
    void	clear();

  private:
    std::list<SceneNode *>	_list;
  };
}

#endif // !LAYER_HPP_

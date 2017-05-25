#ifndef GRAPHIC_LAYER_HPP_
# define GRAPHIC_LAYER_HPP_

# include <list>
# include <algorithm>

# include <SFML/Graphics.hpp>

# include "SceneNode.hpp"
# include "Event.hpp"

namespace mysf
{
  class GraphicLayer
  {
  public:
    GraphicLayer();
    GraphicLayer(const GraphicLayer & o);
    GraphicLayer & operator=(const GraphicLayer & o);
    virtual ~GraphicLayer();

    void	update(const sf::Time & deltaTime, const Event & event);
    void	draw(sf::RenderTarget & target, sf::RenderStates states) const;

    void	add(SceneNode * node);
		void 	remove(SceneNode * node);
    void	clear();

  private:
    std::list<SceneNode *>	_list;
  };
}

#endif // !GRAPHIC_LAYER_HPP_

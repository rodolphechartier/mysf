#ifndef GRAPHIC_LAYER_SET_HPP_
# define GRAPHIC_LAYER_SET_HPP_

# include <vector>

# include <SFML/Graphics.hpp>

# include "GraphicLayer.hpp"
# include "Event.hpp"

namespace mysf
{
  class GraphicLayerSet
  {
  public:
    explicit GraphicLayerSet(unsigned int nbLayer = 0);
    GraphicLayerSet(const GraphicLayerSet &) = delete;
    GraphicLayerSet & operator=(const GraphicLayerSet &) = delete;
    virtual ~GraphicLayerSet();

    void		update(const sf::Time & deltaTime, const Event & event);
    void		draw(sf::RenderTarget & target, sf::RenderStates states) const;

    void		resize(unsigned int nbLayer);
    void		add(unsigned int nbLayer);
    void		sub(unsigned int nbLayer);
    void		clear();

    GraphicLayer & operator[](unsigned int layer);
    const GraphicLayer & operator[](unsigned int layer) const;

  protected:
    std::vector<GraphicLayer> _layers;
  };
}

#endif // !GRAPHIC_LAYER_SET_HPP_

#ifndef GRAPHIC_LAYER_SET_HPP_
# define GRAPHIC_LAYER_SET_HPP_

# include <vector>

# include <SFML/Graphics.hpp>

# include "Layer.hpp"
# include "Input.hpp"

class GraphicLayerSet
{
public:
  explicit GraphicLayerSet(unsigned int nbLayer = 0);
  GraphicLayerSet(const GraphicLayerSet &);
  GraphicLayerSet & operator=(const GraphicLayerSet &);
  virtual ~GraphicLayerSet();

  void		update(float deltaTime, const Input & input);
  void		draw(sf::RenderTarget & target, sf::RenderStates states) const;

  void		resize(unsigned int nbLayer);
  void		add(unsigned int nbLayer);
  void		sub(unsigned int nbLayer);
  void		clear();

  Layer &	operator[](unsigned int layer);
  const Layer &	operator[](unsigned int layer) const;

private:
  std::vector<Layer>	_layers;
};

#endif // !GRAPHIC_LAYER_SET_HPP_

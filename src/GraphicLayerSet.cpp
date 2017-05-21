#include "GraphicLayerSet.hpp"

namespace mysf
{
  GraphicLayerSet::GraphicLayerSet(unsigned int nbLayer)
    : _layers(nbLayer)
  {

  }

  GraphicLayerSet::~GraphicLayerSet()
  {

  }

  void GraphicLayerSet::update(const sf::Time & deltaTime, const Event & event)
  {
    for (unsigned int i = 0; i < _layers.size(); ++i)
      _layers[i].update(deltaTime, event);
  }

  void GraphicLayerSet::draw(sf::RenderTarget & target, sf::RenderStates states) const
  {
    for (unsigned int i = 0; i < _layers.size(); ++i)
      _layers[i].draw(target, states);
  }

  void GraphicLayerSet::resize(unsigned int nbLayer)
  {
    clear();
    _layers.resize(nbLayer);
  }

  void GraphicLayerSet::add(unsigned int nbLayer)
  {
    _layers.resize(_layers.size() + nbLayer);
  }

  void GraphicLayerSet::sub(unsigned int nbLayer)
  {
    if (_layers.size() != nbLayer)
      for (unsigned int i = _layers.size() - nbLayer - 1; i < _layers.size(); ++i)
	     _layers[i].clear();
    _layers.resize(_layers.size() - nbLayer);
  }

  void GraphicLayerSet::clear()
  {
    for (unsigned int i = 0; i < _layers.size(); ++i)
      _layers[i].clear();
  }

  Layer & GraphicLayerSet::operator[](unsigned int layer)
  {
    return _layers[layer];
  }

  const Layer & GraphicLayerSet::operator[](unsigned int layer) const
  {
    return _layers[layer];
  }
}

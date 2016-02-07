#include "Layer.hpp"

namespace mysf
{
  Layer::Layer()
  {

  }

  Layer::Layer(const Layer & o)
    : _list(o._list)
  {

  }

  Layer & Layer::operator=(const Layer & o)
  {
    if (&o == this)
      return *this;
    _list = o._list;
    return *this;
  }

  Layer::~Layer()
  {
    _list.clear();
  }

  void Layer::update(const sf::Time & deltaTime, const Input & input)
  {
    for (std::list<SceneNode *>::iterator it = _list.begin(); it != _list.end(); ++it)
      (*it)->update(deltaTime, input);
  }

  void Layer::draw(sf::RenderTarget & target, sf::RenderStates states) const
  {
    for (std::list<SceneNode *>::const_iterator it = _list.begin(); it != _list.end(); ++it)
      (*it)->draw(target, states);
  }

  void Layer::add(SceneNode * node)
  {
    _list.push_back(node);
  }

  void Layer::clear()
  {
    _list.clear();
  }
}

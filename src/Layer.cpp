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

  }

  void Layer::update(const sf::Time & deltaTime, const Event & event)
  {
    for (auto it = _list.begin(); it != _list.end(); ++it)
      (*it)->update(deltaTime, event);
  }

  void Layer::draw(sf::RenderTarget & target, sf::RenderStates states) const
  {
    for (auto it = _list.begin(); it != _list.end(); ++it)
      (*it)->draw(target, states);
  }

  void Layer::add(SceneNode * node)
  {
    _list.push_back(node);
  }

	void Layer::remove(SceneNode * node)
	{
		_list.erase(std::find(_list.begin(), _list.end(), node));
	}

  void Layer::clear()
  {
    _list.clear();
  }
}

#include "GraphicLayer.hpp"

namespace mysf
{
  GraphicLayer::GraphicLayer()
  {

  }

  GraphicLayer::GraphicLayer(const GraphicLayer & o)
    : _list(o._list)
  {

  }

  GraphicLayer & GraphicLayer::operator=(const GraphicLayer & o)
  {
    if (&o == this)
      return *this;
    _list = o._list;
    return *this;
  }

  GraphicLayer::~GraphicLayer()
  {

  }

  void GraphicLayer::update(const sf::Time & deltaTime, const Event & event)
  {
    for (auto it = _list.begin(); it != _list.end(); ++it)
      (*it)->update(deltaTime, event);
  }

  void GraphicLayer::draw(sf::RenderTarget & target, sf::RenderStates states) const
  {
    for (auto it = _list.begin(); it != _list.end(); ++it)
      (*it)->draw(target, states);
  }

  void GraphicLayer::add(SceneNode * node)
  {
    _list.push_back(node);
  }

	void GraphicLayer::remove(SceneNode * node)
	{
		_list.erase(std::find(_list.begin(), _list.end(), node));
	}

  void GraphicLayer::clear()
  {
    _list.clear();
  }
}

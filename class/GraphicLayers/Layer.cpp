#include "Layer.hpp"

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

void Layer::update(float deltaTime, const Input & input)
{
  for (std::list<Updatable *>::iterator it = _list.begin(); it != _list.end(); ++it)
    (*it)->update(deltaTime, input);
}

void Layer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
  for (std::list<Updatable *>::const_iterator it = _list.begin(); it != _list.end(); ++it)
    target.draw(**it, states);
}

void Layer::add(Updatable * updatable)
{
  _list.push_back(updatable);
}

void Layer::clear()
{
  _list.clear();
}

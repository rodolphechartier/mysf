#include "SceneNode.hpp"

namespace mysf
{
  SceneNode::SceneNode()
    : sf::Transformable()
    , sf::Drawable()
    , _child()
    , _parent(0)
  {

  }

  SceneNode::~SceneNode()
  {
    for (typename std::list<SceneNode *>::iterator it = _child.begin(); it != _child.end(); ++it)
      delete *it;
  }

  void SceneNode::attachChild(SceneNode * child)
  {
    child->_parent = this;
    _child.push_back(child);
  }

  SceneNode * SceneNode::detachChild(const SceneNode & node)
  {
    for (typename std::list<SceneNode *>::iterator it = _child.begin(); it != _child.end(); ++it)
      if (&node == *it)
	{
	  _child.erase(it);
	  return *it;
	}
    return 0;
  }

  sf::Transform SceneNode::getWorldTransform() const
  {
    sf::Transform transform = sf::Transform::Identity;

    for (const SceneNode * node = this; node; node = node->_parent)
      transform *= node->getTransform();
    return transform;
  }

  sf::Vector2f SceneNode::getWorldPosition() const
  {
    return getWorldTransform() * sf::Vector2f();
  }

  void SceneNode::update(const sf::Time & deltaTime, const Input & input)
  {
    updateCurrent(deltaTime, input);
    for (typename std::list<SceneNode *>::const_iterator it = _child.begin(); it != _child.end(); ++it)
      (*it)->update(deltaTime, input);
  }

  void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
  {
    states.transform *= getTransform();
    drawCurrent(target, states);
    for (typename std::list<SceneNode *>::const_iterator it = _child.begin(); it != _child.end(); ++it)
      (*it)->draw(target, states);
  }
}

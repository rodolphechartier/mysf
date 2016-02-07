#ifndef SCENE_NODE_HPP_
# define SCENE_NODE_HPP_

# include <SFML/Graphics.hpp>

# include <list>

class SceneNode : public sf::Transformable, public sf::Drawable
{
public:
  enum Layer
    {
      None = -1,
      First = 0,
      Background = First,
      Air,
      Size
    };

public:
  SceneNode();
  SceneNode(const SceneNode & o);
  SceneNode & operator=(const SceneNode & o);
  virtual ~SceneNode();

  void		attachChild(SceneNode * child);
  SceneNode *	detachChild(const SceneNode & node);

  sf::Transform	getWorldTransform() const;
  sf::Vector2f	getWorldPosition() const;

  virtual void	update(const sf::Time & deltaTime);
  virtual void	draw(sf::RenderTarget & target, sf::RenderStates states) const;

protected:
  virtual void	updateCurrent(const sf::Time & deltaTime) = 0;
  virtual void	drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const = 0;

protected:
  std::list<SceneNode *>	_child;
  SceneNode *			_parent;
};

#endif // !SCENE_NODE_HPP_

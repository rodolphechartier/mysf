#ifndef SCENE_NODE_HPP_
# define SCENE_NODE_HPP_

# include <SFML/Graphics.hpp>

# include <list>

# include "Input.hpp"

namespace mysf
{
  class SceneNode : public sf::Transformable, public sf::Drawable
  {
  public:
    SceneNode();
    SceneNode(const SceneNode & o) = delete;
    SceneNode & operator=(const SceneNode & o) = delete;
    virtual ~SceneNode();

    void		      addChild(SceneNode * child);
    SceneNode *		subChild(const SceneNode & node);

    sf::Transform	getWorldTransform() const;
    sf::Vector2f	getWorldPosition() const;

    virtual void	update(const sf::Time & deltaTime, const Input & input);
    virtual void	draw(sf::RenderTarget & target, sf::RenderStates states) const;

  protected:
    virtual void	updateCurrent(const sf::Time & deltaTime, const Input & input) = 0;
    virtual void	drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const = 0;

  protected:
    std::list<SceneNode *> _child;
    SceneNode * _parent;
  };
}

#endif // !SCENE_NODE_HPP_

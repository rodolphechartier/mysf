#ifndef SPRITE_NODE_HPP_
# define SPRITE_NODE_HPP_

# include <SFML/Graphics.hpp>

# include "SceneNode.hpp"

namespace mysf
{
  class SpriteNode : public SceneNode
  {
  public:
    SpriteNode();
    explicit SpriteNode(const sf::Texture & texture);
    explicit SpriteNode(const sf::Texture & texture, const sf::IntRect & rectanlge);
    SpriteNode(const SpriteNode & o) = delete;
    SpriteNode & operator=(const SpriteNode & o) = delete;
    virtual ~SpriteNode();

    // Direct calls to sf::Sprite
    void setTexture(const sf::Texture & texture, bool resetRect = false);
    void setTextureRect(const sf::IntRect & rectangle);
    void setColor(const sf::Color & color);
    const sf::Texture * getTexture() const;
    const sf::IntRect & getTextureRect() const;
    const sf::Color & getColor() const;
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

  protected:
    // virtual void	updateCurrent(const sf::Time & deltaTime, const Input & input) = 0;
    virtual void	drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;

  protected:
    sf::Sprite _sprite;
  };
}

#endif // !SPRITE_NODE_HPP_

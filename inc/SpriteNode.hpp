#ifndef SPRITENODE_HPP_
# define SPRITENODE_HPP_

# include <SFML/Graphics.hpp>

# include "SceneNode.hpp"

namespace mysf
{
  class SpriteNode : public SceneNode
  {
  public:
    SpriteNode();
    explicit SpriteNode(const sf::Texture & texture);
    explicit SpriteNode(const sf::Texture & texture, const sf::IntRect & rectangle);
    SpriteNode(const SpriteNode & o) = default;
    SpriteNode & operator=(const SpriteNode & o) = default;
    virtual ~SpriteNode();

    void setTexture(const sf::Texture & texture, bool resetRect = false);
    void setTextureRect(const sf::IntRect & rectangle);
    void setColor(const sf::Color & color);

    const sf::Texture * getTexture() const;
    const sf::IntRect & getTextureRect() const;
    const sf::Color & getColor() const;

    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

  protected:
    virtual void updateCurrent(const sf::Time & deltaTime, const Event & event);
    virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;

  private:
    sf::Sprite _sprite;
  };
}

#endif // !SPRITENODE_HPP_

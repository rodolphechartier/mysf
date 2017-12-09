#ifndef TEXTNODE_HPP_
# define TEXTNODE_HPP_

# include <SFML/Graphics.hpp>

# include "SceneNode.hpp"

namespace mysf
{
  class TextNode : public SceneNode
  {
  public:
    TextNode();
    explicit TextNode(const sf::String & string, const sf::Font & font, unsigned int characterSize = 30);
    TextNode(const TextNode & o) = default;
    TextNode & operator=(const TextNode & o) = default;
    virtual ~TextNode();

    void setString(const sf::String & string);
    void setFont(const sf::Font & font);
    void setCharacterSize(unsigned int size);
    void setStyle(sf::Uint32 style);
    void setFillColor(const sf::Color & color);
    void setOutlineColor(const sf::Color & color);
    void setOutlineThickness(float thickness);

    const sf::String & getString() const;
    const sf::Font * getFont() const;
    unsigned int getCharacterSize() const;
    sf::Uint32 getStyle() const;
    const sf::Color & getFillColor() const;
    const sf::Color & getOutlineColor() const;
    float getOutlineThickness() const;
    sf::Vector2f findCharacterPos(std::size_t index) const;

    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

  protected:
    virtual void updateCurrent(const sf::Time & deltaTime, const Event & event);
    virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;

  private:
    sf::Text _text;
  };
}

#endif // !TEXTNODE_HPP_

#include "TextNode.hpp"

namespace mysf
{
    TextNode::TextNode()
    {

    }

    TextNode::TextNode(const sf::String & string, const sf::Font & font, unsigned int characterSize)
        : _text(string, font, characterSize)
    {

    }

    TextNode::~TextNode()
    {

    }

    void TextNode::setString(const sf::String & string)
    {
        _text.setString(string);
    }

    void TextNode::setFont(const sf::Font & font)
    {
        _text.setFont(font);
    }

    void TextNode::setCharacterSize(unsigned int size)
    {
        _text.setCharacterSize(size);
    }

    void TextNode::setStyle(sf::Uint32 style)
    {
        _text.setStyle(style);
    }

    void TextNode::setFillColor(const sf::Color & color)
    {
        _text.setFillColor(color);
    }

    void TextNode::setOutlineColor(const sf::Color & color)
    {
        _text.setOutlineColor(color);
    }

    void TextNode::setOutlineThickness(float thickness)
    {
        _text.setOutlineThickness(thickness);
    }

    const sf::String & TextNode::getString() const
    {
        return _text.getString();
    }

    const sf::Font * TextNode::getFont() const
    {
        return _text.getFont();
    }

    unsigned int TextNode::getCharacterSize() const
    {
        return _text.getCharacterSize();
    }

    sf::Uint32 TextNode::getStyle() const
    {
        return _text.getStyle();
    }

    const sf::Color & TextNode::getFillColor() const
    {
        return _text.getFillColor();
    }

    const sf::Color & TextNode::getOutlineColor() const
    {
        return _text.getOutlineColor();
    }

    float TextNode::getOutlineThickness() const
    {
        return _text.getOutlineThickness();
    }

    sf::Vector2f TextNode::findCharacterPos(std::size_t index) const
    {
        return _text.findCharacterPos(index);
    }

    sf::FloatRect TextNode::getLocalBounds() const
    {
        return _text.getLocalBounds();
    }

    sf::FloatRect TextNode::getGlobalBounds() const
    {
        return getTransform().transformRect(getLocalBounds());
    }

    void TextNode::updateCurrent(const sf::Time & /* deltaTime */, const Event & /* event */)
    {

    }

    void TextNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
    {
        target.draw(_text, states);
    }
}

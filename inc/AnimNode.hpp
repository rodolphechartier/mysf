#ifndef MYSF_ANIMNODE_HPP_
# define MYSF_ANIMNODE_HPP_

# include <vector>
# include <algorithm>
# include <complex>

# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>

# include "SceneNode.hpp"

namespace mysf
{
  class AnimNode : public SceneNode
  {
    struct VertexRect
    {
      sf::Vertex v[4];
    };

  public:
    explicit AnimNode(const sf::Time & frameTime = sf::seconds(0.2f), bool paused = false, bool looped = true);
    explicit AnimNode(const sf::Texture & texture, const sf::Time & frameTime = sf::seconds(0.2f), bool paused = false, bool looped = true);
    AnimNode(const AnimNode & o) = default;
    AnimNode & operator=(const AnimNode & o) = default;
    virtual ~AnimNode();

    void setTexture(const sf::Texture & texture);
    const sf::Texture * getTexture() const;
    bool addFrame(const sf::IntRect & rect);
    void setFrameTime(const sf::Time & deltaTime);
    const sf::Time & getFrameTime() const;

    void play();
    void pause();
    void stop();
    void loop(bool looped = true);
    bool isLooped() const;
    bool isPlaying() const;

    void setColor(const sf::Color & color);
    const sf::Color & getColor() const;

    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

  protected:
    virtual void updateCurrent(const sf::Time & deltaTime, const Event & event);
    virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;

  protected:
    const sf::Texture * _texture;
    std::vector<VertexRect> _vertices;
    sf::Color _color;

    sf::Time _frameTime;
    sf::Time _currTime;
    unsigned int _currFrame;
    bool _paused;
    bool _looped;
  };
}

#endif // !MYSF_ANIMNODE_HPP_

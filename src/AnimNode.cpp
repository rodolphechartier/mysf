#include "AnimNode.hpp"

namespace mysf
{
  AnimNode::AnimNode(const sf::Time & frameTime, bool paused, bool looped)
    : _texture(0)
    , _vertices(0)
    , _color(sf::Color::White)
    , _frameTime(frameTime)
    , _currTime(sf::Time::Zero)
    , _currFrame(0)
    , _paused(paused)
    , _looped(looped)
  {

  }

  AnimNode::AnimNode(const sf::Texture & texture, const sf::Time & frameTime, bool paused, bool looped)
    : _texture(&texture)
    , _vertices(0)
    , _color(sf::Color::White)
    , _frameTime(frameTime)
    , _currTime(sf::Time::Zero)
    , _currFrame(0)
    , _paused(paused)
    , _looped(looped)
  {

  }

  AnimNode::~AnimNode()
  {

  }

  void AnimNode::setTexture(const sf::Texture & texture)
  {
    _texture = &texture;
  }

  const sf::Texture * AnimNode::getTexture() const
  {
    return _texture;
  }

  void AnimNode::addFrame(const sf::IntRect & rect)
  {
    static sf::VertexArray varr(sf::Quads, 4);

    varr[0].position = sf::Vector2f(0.f, 0.f);
    varr[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
    varr[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
    varr[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

    float left = static_cast<float>(rect.left) + 0.0001f;
    float right = left + static_cast<float>(rect.width);
    float top = static_cast<float>(rect.top);
    float bottom = top + static_cast<float>(rect.height);

    varr[0].texCoords = sf::Vector2f(left, top);
    varr[1].texCoords = sf::Vector2f(left, bottom);
    varr[2].texCoords = sf::Vector2f(right, bottom);
    varr[3].texCoords = sf::Vector2f(right, top);

    if (varr[0].color != _color)
    {
      varr[0].color = _color;
      varr[1].color = _color;
      varr[2].color = _color;
      varr[3].color = _color;
    }

    _vertices.push_back(varr);
  }

  void AnimNode::setFrameTime(const sf::Time & deltaTime)
  {
    _frameTime = deltaTime;
  }

  const sf::Time & AnimNode::getFrameTime() const
  {
    return _frameTime;
  }

  void AnimNode::play()
  {
    _paused = false;
  }

  void AnimNode::pause()
  {
    _paused = true;
  }

  void AnimNode::stop()
  {
    _paused = true;
    _currFrame = 0;
  }

  void AnimNode::loop(bool looped)
  {
    _looped = looped;
  }

  bool AnimNode::isLooped() const
  {
    return _looped;
  }

  bool AnimNode::isPlaying() const
  {
    return !_paused;
  }

  void AnimNode::setColor(const sf::Color & color)
  {
    _color = color;
    for (unsigned int i = 0; i < _vertices.size(); ++i)
    {
      _vertices[i][0].color = _color;
      _vertices[i][1].color = _color;
      _vertices[i][2].color = _color;
      _vertices[i][3].color = _color;
    }
  }

  const sf::Color & AnimNode::getColor() const
  {
    return _color;
  }

  sf::FloatRect AnimNode::getLocalBounds() const
  {
    // sf::Vector2f size(_vertices[_currFrame][2].position);

    return _vertices[_currFrame].getBounds();
    // return sf::FloatRect(0.f, 0.f, std::abs(size.x), std::abs(size.y));
  }

  sf::FloatRect AnimNode::getGlobalBounds() const
  {
    return getTransform().transformRect(getLocalBounds());
  }

  void AnimNode::updateCurrent(const sf::Time & deltaTime, const Event & /* event */)
  {
    if (_paused)
      return ;
    _currTime += deltaTime;
    if (_currTime < _frameTime)
      return ;
    _currTime = sf::microseconds(_currTime.asMicroseconds() % _frameTime.asMicroseconds());
    if (_currFrame + 1 < _vertices.size())
      ++_currFrame;
    else
    {
      if (_looped)
        _currFrame = 0;
      else
        _paused = true;
    }
  }

  void AnimNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
  {
    if (!_texture)
      return ;
    states.texture = _texture;
    target.draw(_vertices[_currFrame], states);
  }
}

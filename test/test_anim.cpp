#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "Engine.hpp"
#include "GraphicRender.hpp"
#include "ResourceHolder.hpp"
#include "AnimNode.hpp"

static const unsigned int Scale = 10;
static const sf::Time frameTime(sf::seconds(0.2f));

template <typename T>
std::ostream & operator<<(std::ostream & os, const sf::Rect<T> & rect)
{
  return os << "x: " << rect.left << "; y: " << rect.top << "; w: " << rect.width << "; h: " << rect.height;
}

class Render : public mysf::GraphicRender
{
public:
  Render(sf::RenderWindow & window, int ac, char ** av)
    : _ac(ac)
    , _av(av)
    , _window(window)
    , _select(0)
  {
    _gls.resize(1);
  }

  virtual ~Render()
  {
    _thl.unload();
  }

  virtual bool init()
  {
    try {
      _spriteSize.x = std::stoul(_av[1]);
      _spriteSize.y = std::stoul(_av[2]);
    } catch (const std::out_of_range & e) {
      return false;
    }

    std::cout << "Loading Animations..." << std::endl;
    if (_thl.setDefault("resources/images/default.png") == false)
    {
      std::cerr << "failed to load default texture" << std::endl;
      return false;
    }
    _anims.resize(_ac - 3);
    for (int i = 0; i < _ac - 3; ++i)
    {
      if (_thl.load(i, _av[i + 3]) == false)
        std::cerr << "Cannot load anim: " << _av[i + 3] << std::endl;
      _buildAnim(_anims[i], _thl[i]);
    }
    std::cout << "Animations Loaded" << std::endl;

    _windowSize = sf::Vector2u(_spriteSize * Scale);
    _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), "Test");

    _gls[0].add(&_anims[_select]);
    _anims[_select].play();
    return true;
  }

  virtual GraphicRender * onUpdate(const sf::Time & /* deltaTime */, const mysf::Event & event)
  {
    if (event.isClosed() || event.key().isDown(sf::Keyboard::Escape))
      return 0;
    if (event.key().isDown(sf::Keyboard::Left) || event.key().isDown(sf::Keyboard::Down))
    {
      _anims[_select].stop();
      _gls[0].sub(&_anims[_select]);
      _select = _select ? _select - 1 : _anims.size() - 1;
      _gls[0].add(&_anims[_select]);
      _anims[_select].play();
    }
    if (event.key().isDown(sf::Keyboard::Right) || event.key().isDown(sf::Keyboard::Up))
    {
      _anims[_select].stop();
      _gls[0].sub(&_anims[_select]);
      _select = (_select + 1) % _anims.size();
      _gls[0].add(&_anims[_select]);
      _anims[_select].play();
    }
    return this;
  }

private:
  void _buildAnim(mysf::AnimNode & anim, const sf::Texture & texture)
  {
    anim.setTexture(texture);
    for (unsigned int i = 0; i < texture.getSize().x / _spriteSize.x; ++i)
      anim.addFrame(sf::IntRect(i * _spriteSize.x, 0, _spriteSize.x, _spriteSize.y));
    anim.setFrameTime(frameTime);
    anim.setScale(Scale, Scale);
    anim.loop(true);
    anim.stop();
  }

private:
  int _ac;
  char ** _av;

  sf::RenderWindow & _window;
  mysf::TextureHolder _thl;

  sf::Vector2u _spriteSize;
  sf::Vector2u _windowSize;

  std::vector<mysf::AnimNode> _anims;
  unsigned int _select;
};

// Creating the engine that will handle your differents GraphicRenders
class Main : public mysf::Engine<sf::RenderWindow>
{
public:
  virtual bool init(int ac, char ** av)
  {
    _grender = new Render(_window, ac, av);
    _event.key().setEventType(mysf::OnPressed);
    _event.mouse().setEventType(mysf::OnPressed);
    if (ac < 4)
    {
      std::cerr << av[0] << ": [sprite_size_x] [sprite_size_y] [anim_path [...]]" << std::endl;
      return 1;
    }
    return _grender->init();
  }
};

// Instantiate Engine, initialize it and run it
int main(int ac, char ** av)
{
  Main test;

  if (test.init(ac, av) == false)
    return 1;
  return test.run();
}

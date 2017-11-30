#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "Engine.hpp"
#include "GraphicRender.hpp"
#include "ResourceHolder.hpp"
#include "AnimNode.hpp"

static const unsigned int Scale = 10;
static const sf::Time frameTime(sf::seconds(0.2f));
static const sf::Vector2u SpriteSize = sf::Vector2u(52, 89);
static const sf::Vector2u WindowSize = sf::Vector2u(SpriteSize * Scale);

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
    std::cout << "Loading Animations..." << std::endl;
    if (_thl.setDefault("resources/images/default.png") == false)
    {
      std::cerr << "failed to load default texture" << std::endl;
      return false;
    }
    _anims.resize(_ac - 1);
    for (int i = 1; i < _ac; ++i)
    {
      if (_thl.load(i - 1, _av[i]) == false)
        std::cerr << "Cannot load anim: " << _av[i] << std::endl;
      _buildAnim(_anims[i - 1], _thl[i - 1]);
    }
    std::cout << "Animations Loaded" << std::endl;
    _window.create(sf::VideoMode(WindowSize.x, WindowSize.y), "Test");
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
      _gls[0].remove(&_anims[_select]);
      _select = _select ? _select - 1 : _anims.size() - 1;
      _gls[0].add(&_anims[_select]);
      _anims[_select].play();
    }
    if (event.key().isDown(sf::Keyboard::Right) || event.key().isDown(sf::Keyboard::Up))
    {
      _anims[_select].stop();
      _gls[0].remove(&_anims[_select]);
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
    for (unsigned int i = 0; i < texture.getSize().x / SpriteSize.x; ++i)
      anim.addFrame(sf::IntRect(i * SpriteSize.x, 0, SpriteSize.x, SpriteSize.y));
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

  std::vector<mysf::AnimNode> _anims;
  unsigned int _select;
};

// Creating the engine that will handle your differents GraphicRenders
class Main : public mysf::Engine<>
{
public:
  virtual bool init(int ac, char ** av)
  {
    _grender = new Render(_window, ac, av);
    _event.key().setEventType(mysf::OnPressed);
    _event.mouse().setEventType(mysf::OnPressed);
    if (ac < 2)
    {
      std::cerr << av[0] << ": [anim_path [...]]" << std::endl;
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

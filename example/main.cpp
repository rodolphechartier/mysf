#include "../inc/Mysf.hpp"

class Node : public mysf::SpriteNode
{
public:
  Node() : mysf::SpriteNode(), _speed(500.f) {}

  Node(const Node &) = delete;
  Node & operator=(const Node &) = delete;
  virtual ~Node() {}

protected:
  virtual void updateCurrent(const sf::Time & deltaTime, const mysf::Input & input)
  {
    sf::Vector2f pos(getPosition());
    const float move = deltaTime.asSeconds() * _speed;

    if (input.key()[sf::Keyboard::W])
      pos.y -= move;
    if (input.key()[sf::Keyboard::A])
      pos.x -= move;
    if (input.key()[sf::Keyboard::S])
      pos.y += move;
    if (input.key()[sf::Keyboard::D])
      pos.x += move;
    setPosition(pos);
  }

private:
  float _speed;
};

class Render : public mysf::GraphicRender
{
public:
  explicit Render(mysf::Context & ctx) : mysf::GraphicRender(ctx) {}
  Render(const Render &) = delete;
  Render & operator=(const Render &) = delete;
  virtual ~Render() {}

  virtual bool init()
  {
    _ctx.gls.resize(1);
    _ctx.gls.clear();

    _def.setTexture(_ctx.thl.getDefault());
    _ctx.gls[0].add(&_def);
    return true;
  }

private:
  Node _def;
};

class Main : public mysf::Engine
{
public:
  Main() : mysf::Engine() {}
  Main(const Main &) = delete;
  Main & operator=(const Main &) = delete;
  virtual ~Main() {}

  virtual bool init(int /* ac */, char ** /* av */)
  {
    _grender = new Render(_ctx);

    _ctx.win.create(sf::VideoMode(800, 450), "Test");
    if (_ctx.thl.setDefault("../rsc/default.png") == false)
      return false;
    return _grender->init();
  }
};

int main(int ac, char ** av)
{
  Main test;

  if (test.init(ac, av) == false)
    return 1;
  return test.run();
}

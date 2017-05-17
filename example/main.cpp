#include "../inc/Mysf.hpp"

class Node : public mysf::SpriteNode
{
	enum Action
	{
		Up,
		Left,
		Down,
		Right,
		ActionCount
	};

public:
  explicit Node()
		: mysf::SpriteNode()
		, _bind()
		, _speed(500.f)
	{
		_bind.setNbAction(ActionCount);
		_bind.setBind(Up, mysf::Binding::InputCode(mysf::Binding::KeyboardInput, sf::Keyboard::Z));
		_bind.setBind(Left, mysf::Binding::InputCode(mysf::Binding::KeyboardInput, sf::Keyboard::Q));
		_bind.setBind(Down, mysf::Binding::InputCode(mysf::Binding::KeyboardInput, sf::Keyboard::S));
		_bind.setBind(Right, mysf::Binding::InputCode(mysf::Binding::KeyboardInput, sf::Keyboard::D));
	}

  Node(const Node &) = delete;
  Node & operator=(const Node &) = delete;
  virtual ~Node() {}

protected:
  virtual void updateCurrent(const sf::Time & deltaTime, const mysf::Input & input)
  {
    sf::Vector2f pos(getPosition());
    const float move = deltaTime.asSeconds() * _speed;

    if (_bind.isDown(Up, input))
      pos.y -= move;
    if (_bind.isDown(Left, input))
      pos.x -= move;
    if (_bind.isDown(Down, input))
      pos.y += move;
    if (_bind.isDown(Right, input))
      pos.x += move;
    setPosition(pos);
  }

private:
	mysf::Binding _bind;
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

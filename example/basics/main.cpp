#include <iostream>

#include "Mysf.hpp"

namespace Action
{
  enum
	{
	  Up,
	  Left,
	  Down,
	  Right,
	  Quit,
	  ActionCount
	};
}

// Creating node where inputs are handle and sprite is display
class Node : public mysf::SceneNode
{
public:
  explicit Node(mysf::Binding & bind)
	: mysf::SceneNode()
	, _bind(bind)
	, _speed(100.f)
  {

  }

  void setTexture(const sf::Texture & texture)
  {
	_sprite.setTexture(texture);
  }

protected:
  virtual void updateCurrent(const sf::Time & deltaTime, const mysf::Event & event)
  {
	sf::Vector2f pos(getPosition());
	const float move = deltaTime.asSeconds() * _speed;

	if (_bind.getInput(Action::Up, event))
	  pos.y -= move;
	if (_bind.getInput(Action::Left, event))
	  pos.x -= move;
	if (_bind.getInput(Action::Down, event))
	  pos.y += move;
	if (_bind.getInput(Action::Right, event))
	  pos.x += move;
	setPosition(pos);
  }

  virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
  {
	target.draw(_sprite, states);
  }

private:
  sf::Sprite _sprite;
  mysf::Binding & _bind;
  float _speed;
};

// Creating a GraphicRender to be run by the engine
class Render : public mysf::GraphicRender
{
public:
  Render(sf::RenderWindow & window)
	: _window(window)
	, _bind(Action::ActionCount)
	, _node(_bind)
  {
	std::map<std::string, unsigned int> bind;

	_gls.resize(1);
	_gls[0].add(&_node);

	// Assign string to value (bind[string] = enumValue)
	bind["Up"] = Action::Up;
	bind["Left"] = Action::Left;
	bind["Down"] = Action::Down;
	bind["Right"] = Action::Right;
	bind["Quit"] = Action::Quit;
	_bind.load("key.conf", bind);
  }

  virtual bool init()
  {
	if (_thl.setDefault("../../rsc/default.png") == false)
	  return false;
	_window.create(sf::VideoMode(800, 450), "Test");
	_node.setTexture(_thl.getDefault());
	return true;
  }

  virtual mysf::GraphicRender * onUpdate(const sf::Time & /* deltaTime */, const mysf::Event & event)
  {
	if (_bind.getInput(Action::Quit, event) || event.isClosed())
	  return 0;
	return this;
  }

private:
  sf::RenderWindow & _window;
  mysf::TextureHolder _thl;
  mysf::Binding _bind;
  Node _node;
};

// Creating the engine that will handle your differents GraphicRenders
class Main : public mysf::Engine<sf::RenderWindow>
{
public:
  virtual bool init(int /* ac */, char ** /* av */)
  {
	_grender = new Render(_window);
	// _event.key().setEventType(mysf::OnPressed);
	// _event.mouse().setEventType(mysf::OnPressed);
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

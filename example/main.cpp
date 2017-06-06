#include <iostream>

#include "../inc/Mysf.hpp"

// Creating node where inputs are handle and sprite is display
class Node : public mysf::SceneNode
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
		: mysf::SceneNode()
		, _bind(ActionCount)
		, _speed(1.f)
	{
		std::map<std::string, unsigned int> bind;

		bind["Up"] = Up;
		bind["Left"] = Left;
		bind["Down"] = Down;
		bind["Right"] = Right;
		_bind.load("key.conf", bind);
	}

	void setTexture(const sf::Texture & texture)
	{
		_sprite.setTexture(texture);
	}

protected:
  virtual void updateCurrent(const sf::Time & /* deltaTime */, const mysf::Event & event)
  {
    sf::Vector2f pos(getPosition());
		// const float move = deltaTime.asSeconds() * _speed;
		const unsigned int move = (unsigned int)_speed;

    if (_bind.getInput(Up, event))
      pos.y -= move;
    if (_bind.getInput(Left, event))
      pos.x -= move;
    if (_bind.getInput(Down, event))
      pos.y += move;
    if (_bind.getInput(Right, event))
      pos.x += move;
    setPosition(pos);
  }

	virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(_sprite, states);
	}

private:
	sf::Sprite _sprite;
	mysf::Binding _bind;
  float _speed;
};

// Creating a GraphicRender to be run by the engine
class Render : public mysf::GraphicRender
{
public:
	Render()
	{
    _gls.resize(1);
    _gls[0].add(&_node);
  }

	virtual bool init()
	{
		if (_thl.setDefault("../rsc/default.png") == false)
			return false;
		_node.setTexture(_thl.getDefault());
		return true;
	}

private:
	mysf::TextureHolder _thl;
  Node _node;
};

// Creating the engine that will handle your differents GraphicRenders
class Main : public mysf::Engine
{
public:
  virtual bool init(int /* ac */, char ** /* av */)
  {
		_window = new sf::RenderWindow(sf::VideoMode(800, 450), "Test");
		_grender = new Render;
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

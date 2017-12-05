#include "Game.hpp"

const sf::Vector2u Game::WindowSize(1500, 800);

Game::Game(sf::RenderWindow & window)
	: _window(window)
	, _helicopter(_bind)
{

}

Game::~Game()
{

}

bool Game::init()
{
	if (initBinding() == false)
		return false;
	if (_thl.setDefault("rsc/img/default.png") == false)
		return false;
	_thl.load(Resource::Texture::Helicopter, "rsc/img/helicopter.png");
	if (_helicopter.init(_thl) == false)
		return false;

	_gls.resize(1);
	_gls[0].add(&_helicopter);
	_window.create(sf::VideoMode(WindowSize.x, WindowSize.y), "Cavern Escape");
	_window.setFramerateLimit(60);
	return true;
}

mysf::GraphicRender * Game::onUpdate(const sf::Time & /* deltaTime */, const mysf::Event & event)
{
	if (_bind.getInput(Action::Quit, event) || event.isClosed())
		return 0;
	return this;
}

bool Game::initBinding()
{
	std::map<std::string, unsigned int> bind;

	bind["Up"] = Action::Up;
	bind["Left"] = Action::Left;
	bind["Down"] = Action::Down;
	bind["Right"] = Action::Right;
	bind["Quit"] = Action::Quit;
	return _bind.load("rsc/conf/key.conf", bind);
}

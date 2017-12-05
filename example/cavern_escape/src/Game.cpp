#include "Game.hpp"

const sf::Vector2u Game::WindowSize(1500, 800);

Game::Game(sf::RenderWindow & window)
	: _window(window)
{

}

Game::~Game()
{

}

bool Game::init()
{
	if (_thl.setDefault("rsc/img/default.png") == false)
		return false;
	_thl.load(Resource::Texture::Helicopter, "rsc/img/helicopter.png");
	if (_helicopter.init(_thl) == false)
		return false;

	_gls.resize(1);
	_gls[0].add(&_helicopter);
	_window.create(sf::VideoMode(WindowSize.x, WindowSize.y), "Cavern Escape");
	return true;
}

mysf::GraphicRender * Game::onUpdate(const sf::Time & /* deltaTime */, const mysf::Event & event)
{
	if (event.isClosed())
		return 0;
	return this;
}

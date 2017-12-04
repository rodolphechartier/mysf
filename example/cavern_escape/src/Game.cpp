#include "Game.hpp"

const sf::Vector2u Game::WindowSize(750, 500);

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
	_window.create(sf::VideoMode(WindowSize.x, WindowSize.y), "Cavern Escape");
	return true;
}

mysf::GraphicRender * Game::onUpdate(const sf::Time & /* deltaTime */, const mysf::Event & event)
{
	if (event.isClosed())
		return 0;
	return this;
}

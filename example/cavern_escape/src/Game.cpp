#include "Game.hpp"

const sf::Vector2u Game::WindowSize(1500, 800);

Game::Game(sf::RenderWindow & window)
	: _window(window)
	, _helicopter(_bind, window, _map)
{

}

Game::~Game()
{
	_thl.unload();
}

bool Game::init()
{
	if (initBinding() == false)
		return false;
	if (_thl.setDefault("rsc/img/default.png") == false)
		return false;
	_thl.load(Resource::Texture::Background, "rsc/img/background.png");
	_thl.load(Resource::Texture::CavernWall, "rsc/img/cavern_wall_01.png");
	_thl.load(Resource::Texture::Helicopter, "rsc/img/helicopter.png");

	if (_fhl.setDefault("rsc/font/default.ttf") == false)
		return false;
	_fhl.load(Resource::Font::VcrOsd, "rsc/font/vcr_osd.ttf");
	_fhl.load(Resource::Font::ComfortaaRegular, "rsc/font/comfortaa_regular.ttf");
	_fhl.load(Resource::Font::ComfortaaLight, "rsc/font/comfortaa_light.ttf");
	_fhl.load(Resource::Font::ComfortaaBold, "rsc/font/comfortaa_bold.ttf");

	_gls.resize(3);

	_background.setTexture(_thl[Resource::Texture::Background]);
	_background.setSize(sf::Vector2f(WindowSize));
	_helicopter.setPosition(sf::Vector2f(10, WindowSize.y / 2));
	if (_helicopter.init(_gls, _thl, _fhl) == false)
		return false;
	_map.setTexture(_thl[Resource::Texture::CavernWall]);
	_map.gen(WindowSize, _helicopter.getGlobalBounds().height + _helicopter.getGlobalBounds().width + 20);

	_gls[0].add(&_background);
	_gls[1].add(&_map);
	_gls[1].add(&_helicopter);

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

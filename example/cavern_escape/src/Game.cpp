#include "Game.hpp"

const sf::Vector2f Game::WindowSize(1500.f, 800.f);

Game::Game(mysf::Engine<sf::RenderWindow> & engine, sf::RenderWindow & window)
	: _engine(engine)
	, _window(window)
	, _helicopter(_bind, window, _map, _score)
	, _gameover(engine, window, _helicopter, _map)
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

	_background.setTexture(_thl[Resource::Texture::Background]);
	_background.setSize(WindowSize);
	_helicopter.setPosition(sf::Vector2f(15.f, WindowSize.y / 2.f));
	if (_helicopter.init(_thl) == false)
		return false;
	_score.setCharacterSize(40);
	_score.setPosition(sf::Vector2f(10.f, 10.f));
	_score.setFont(_fhl[Resource::Font::VcrOsd]);

	_map.setTexture(_thl[Resource::Texture::CavernWall]);
	_map.gen(WindowSize, _helicopter.getGlobalBounds().height + _helicopter.getGlobalBounds().width + 20);

	_gls.resize(3);
	_gls[0].add(&_background);
	_gls[1].add(&_map);
	_gls[1].add(&_helicopter);
	_gls[2].add(&_score);

	if (_gameover.init(&_gls[2], _fhl[Resource::Font::VcrOsd]) == false)
		return false;

	_window.create(sf::VideoMode(WindowSize.x, WindowSize.y), "Cavern Escape");
	_window.setFramerateLimit(60);
	_window.setVerticalSyncEnabled(true);
	return true;
}

mysf::GraphicRender * Game::onUpdate(const sf::Time & deltaTime, const mysf::Event & event)
{
	static sf::Time time(sf::Time::Zero);
    static const sf::Time stage(sf::seconds(10.f));

	if (_bind.getInput(Action::Quit, event) || event.isClosed())
		return 0;
	if (_helicopter.getState() == Helicopter::State::Destroy)
		return _gameover(event, this);

	time += deltaTime;
	if (time > stage)
	{
        _map.addSpeed(50.f);
		time -= stage;
	}
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

#include "Game.hpp"

const sf::Vector2u Game::WindowSize(1500, 800);

Game::Game(mysf::Engine<sf::RenderWindow> & engine, sf::RenderWindow & window)
	: _engine(engine)
	, _window(window)
	, _helicopter(_bind, window, _map, _score)
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
	_background.setSize(sf::Vector2f(WindowSize));
	_helicopter.setPosition(sf::Vector2f(10, WindowSize.y / 2));
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

	_window.create(sf::VideoMode(WindowSize.x, WindowSize.y), "Cavern Escape");
	_window.setFramerateLimit(60);
	return true;
}

mysf::GraphicRender * Game::onUpdate(const sf::Time & deltaTime, const mysf::Event & event)
{
	static sf::Time time(sf::Time::Zero);

	if (_bind.getInput(Action::Quit, event) || event.isClosed())
		return 0;
	if (_helicopter.getState() == Helicopter::State::Destroy)
		return gameover(event);
	time += deltaTime;
	if (time > sf::seconds(15.f))
	{
		_engine.multiplySpeed(1.01f);
		time -= sf::seconds(15.f);
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

mysf::GraphicRender * Game::gameover(const mysf::Event & event)
{
	static bool called = false;
	static mysf::TextNode text;

	if (event.key().isDown(sf::Keyboard::R))
	{
		_engine.play();
		return new Game(_engine, _window);
	}
	if (called)
		return this;

	_engine.pause();
	text.setCharacterSize(60);
	text.setFont(_fhl[Resource::Font::VcrOsd]);
	text.setString("Game Over\nScore: " + std::to_string(_score.getValue()));
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(sf::Vector2f(WindowSize) / 2.f);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2.f);
	_gls[2].add(&text);
	called = true;
	return this;
}

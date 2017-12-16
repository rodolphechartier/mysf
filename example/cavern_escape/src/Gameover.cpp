#include "Gameover.hpp"
#include "Game.hpp"

Gameover::Gameover(mysf::Engine<sf::RenderWindow> & engine, sf::RenderWindow & window, Helicopter & helicopter)
	: _engine(engine)
	, _window(window)
	, _helicopter(helicopter)
	, _layer(0)
	, _added(false)
{

}

Gameover::~Gameover()
{

}

bool Gameover::init(mysf::GraphicLayer * layer, const sf::Font & font)
{
	if (!layer)
		return false;
	_layer = layer;
	_text.setFont(font);
	_text.setCharacterSize(std::min(Game::WindowSize.x, Game::WindowSize.y) / 4.f);
	_text.setString("Game Over");
	_text.setOrigin(_text.getLocalBounds().width / 2.f, _text.getLocalBounds().height / 2.f);
	_text.setPosition(Game::WindowSize / 2.f);
	_text.setFillColor(sf::Color::White);
	_text.setOutlineColor(sf::Color::Black);
	_text.setOutlineThickness(4.f);

	_continue.setFont(font);
	_continue.setCharacterSize(std::min(Game::WindowSize.x, Game::WindowSize.y) / 10.f);
	_continue.setString("Continue ? (press R)");
	_continue.setOrigin(_continue.getLocalBounds().width / 2.f, _continue.getLocalBounds().height / 2.f);
	_continue.setPosition(Game::WindowSize.x / 2.f, Game::WindowSize.y / 2.f + _text.getLocalBounds().height);
	_continue.setFillColor(sf::Color::White);
	_continue.setOutlineColor(sf::Color::Black);
	_continue.setOutlineThickness(3.f);
	return true;
}

mysf::GraphicRender * Gameover::operator()(const mysf::Event & event, mysf::GraphicRender * parent)
{
	if (_added == false)
	{
		_layer->add(this);
		_added = true;
	}

	if (_engine.getSpeed() && !_helicopter.isPlaying())
		_engine.pause();
	if (event.key().isDown(sf::Keyboard::R))
		return new Game(_engine, _window);
	return parent;
}

void Gameover::updateCurrent(const sf::Time & /* deltaTime */, const mysf::Event & /* event */)
{

}

void Gameover::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_text, states);
	target.draw(_continue, states);
}

#include "Helicopter.hpp"

Helicopter::Helicopter(const mysf::Binding & bind, const sf::RenderWindow & window, const Map & map)
	: _bind(bind)
	, _window(window)
	, _map(map)
	, _state(Helicopter::State::Idle)
	, _speed(200.f)
	, _life(1000)
{

}

bool Helicopter::init(const mysf::TextureHolder & thl)
{
	_anims.resize(Helicopter::State::Size);
	_anims[Helicopter::State::Idle].reset(new HelicopterIdle(thl));
	_anims[Helicopter::State::Hit].reset(new HelicopterHit(thl));
	_anims[Helicopter::State::Destroy].reset(new HelicopterDestroy(thl));

	addChild(&_life);
	_life.setSize(sf::Vector2f(200.f, 10.f));
	_life.setOrigin(_life.getSize() / 2.f);
	_life.setPosition(sf::Vector2f(getGlobalBounds().width / 2.f, -15.f));
	return true;
}

void Helicopter::hit(unsigned int damage)
{
	_life.sub(damage);
	_anims[_state]->stop();
	_state = _life ? Helicopter::Hit : Helicopter::State::Destroy;
	_anims[_state]->play();
}

sf::FloatRect Helicopter::getLocalBounds() const
{
	return _anims[_state]->getLocalBounds();
}

sf::FloatRect Helicopter::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}

void Helicopter::updateCurrent(const sf::Time & deltaTime, const mysf::Event & event)
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

	colision(pos);
	if (_state != Helicopter::State::Destroy && _anims[_state]->isPlaying() == false)
	{
		_anims[_state]->stop();
		_state = Helicopter::State::Idle;
		_anims[_state]->play();
	}
	_anims[_state]->update(deltaTime, event);
}

void Helicopter::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	_anims[_state]->draw(target, states);
}

void Helicopter::colision(sf::Vector2f & pos)
{
	if (pos.x < 0)
		pos.x = 0;
	if (pos.y < 0)
		pos.y = 0;
	if (pos.x >= _window.getSize().x - getGlobalBounds().width)
		pos.x = _window.getSize().x - getGlobalBounds().width - 1;
	if (pos.y >= _window.getSize().y - getGlobalBounds().height)
		pos.y = _window.getSize().y - getGlobalBounds().height - 1;

	setPosition(pos);
	if (_map.intersects(getGlobalBounds()))
		hit(5);
}

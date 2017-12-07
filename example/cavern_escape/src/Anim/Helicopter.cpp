#include "Helicopter.hpp"

Helicopter::Helicopter(const mysf::Binding & bind, const Map & map)
	: _bind(bind)
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
	return true;
}

void Helicopter::hit(unsigned int damage)
{
	if (_life)
	{
		_life = _life > damage ? 0 : _life - damage;
		_anims[_state]->stop();
		_state = _life ? Helicopter::Hit : Helicopter::State::Destroy;
		_anims[_state]->play();
	}
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
	// const sf::Vector2f lastPos(pos);
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
	if (_map.intersects(getGlobalBounds()))
	{
		hit(5);
		// setPosition(lastPos);
	}
	_anims[_state]->update(deltaTime, event);
}

void Helicopter::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	_anims[_state]->draw(target, states);
}

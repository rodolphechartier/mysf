#include "Helicopter.hpp"

Helicopter::Helicopter(const mysf::Binding & bind)
	: _bind(bind)
	, _state(Helicopter::State::Idle)
	, _speed(200.f)
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

sf::FloatRect Helicopter::getLocalBounds() const
{
	return _anims[_state]->getLocalBounds();
}

sf::FloatRect Helicopter::getGlobalBounds() const
{
	return _anims[_state]->getGlobalBounds();
}

// TODO: manage _state
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
	setPosition(pos);
	_anims[_state]->update(deltaTime, event);
}

void Helicopter::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	_anims[_state]->draw(target, states);
}

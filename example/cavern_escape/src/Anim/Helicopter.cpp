#include "Helicopter.hpp"

Helicopter::Helicopter()
	: _anims(Helicopter::State::Size, 0)
	, _state(Helicopter::State::Idle)
{
	_anims[Helicopter::State::Idle].reset(new HelicopterIdle);
	_anims[Helicopter::State::Hit].reset(new HelicopterHit);
	_anims[Helicopter::State::Destroy].reset(new HelicopterDestroy);
}

// TODO: manage _state
void Helicopter::updateCurrent(const sf::Time & deltaTime, const mysf::Event & event)
{
	_anims[_state]->update(deltaTime, event);
}

void Helicopter::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	_anims[_state]->draw(target, states);
}

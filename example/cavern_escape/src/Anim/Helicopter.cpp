#include "Helicopter.hpp"

Helicopter::Helicopter()
	: _state(Helicopter::State::Idle)
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

// TODO: manage _state
void Helicopter::updateCurrent(const sf::Time & deltaTime, const mysf::Event & event)
{
	_anims[_state]->update(deltaTime, event);
}

void Helicopter::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	_anims[_state]->draw(target, states);
}

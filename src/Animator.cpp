#include "Animator.hpp"

namespace mysf
{
	Animator::Animator(unsigned int nb)
		: _animations(nb)
	{

	}

	Animation & Animator::operator[](unsigned int state)
	{
		return _animations[state];
	}

	const Animation & Animator::operator[](unsigned int state) const
	{
		return _animations[state];
	}

	Animation & Animator::current()
	{
		return _animations[_state];
	}

	const Animation & Animator::current() const
	{
		return _animations[_state];
	}

	bool Animator::setState(unsigned int state)
	{
		if (state >= _animations.size())
			return false;
		_animations[_state].stop();
		_state = state;
		_animations[_state].play();
		return true;
	}

	unsigned int Animator::getState() const
	{
		return _state;
	}

	bool Animator::setDefaultState(unsigned int state)
	{
		if (state >= _animations.size())
			return false;
		_default = state;
		return true;
	}

	unsigned int Animator::getDefaultState() const
	{
		return _default;
	}

	void Animator::resize(unsigned int size)
	{
		_animations.resize(size);
	}

	void Animator::add(Animation & animation)
	{
		_animations.push_back(animation);
	}

	void Animator::clear()
	{
		_animations.clear();
	}

	unsigned int Animator::size() const
	{
		return _animations.size();
	}

	void Animator::update(const sf::Time & deltaTime)
	{
		if (_animations[_state].isPlaying() == false)
			_state = _default;
		_animations[_state].update(deltaTime);
	}

	void Animator::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(_animations[_state], states);
	}
}

#include "AnimNode.hpp"

namespace mysf
{
	AnimNode::AnimNode(const sf::Time & frameTime, bool paused, bool looped)
		: _texture(0)
		, _vertices(0)
		, _color(sf::Color())
		, _frameTime(frameTime)
		, _currTime(sf::Time::Zero)
		, _currFrame(0)
		, _paused(paused)
		, _looped(looped)
	{

	}

	AnimNode::AnimNode(const sf::Texture & texture, const sf::Time & frameTime, bool isPaused, bool isLooped)
		: _texture(texture)
		, _vertices(0)
		, _color(sf::Color())
		, _frameTime(frameTime)
		, _currTime(sf::Time::Zero)
		, _currFrame(0)
		, _paused(paused)
		, _looped(looped)
	{

	}

	AnimNode::~AnimNode()
	{

	}

	void AnimNode::setTexture(const sf::Texture & texture)
	{
		_texture = &texture;
	}

	const sf::Texture * AnimNode::getTexture() const
	{
		return _texture;
	}

	// TODO
	void AnimNode::addFrame(const sf::IntRect & rect)
	{
		if (!_texture)
			return;
		_vertices.push_back();
	}

	void AnimNode::setFrameTime(const sf::Time & deltaTime)
	{
		_frameTime = deltaTime;
	}

	const sf::Time & AnimNode::getFrameTime() const
	{
		return _frameTime;
	}

	void AnimNode::play()
	{
		_paused = false;
	}

	void AnimNode::pause()
	{
		_paused = true;
	}

	void AnimNode::stop()
	{
		_paused = true;
		_currFrame = 0;
	}

	void AnimNode::setLooped(bool looped)
	{
		_looped = looped;
	}

	bool AnimNode::isLooped() const
	{
		return _looped;
	}

	bool AnimNode::isPlaying() const
	{
		return !_paused;
	}

	void AnimNode::setColor(const sf::Color & color)
	{
		_color = color;
		for (unsigned int i = 0; i < _vertices.size(); ++i)
			for (unsigned int j = 0; j < 4; ++j)
				_vertices[i][j].color = _color;
	}

	const sf::Color & AnimNode::getColor() const
	{
		return _color;
	}

	void AnimNode::updateCurrent(const sf::Time & deltaTime, const Event & event)
	{
		if (_paused)
			return ;
		_currTime += deltaTime;
		if (_currTime < _frameTime)
			return ;
		_currTime = sf::microseconds(_currTime.asMicroseconds() % _frameTime.asMicroseconds());
		if (_currFrame + 1 < _frames.size())
			++_currFrame;
		else
		{
			if (_looped)
				_currFrame = 0;
			else
				_paused = true;
		}
	}

	void AnimNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
	{
		if (!_texture)
			return ;
		states.texture = m_texture;
		target.draw(_vertices[_currFrame], 4, sf::Quads, states);
	}
}

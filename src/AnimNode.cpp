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

	AnimNode::AnimNode(const sf::Texture & texture, const sf::Time & frameTime, bool paused, bool looped)
		: _texture(&texture)
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

	bool AnimNode::addFrame(const sf::IntRect & rect)
	{
		static VertexRect vr;

		if (!_texture)
			return false;
		vr.v[0].position = sf::Vector2f(0.f, 0.f);
		vr.v[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
		vr.v[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
		vr.v[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

		float left = static_cast<float>(rect.left) + 0.0001f;
		float right = left + static_cast<float>(rect.width);
		float top = static_cast<float>(rect.top);
		float bottom = top + static_cast<float>(rect.height);

		vr.v[0].texCoords = sf::Vector2f(left, top);
		vr.v[1].texCoords = sf::Vector2f(left, bottom);
		vr.v[2].texCoords = sf::Vector2f(right, bottom);
		vr.v[3].texCoords = sf::Vector2f(right, top);

		if (vr.v[0].color != _color)
		{
			vr.v[0].color = _color;
			vr.v[1].color = _color;
			vr.v[2].color = _color;
			vr.v[3].color = _color;
		}

		_vertices.push_back(vr);
		return true;
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
		{
			_vertices[i].v[0].color = _color;
			_vertices[i].v[1].color = _color;
			_vertices[i].v[2].color = _color;
			_vertices[i].v[3].color = _color;
		}
	}

	const sf::Color & AnimNode::getColor() const
	{
		return _color;
	}

	sf::FloatRect AnimNode::getLocalBounds() const
	{
		sf::Vector2f size(_vertices[_currFrame].v[2].position);

		return sf::FloatRect(0.f, 0.f, std::abs(size.x), std::abs(size.y));
	}

	sf::FloatRect AnimNode::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}

	void AnimNode::updateCurrent(const sf::Time & deltaTime, const Event & /* event */)
	{
		if (_paused)
			return ;
		_currTime += deltaTime;
		if (_currTime < _frameTime)
			return ;
		_currTime = sf::microseconds(_currTime.asMicroseconds() % _frameTime.asMicroseconds());
		if (_currFrame + 1 < _vertices.size())
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
		states.texture = _texture;
		target.draw(_vertices[_currFrame].v, 4, sf::Quads, states);
	}
}

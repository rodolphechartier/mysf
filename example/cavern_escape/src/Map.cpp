#include "Map.hpp"

Map::Map()
	: _speed(100.f)
	, _texture(0)
	, _drawOffset(0)
{
	srand(time(0));
}

Map::~Map()
{

}

void Map::gen(const sf::Vector2f & size, unsigned int minSize)
{
	_size = size;
	_minSize = minSize;
	for (unsigned int i = 0; i < _size.x * 2; ++i)
		genLine();
}

void Map::setSpeed(float speed)
{
	_speed = speed;
}

void Map::resetSpeed()
{
  _speed = 100.f;
}

void Map::addSpeed(float speed)
{
	_speed += speed;
}

float Map::getSpeed() const
{
	return _speed;
}

void Map::setTexture(sf::Texture & texture)
{
	_texture = &texture;
	_texture->setRepeated(true);
}

const sf::Texture * Map::getTexture() const
{
	return _texture;
}

void Map::updateCurrent(const sf::Time & deltaTime, const mysf::Event & /* event */)
{
    if (_speed == 0.f) return;
	static sf::Time time = sf::Time::Zero;
    const sf::Time deltaSpeed(sf::seconds(1.f / _speed));

	time += deltaTime;
	while (time > deltaSpeed)
	{
		_data.pop_front();
		genLine();
		time -= deltaSpeed;
		++_drawOffset;
	}
	if (_texture)
		_drawOffset %= _texture->getSize().x;
}

void Map::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (!_texture)
		return ;
	sf::Sprite sprite(*_texture);
	unsigned int x = 0;

	for (auto it = _data.begin(); it != _data.end() && x < _size.x; ++it)
	{
		const std::vector<unsigned int> & line(*it);
		sf::IntRect rect;

		rect.left = x + _drawOffset;
		rect.width = 1;
		for (unsigned int i = 0; i <= line.size(); i += 2)
		{
			rect.top = i ? line[i - 1] : 0;
			rect.height = (i == line.size() ? _size.y : line[i]) - rect.top;
			sprite.setTextureRect(rect);
			sprite.setPosition(x, rect.top);
			target.draw(sprite, states);
		}
		++x;
	}
}

void Map::genLine()
{
	static unsigned int nbGen = 0;
	static std::vector<int> slope(2, 0);
	std::vector<unsigned int> line(2, 0);

	if (nbGen > 64)
	{
		for (unsigned int i = 0; i < slope.size(); ++i)
			slope[i] = (rand() % 5) - 2;
		nbGen = 0;
	}

	if (_data.empty())
	{
		unsigned int i = 3;

		while (checkGenLine(line) == false)
		{
			line[0] = _size.y / i;
			line[1] = (i - 1) * line[0];
			++i;
		}
	}
	else
	{
		const std::vector<unsigned int> & last(_data.back());

		while (checkGenLine(line) == false)
		{
			for (unsigned int i = 0; i < line.size(); ++i)
				line[i] = last[i] + (slope[i] * (rand() % 2)) + (rand() % 3 - 1);
				// line[i] = last[i] + (slope[i] * (rand() % 3));
				// line[i] = last[i] + (slope[i] * (rand() % 4));
				// line[i] = last[i] + (slope[i] + ((rand() % 5) - 2));
				// line[i] = last[i] + (slope[i] + ((rand() % 9) - 4));
		}
	}
	++nbGen;
	_data.push_back(line);
}

bool Map::checkGenLine(const std::vector<unsigned int> & line) const
{
	if (!line.size() || line.size() % 2)
		return false;
	for (unsigned int i = 0; i < line.size(); ++i)
	{
		if (i < line.size() - 1 && line[i] >= line[i + 1])
			return false;
		if (line[i] >= _size.y)
			return false;
		if (!(i % 2) && line[i + 1] - line[i] < _minSize)
			return false;
	}
	return true;
}

#ifndef MAP_HPP_
# define MAP_HPP_

# include <iostream>

# include <cstdlib>
# include <ctime>
# include <vector>
# include <list>

# include "SceneNode.hpp"

class Map : public mysf::SceneNode
{
public:
	Map();
	Map(const Map & o) = default;
	Map & operator=(const Map & o) = default;
	virtual ~Map();

	void gen(const sf::Vector2u & size, unsigned int minSize);

	void setSpeed(const sf::Time & speed);
	const sf::Time & getSpeed() const;

    void setTexture(sf::Texture & texture);
    const sf::Texture * getTexture() const;

	// template <typename T>
	// bool intersects(const sf::Rect<T> & rect) const
	// {

	// }

	virtual void updateCurrent(const sf::Time & deltaTime, const mysf::Event & event) override;
	virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	void genLine();
	bool checkGenLine(const std::vector<unsigned int> & line) const;

private:
	std::list<std::vector<unsigned int>> _data;
	sf::Vector2u _size;
	unsigned int _minSize;
	sf::Time _speed;
	sf::Texture * _texture;

	unsigned int _drawOffset;
};

#endif // !MAP_HPP_

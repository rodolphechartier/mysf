#ifndef LIFE_HPP_
# define LIFE_HPP_

# include "RectangleShapeNode.hpp"

class Life : public mysf::RectangleShapeNode
{
public:
	explicit Life(unsigned int max = 1000);
	Life(const Life & o) = default;
	Life & operator=(const Life & o) = default;
	virtual ~Life();

	void add(unsigned int heal = 1);
	void sub(unsigned int damage = 1);
	unsigned int getValue() const;
	unsigned int getMax() const;
	float getRatio() const;

	operator bool() const;

	void setSizeMax(const sf::Vector2f & size);
	const sf::Vector2f & getSizeMax() const;

private:
	void update();

	sf::Vector2f _sizeMax;

	unsigned int _val;
	unsigned int _max;
};

#endif // !LIFE_HPP_

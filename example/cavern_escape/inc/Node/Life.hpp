#ifndef LIFE_HPP_
# define LIFE_HPP_

# include "SceneNode.hpp"

class Life : public mysf::SceneNode
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

	void setSize(const sf::Vector2f & size);
	const sf::Vector2f & getSize() const;

private:
	virtual void updateCurrent(const sf::Time & deltaTime, const mysf::Event & event) override;
    virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const override;

	sf::RectangleShape _shape;
	sf::Vector2f _size;

	unsigned int _val;
	unsigned int _max;
};

#endif // !LIFE_HPP_

#ifndef SCORE_HPP_
# define SCORE_HPP_

# include <string>

# include <SFML/Graphics.hpp>

# include "SceneNode.hpp"

class Score : public mysf::SceneNode
{
public:
	Score();
	Score(const Score & o) = default;
	Score & operator=(const Score & o) = default;
	virtual ~Score();

	void sub(long int val);
	void add(long int val);
	long int getValue() const;

	operator long int() const;

	void setCharacterSize(unsigned int size);
	void setFont(const sf::Font & font);
	unsigned int getCharacterSize() const;
	const sf::Font * getFont() const;

private:
	void updateText();

    virtual void updateCurrent(const sf::Time & deltaTime, const mysf::Event & event) override;
    virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const override;

	sf::Text _text;
	long int _val;
};

#endif // !SCORE_HPP_

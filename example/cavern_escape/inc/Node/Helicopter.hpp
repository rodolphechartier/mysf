#ifndef HELICOPTER_HPP_
# define HELICOPTER_HPP_

# include <vector>
# include <memory>

# include "GraphicLayerSet.hpp"
# include "SceneNode.hpp"
# include "AnimNode.hpp"
# include "ResourceHolder.hpp"
# include "Binding.hpp"

# include "Map.hpp"
# include "Action.hpp"
# include "HelicopterIdle.hpp"
# include "HelicopterHit.hpp"
# include "HelicopterDestroy.hpp"
# include "Life.hpp"
# include "Score.hpp"

class Helicopter : public mysf::SceneNode
{
public:
	enum State
	{
		First,
		Idle = First,
		Hit,
		Destroy,
		Size
	};

public:
	explicit Helicopter(const mysf::Binding & bind, const sf::RenderWindow & window, const Map & map, Score & score);
	Helicopter(const Helicopter & o) = delete;
	Helicopter & operator=(const Helicopter & o) = delete;
	virtual ~Helicopter() = default;

	bool init(const mysf::TextureHolder & thl);

    float getSpeed() const;
    void setSpeed(float speed);
    void addSpeed(float speed);

	void hit(unsigned int damage);
	State getState() const;
    bool isPlaying() const;

	void setHitbox(const sf::FloatRect & hitbox);
	sf::FloatRect getLocalHitbox() const;
	sf::FloatRect getGlobalHitbox() const;
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

private:
	virtual void updateCurrent(const sf::Time & deltaTime, const mysf::Event & event) override;
	virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const override;

	void colision(const sf::Time & deltaTime);

	const mysf::Binding & _bind;
	const sf::RenderWindow & _window;
	const Map & _map;
	Score & _score;

	std::vector<std::unique_ptr<mysf::AnimNode>> _anims;
	sf::FloatRect _hitbox;
	State _state;
	float _speed;
	Life _life;
};

#endif // !HELICOPTER_HPP_

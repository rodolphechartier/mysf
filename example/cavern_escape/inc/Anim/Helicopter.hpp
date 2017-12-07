#ifndef HELICOPTER_HPP_
# define HELICOPTER_HPP_

# include <vector>
# include <memory>

# include "SceneNode.hpp"
# include "AnimNode.hpp"
# include "ResourceHolder.hpp"
# include "Binding.hpp"

# include "Map.hpp"
# include "Action.hpp"
# include "HelicopterIdle.hpp"
# include "HelicopterHit.hpp"
# include "HelicopterDestroy.hpp"

class Helicopter : public mysf::SceneNode
{
	enum State
	{
		First,
		Idle = First,
		Hit,
		Destroy,
		Size
	};

public:
	explicit Helicopter(const mysf::Binding & bind, const Map & map);
	Helicopter(const Helicopter & o) = delete;
	Helicopter & operator=(const Helicopter & o) = delete;
	virtual ~Helicopter() = default;

	bool init(const mysf::TextureHolder & thl);
	void hit(unsigned int damage);

    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

private:
	virtual void updateCurrent(const sf::Time & deltaTime, const mysf::Event & event) override;
	virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const override;

	const mysf::Binding & _bind;
	const Map & _map;
	std::vector<std::unique_ptr<mysf::AnimNode>> _anims;
	State _state;
	float _speed;
	unsigned int _life;
};

#endif // !HELICOPTER_HPP_

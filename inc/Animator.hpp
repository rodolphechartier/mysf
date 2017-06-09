#ifndef MYSF_ANIMATOR_HPP_
# define MYSF_ANIMATOR_HPP_

# include <vector>

# include <SFML/Graphics.hpp>

# include "Animation.hpp"

namespace mysf
{
	class Animator : public sf::Drawable
	{
	public:
		explicit Animator(unsigned int nb = 1);
		Animator(const Animator & o) = default;
		Animator & operator=(const Animator & o) = default;
		virtual ~Animator() = default;

		Animation & operator[](unsigned int state);
		const Animation & operator[](unsigned int state) const;
		Animation & current();
		const Animation & current() const;

		bool setState(unsigned int state);
		unsigned int getState() const;
		bool setDefaultState(unsigned int state);
		unsigned int getDefaultState() const;

		void resize(unsigned int size);
		void add(Animation & animation);
		void clear();
		unsigned int size() const;

		virtual void update(const sf::Time & deltaTime);
		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const final;

	private:
		std::vector<Animation>	_animations;
		unsigned int						_state;
		unsigned int 						_default;
	};
}

#endif // !MYSF_ANIMATOR_HPP_

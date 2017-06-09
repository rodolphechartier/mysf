#ifndef MYSF_ANIMATION_HPP_
# define MYSF_ANIMATION_HPP_

# include <vector>

# include <SFML/Graphics.hpp>

namespace mysf
{
	class Animation : public sf::Transformable, public sf::Drawable
	{
	public:
		explicit Animation(unsigned int nb = 1);
		explicit Animation(const sf::Texture & texture, unsigned int nb = 1);
		explicit Animation(const sf::Texture & texture, const sf::IntRect & rectangle, unsigned int nb = 1);
		Animation(const Animation & o) = default;
		Animation & operator=(const Animation & o) = default;
		virtual ~Animation() = default;

		void setTexture(const sf::Texture & texture, bool resetRect = false);
		void setTextureRect(const sf::IntRect & rectangle);
		void setNumber(unsigned int nb);
		void setColor(const sf::Color & color);
		void setSpeed(const sf::Time & speed);
		void setLooped(bool isLooped = true);

		const sf::Texture * getTexture() const;
		const sf::IntRect & getTextureRect() const;
		unsigned int getNumber() const;
		const sf::Color & getColor() const;
		const sf::Time & getSpeed() const;
		bool isPlaying() const;
		bool isLooped() const;

		sf::FloatRect getLocalBounds() const;
		sf::FloatRect getGlobalBounds() const;

		void play();
		void pause();
		void stop();
		void update(const sf::Time & deltaTime);
		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const final;

	private:
		void build();

		const sf::Texture *			_texture;
		sf::IntRect							_textureRect;
		sf::Color								_color;
		sf::Time								_speed;
		bool										_isPlaying;
		bool 										_isLooped;

		std::vector<sf::Sprite>	_sprites;
		sf::Time								_timer;
		unsigned int						_index;
	};
}

#endif // !MYSF_ANIMATION_HPP_

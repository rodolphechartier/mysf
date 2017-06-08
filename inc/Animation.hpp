#ifndef MYSF_ANIMSPRITE_HPP_
# define MYSF_ANIMSPRITE_HPP_

# include <vector>

# include <SFML/Graphics.hpp>

namespace mysf
{
	class AnimSprite : public sf::Transformable, public sf::Drawable
	{
	public:
		explicit AnimSprite(unsigned int nb = 1);
		explicit AnimSprite(const sf::Texture & texture, unsigned int nb = 1);
		explicit AnimSprite(const sf::Texture & texture, const sf::IntRect & rectangle, unsigned int nb = 1);
		AnimSprite(const AnimSprite & o) = default;
		AnimSprite & operator=(const AnimSprite & o) = default;
		virtual ~AnimSprite() = default;

		void setTexture(const sf::Texture & texture, bool resetRect = false);
		void setTextureRect(const sf::IntRect & rectangle);
		void setNumber(unsigned int nb);
		void setColor(const sf::Color & color);
		void setSpeed(const sf::Time & speed);

		const sf::Texture * getTexture() const;
		const sf::IntRect & getTextureRect() const;
		unsigned int getNumber() const;
		const sf::Color & getColor() const;
		const sf::Time & getSpeed() const;

		sf::FloatRect getLocalBounds() const;
		sf::FloatRect getGlobalBounds() const;


	private:
		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

		void update();

		static const sf::Clock	_clock;
		const sf::Texture *			_texture;
		sf::IntRect							_textureRect;
		sf::Color								_color;
		sf::Time								_speed;

		std::vector<sf::Sprite>	_sprites;
		mutable unsigned int		_index;
	};
}

#endif // !MYSF_ANIMSPRITE_HPP_

#ifndef MYSF_ANIMSPRITE_HPP_
# define MYSF_ANIMSPRITE_HPP_

# include <vector>

# include <SFML/Graphics.hpp>

namespace mysf
{
	class AnimSprite : public sf::Transformable, public sf::Drawable
	{
	public:
		AnimSprite();
		explicit AnimSprite(const sf::Texture & texture);
		AnimSprite(const sf::Texture & texture, const sf::IntRect & rectangle);
		AnimSprite(const AnimSprite & o) = default;
		AnimSprite & operator=(const AnimSprite & o) = default;
		virtual ~AnimSprite() = default;

		void setTexture(const sf::Texture & texture, bool resetRect = false);
		void setTextureRect(const sf::IntRect & rectangle);
		void setColor(const sf::Color & color);

		void setSize(unsigned int x, unsigned int y);
		void setSize(const sf::Vector2u & size);
		void setMargin(unsigned int x, unsigned int y);
		void setMargin(const sf::Vector2u & margin);
		void setSpeed(const sf::Time & speed);

		const sf::Texture * getTexture() const;
		const sf::IntRect & getTextureRect() const;
		const sf::Color & getColor() const;
		sf::FloatRect getLocalBounds() const;
		sf::FloatRect getGlobalBounds() const;

		const sf::Vector2u & getSize() const;
		const sf::Vector2u & getMargin() const;
		const sf::Time & getSpeed() const;

	private:
		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

		void update();

		const sf::Texture *			_texture;
		sf::IntRect							_textureRect;
		sf::Color								_color;
		sf::Vector2u						_size;
		sf::Vector2u						_margin;
		sf::Time								_speed;

		std::vector<sf::Sprite>	_sprites;
		mutable unsigned int		_index;
	};
}

#endif // !MYSF_ANIMSPRITE_HPP_

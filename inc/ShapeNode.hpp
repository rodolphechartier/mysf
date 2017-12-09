#ifndef MYSF_SHAPENODE_HPP_
# define MYSF_SHAPENODE_HPP_

# include <SFML/Graphics.hpp>

# include "SceneNode.hpp"

namespace mysf
{
	class ShapeNode : public SceneNode
	{
	public:
		ShapeNode(const ShapeNode & o) = default;
		ShapeNode & operator=(const ShapeNode & o) = default;
		virtual ~ShapeNode();

		void setTexture(const sf::Texture * texture, bool resetRect = false);
		void setTextureRect(const sf::IntRect & rect);
		void setFillColor(const sf::Color & color);
		void setOutlineColor(const sf::Color & color);
		void setOutlineThickness(float thickness);

		const sf::Texture * getTexture() const;
		const sf::IntRect & getTextureRect() const;
		const sf::Color & getFillColor() const;
		const sf::Color & getOutlineColor() const;
		float getOutlineThickness() const;

		virtual std::size_t getPointCount() const = 0;
		virtual sf::Vector2f getPoint(std::size_t index) const = 0;

		sf::FloatRect getLocalBounds() const;
		sf::FloatRect getGlobalBounds() const;

	protected:
		explicit ShapeNode(sf::Shape & shape);
		void update();

		virtual void updateCurrent(const sf::Time & deltaTime, const Event & event);
		virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;

	private:
		sf::Shape & _shape;
	};
}

#endif // !MYSF_SHAPENODE_HPP_

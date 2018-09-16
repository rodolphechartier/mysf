#ifndef MYSF_RECTANGLESHAPENODE_HPP_
# define MYSF_RECTANGLESHAPENODE_HPP_

# include <SFML/Graphics.hpp>

# include "ShapeNode.hpp"

namespace mysf
{
	class RectangleShapeNode : public ShapeNode
	{
	public:
		explicit RectangleShapeNode(const sf::Vector2f & size = sf::Vector2f(0, 0));
		RectangleShapeNode(const RectangleShapeNode & o) = default;
		RectangleShapeNode & operator=(const RectangleShapeNode & o) = default;
		virtual ~RectangleShapeNode();

		void setSize(const sf::Vector2f & size);
		const sf::Vector2f & getSize() const;
		virtual std::size_t getPointCount() const override;
		virtual sf::Vector2f getPoint(std::size_t index) const override;

	private:
		sf::RectangleShape _rectangle;
	};
}

#endif // !MYSF_RECTANGLESHAPENODE_HPP_

#ifndef MYSF_CIRCLESHAPENODE_HPP_
# define MYSF_CIRCLESHAPENODE_HPP_

# include <SFML/Graphics.hpp>

# include "ShapeNode.hpp"

namespace mysf
{
	class CircleShapeNode : public ShapeNode
	{
	public:
		CircleShapeNode(float radius = 0, std::size_t pointCount = 30);
		CircleShapeNode(const CircleShapeNode & o) = default;
		CircleShapeNode & operator=(const CircleShapeNode & o) = default;
		virtual ~CircleShapeNode();

		void setRadius(float radius);
		float getRadius() const;
		void setPointCount(std::size_t count);
		virtual std::size_t getPointCount() const override;
		virtual sf::Vector2f getPoint(std::size_t index) const override;

	private:
		sf::CircleShape _circle;
	};
}

#endif // !MYSF_CIRCLESHAPENODE_HPP_

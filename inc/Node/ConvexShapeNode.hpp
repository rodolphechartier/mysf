#ifndef MYSF_CONVEXSHAPENODE_HPP_
# define MYSF_CONVEXSHAPENODE_HPP_

# include <SFML/Graphics.hpp>

# include "ShapeNode.hpp"

namespace mysf
{
	class ConvexShapeNode : public mysf::ShapeNode
	{
	public:
		explicit ConvexShapeNode(std::size_t pointCount = 0);
		ConvexShapeNode(const ConvexShapeNode & o) = default;
		ConvexShapeNode & operator=(const ConvexShapeNode & o) = default;
		virtual ~ConvexShapeNode();

		void setPointCount(std::size_t count);
		void setPoint(std::size_t index, const sf::Vector2f & point);
		virtual std::size_t getPointCount() const override;
		virtual sf::Vector2f getPoint(std::size_t index) const override;

	private:
		sf::ConvexShape _convex;
	};
}

#endif // !MYSF_CONVEXSHAPENODE_HPP_

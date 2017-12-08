#ifndef HELICOPTERDESTROY_HPP_
# define HELICOPTERDESTROY_HPP_

# include "AnimNode.hpp"

# include "ResourceHolder.hpp"
# include "Resource.hpp"

class HelicopterDestroy : public mysf::AnimNode
{
public:
	explicit HelicopterDestroy(const mysf::TextureHolder & thl);
	HelicopterDestroy(const HelicopterDestroy & o) = delete;
	HelicopterDestroy & operator=(const HelicopterDestroy & o) = delete;
	virtual ~HelicopterDestroy() = default;
};

#endif // !HELICOPTERDESTROY_HPP_

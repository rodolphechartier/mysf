#ifndef HELICOPTERHIT_HPP_
# define HELICOPTERHIT_HPP_

# include "AnimNode.hpp"

# include "ResourceHolder.hpp"
# include "Resource.hpp"

class HelicopterHit : public mysf::AnimNode
{
public:
	explicit HelicopterHit(const mysf::TextureHolder & thl);
	HelicopterHit(const HelicopterHit & o) = delete;
	HelicopterHit & operator=(const HelicopterHit & o) = delete;
	virtual ~HelicopterHit() = default;
};

#endif // !HELICOPTERHIT_HPP_

#ifndef HELICOPTERHIT_HPP_
# define HELICOPTERHIT_HPP_

# include "AnimNode.hpp"

class HelicopterHit : public mysf::AnimNode
{
public:
	HelicopterHit();
	HelicopterHit(const HelicopterHit & o) = delete;
	HelicopterHit & operator=(const HelicopterHit & o) = delete;
	virtual ~HelicopterHit() = default;
};

#endif // !HELICOPTERHIT_HPP_

#ifndef HELICOPTERIDLE_HPP_
# define HELICOPTERIDLE_HPP_

# include "AnimNode.hpp"

# include "ResourceHolder.hpp"
# include "Resource.hpp"

class HelicopterIdle : public mysf::AnimNode
{
public:
	explicit HelicopterIdle(const mysf::TextureHolder & thl);
	HelicopterIdle(const HelicopterIdle & o) = delete;
	HelicopterIdle & operator=(const HelicopterIdle & o) = delete;
	virtual ~HelicopterIdle() = default;
};

#endif // !HELICOPTERIDLE_HPP_

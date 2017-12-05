#ifndef HELICOPTERIDLE_HPP_
# define HELICOPTERIDLE_HPP_

# include "AnimNode.hpp"

class HelicopterIdle : public mysf::AnimNode
{
public:
	HelicopterIdle();
	HelicopterIdle(const HelicopterIdle & o) = delete;
	HelicopterIdle & operator=(const HelicopterIdle & o) = delete;
	virtual ~HelicopterIdle() = default;
};

#endif // !HELICOPTERIDLE_HPP_

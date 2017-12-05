#ifndef HELICOPTERDESTROY_HPP_
# define HELICOPTERDESTROY_HPP_

# include "AnimNode.hpp"

class HelicopterDestroy : public mysf::AnimNode
{
public:
	HelicopterDestroy();
	HelicopterDestroy(const HelicopterDestroy & o) = delete;
	HelicopterDestroy & operator=(const HelicopterDestroy & o) = delete;
	virtual ~HelicopterDestroy() = default;
};

#endif // !HELICOPTERDESTROY_HPP_

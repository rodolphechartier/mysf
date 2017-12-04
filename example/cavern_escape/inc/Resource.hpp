#ifndef RESOURCE_HPP_
# define RESOURCE_HPP_

namespace Resource
{
	namespace Texture
	{
		enum ID
		{
			None = -1,
			First = 0,
			Helicopter = First,
			Size
		};
	}

	namespace Sound
	{
		enum ID
		{
			None = -1,
			First = 0,
			Size
		};
	}

	namespace Font
	{
		enum ID
		{
			None = -1,
			First = 0,
			Size
		};
	}
}

#endif // !RESOURCE_HPP_

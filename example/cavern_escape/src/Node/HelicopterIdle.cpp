#include "HelicopterIdle.hpp"

HelicopterIdle::HelicopterIdle(const mysf::TextureHolder & thl)
	: AnimNode(thl[Resource::Texture::Helicopter], sf::seconds(0.135f))
{
	for (unsigned int i = 0; i < 7; ++i)
		addFrame(sf::IntRect(i * 180, 0, 180, 95));
}

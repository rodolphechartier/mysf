#include "HelicopterHit.hpp"

HelicopterHit::HelicopterHit(const mysf::TextureHolder & thl)
	: AnimNode(thl[Resource::Texture::Helicopter], sf::seconds(0.135f), true, false)
{
	for (unsigned int i = 0; i < 7; ++i)
		addFrame(sf::IntRect(i * 180, 95, 180, 95));
}

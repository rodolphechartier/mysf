#include "HelicopterDestroy.hpp"

HelicopterDestroy::HelicopterDestroy(const mysf::TextureHolder & thl)
	: AnimNode(thl[Resource::Texture::Helicopter], sf::seconds(0.2f), true, false)
{
	for (unsigned int i = 0; i < 7; ++i)
		addFrame(sf::IntRect(i * 180, 190, 180, 95));
}

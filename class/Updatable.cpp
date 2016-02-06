#include "Updatable.hpp"

Updatable::Updatable()
{

}

Updatable::Updatable(const sf::Texture & texture)
{
  setTexture(&texture);
}

Updatable::~Updatable()
{

}

void Updatable::update(float /* deltaTime */, const Input & /* input */)
{

}

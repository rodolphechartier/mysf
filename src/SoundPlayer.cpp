#include "SoundPlayer.hpp"

namespace mysf
{
	SoundPlayer::SoundPlayer()
	{

	}

	SoundPlayer::~SoundPlayer()
	{

	}

	void SoundPlayer::play(const sf::Sound & sound)
	{
		_sounds.push_back(sf::Sound(sound));
		_sounds.back().play();
	}

	void SoundPlayer::play(const sf::SoundBuffer & soundBuffer)
	{
		_sounds.push_back(sf::Sound(soundBuffer));
		_sounds.back().play();
	}

	void SoundPlayer::removeStoppedSounds()
	{
		_sounds.remove_if([] (const sf::Sound & s)
		{
			return s.getStatus() == sf::Sound::Stopped;
		});
	}
}

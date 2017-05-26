#include "SoundPlayer.hpp"

namespace mysf
{
	SoundPlayer::SoundPlayer()
	{

	}

	SoundPlayer::~SoundPlayer()
	{

	}

	void SoundPlayer::play(const sf::SoundBuffer & soundBuffer, const SoundProperties & properties)
	{
		_sounds.push_back(sf::Sound(soundBuffer));
		sf::Sound & sound = _sounds.back();

		sound.setVolume(properties.volume);
		sound.setPitch(properties.pitch);
		sound.setAttenuation(properties.attenuation);
		sound.setMinDistance(properties.minDistance);
		sound.setLoop(properties.loop);
		sound.setRelativeToListener(properties.relative);
		sound.setPosition(properties.position);
		sound.play();
	}

	void SoundPlayer::removeStoppedSounds()
	{
		_sounds.remove_if([] (const sf::Sound & s)
		{
			return s.getStatus() == sf::Sound::Stopped;
		});
	}
}

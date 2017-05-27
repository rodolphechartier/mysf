#include "SoundPlayer.hpp"

namespace mysf
{
	SoundPlayer::SoundPlayer()
	{

	}

	SoundPlayer::~SoundPlayer()
	{

	}

	void SoundPlayer::setNbLayer(unsigned int nbLayer)
	{
		_volumes.resize(nbLayer);
	}

	unsigned int SoundPlayer::getNbLayer() const
	{
		return _volumes.size();
	}

	void SoundPlayer::setLayerVolume(float volume, unsigned int layer)
	{
		_volumes[layer] = volume;
	}

	float SoundPlayer::getLayerVolume(unsigned int layer) const
	{
		return _volumes[layer];
	}

	void SoundPlayer::play(const sf::Sound & sound)
	{
		_sounds.push_back(sf::Sound(sound));
		_sounds.back().play();
	}

	void SoundPlayer::play(const sf::Sound & sound, unsigned int layer)
	{
		_sounds.push_back(sf::Sound(sound));
		sf::Sound & s = _sounds.back();

		s.setVolume(s.getVolume() * _volumes[layer] / 100.f);
		s.play();
	}

	void SoundPlayer::removeStoppedSounds()
	{
		_sounds.remove_if([] (const sf::Sound & s)
		{
			return s.getStatus() == sf::Sound::Stopped;
		});
	}
}

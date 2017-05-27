#ifndef SOUND_PLAYER_HPP_
# define SOUND_PLAYER_HPP_

# include <list>

# include <SFML/Audio.hpp>

namespace mysf
{
	class SoundPlayer : public sf::Listener
	{
	public:
		SoundPlayer();
		SoundPlayer(const SoundPlayer &) = delete;
		SoundPlayer & operator=(const SoundPlayer &) = delete;
		virtual ~SoundPlayer();

		void setNbLayer(unsigned int nbLayer);
		unsigned int getNbLayer() const;

		void setLayerVolume(float volume, unsigned int layer);
		float getLayerVolume(unsigned int layer) const;

		void play(const sf::Sound & sound);
		void play(const sf::Sound & sound, unsigned int layer);
		void removeStoppedSounds();

	private:
		std::list<sf::Sound> 	_sounds;
		std::vector<float> 		_volumes;
	};
}

#endif // !SOUND_PLAYER_HPP_

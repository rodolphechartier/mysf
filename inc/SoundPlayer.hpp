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

		void play(const sf::Sound & sound);
		void play(const sf::SoundBuffer & soundBuffer);
		void removeStoppedSounds();

	private:
		std::list<sf::Sound> _sounds;
	};
}

#endif // !SOUND_PLAYER_HPP_

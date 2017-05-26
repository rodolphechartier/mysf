#ifndef SOUND_PLAYER_HPP_
# define SOUND_PLAYER_HPP_

# include <list>

# include <SFML/Audio.hpp>

namespace mysf
{
	class SoundPlayer
	{
	public:
		struct SoundProperties
		{
			SoundProperties()
				: volume(100.f)
				, pitch(1.f)
				, attenuation(1.f)
				, minDistance(1.f)
				, loop(false)
				, relative(false)
				, position(0, 0, 0)
			{}

			float 				volume;
			float 				pitch;
			float 				attenuation;
			float 				minDistance;
			bool 					loop;
			bool 					relative;
			sf::Vector3f 	position;
		};

	public:
		SoundPlayer();
		SoundPlayer(const SoundPlayer &) = delete;
		SoundPlayer & operator=(const SoundPlayer &) = delete;
		virtual ~SoundPlayer();

		void play(const sf::SoundBuffer & soundBuffer, const SoundProperties & properties = SoundProperties());
		void removeStoppedSounds();

	private:
		std::list<sf::Sound> _sounds;
	};
}

#endif // !SOUND_PLAYER_HPP_

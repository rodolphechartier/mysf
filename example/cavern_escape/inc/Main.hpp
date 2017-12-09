#ifndef MAIN_HPP_
# define MAIN_HPP_

# include "Engine.hpp"

# include "Game.hpp"

class Main : public mysf::Engine<sf::RenderWindow>
{
public:
	virtual bool init(int /* ac */, char ** /* av */) override
	{
		_grender = new Game(*dynamic_cast<mysf::Engine<sf::RenderWindow> *>(this), _window);

		return _grender->init();
	}
};

#endif // !MAIN_HPP_

#ifndef MAIN_HPP_
# define MAIN_HPP_

# include "Engine.hpp"

# include "Game.hpp"

class Main : public mysf::Engine<sf::RenderWindow>
{
public:
	bool init(int /* ac */, char ** /* av */)
	{
        try {
            _grender = new Game(*dynamic_cast<mysf::Engine<sf::RenderWindow> *>(this), _window);
        }
        catch (const std::exception & e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
        return true;
	}
};

#endif // !MAIN_HPP_

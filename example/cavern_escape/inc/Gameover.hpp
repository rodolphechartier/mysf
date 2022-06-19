#ifndef GAMEOVER_HPP_
# define GAMEOVER_HPP_

# include <algorithm>

# include <SFML/Graphics.hpp>

# include "Engine.hpp"
# include "SceneNode.hpp"
# include "TextNode.hpp"
# include "GraphicLayer.hpp"

# include "Helicopter.hpp"

class Gameover : public mysf::SceneNode
{
public:
  explicit Gameover(mysf::Engine<sf::RenderWindow> & engine, sf::RenderWindow & window, Helicopter & helicopter, Map & map);
	Gameover(const Gameover & o) = default;
	Gameover & operator=(const Gameover & o) = default;
	virtual ~Gameover();

	bool init(mysf::GraphicLayer * layer, const sf::Font & font);
	mysf::GraphicRender * operator()(const mysf::Event & event, mysf::GraphicRender * parent);

private:
	virtual void updateCurrent(const sf::Time & deltaTime, const mysf::Event & event);
	virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;

private:
	mysf::Engine<sf::RenderWindow> & _engine;
	sf::RenderWindow & _window;
	Helicopter & _helicopter;
    Map & _map;

	sf::Text _text;
	sf::Text _continue;
	mysf::GraphicLayer * _layer;
	bool _added;
};

#endif // !GAMEOVER_HPP_

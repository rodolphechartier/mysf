#include "Engine.hpp"

Engine::Engine(int argc, char ** argv, const std::string & title)
  : _argc(argc)
  , _argv(argv)
  , _grender(0)
{
  _ctx.win.create(sf::VideoMode(760, 960), title, sf::Style::Default & ~sf::Style::Resize);
  _grender = new MainMenu(_ctx);
}

Engine::~Engine()
{
  if (_grender)
    delete _grender;
}

bool Engine::init()
{
  if (_ctx.thl.setDefault("assets/default.png") == false)
    return false;
  return _grender ? _grender->init() : false;
}

int Engine::run()
{
  int ret;
  sf::Clock clock;

  ret = 0;
  _draw(); // 1st render
  while (_ctx.win.isOpen())
    {
      _processEvents();
      if ((ret = _update(clock.restart())))
	{
	  _ctx.win.close();
	  return ret - 1;
	}
      _draw();
    }
  return ret;
}

void Engine::_processEvents()
{
  if (_ctx.win.pollEvent(_event))
    _input.update(_event);
}

// return
// 0 continue
// 1 close win
// 2 error
int Engine::_update(const sf::Time & deltaTime)
{
  GraphicRender * ret;

  if (!_grender)
    return 2;
  if ((ret = _grender->update(deltaTime.asSeconds(), _input)) != _grender)
    {
      delete _grender;
      if ((_grender = ret) == 0)
	return 1;
      if (_grender->init() == false)
	return 2;
      _input.reset();
    }
  return 0;
}

void Engine::_draw()
{
  _ctx.win.clear();
  if (_grender)
    _grender->draw();
  _ctx.win.display();
}

#include "Engine.hpp"

namespace mysf
{
  Engine::Engine()
    : _grender(0)
  {

  }

  Engine::~Engine()
  {
    if (_grender)
      delete _grender;
  }

  int Engine::run()
  {
		sf::Clock clock;
    int ret = 0;

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
		static sf::Event event;

    while (_ctx.win.pollEvent(event))
      _event.update(event);
  }

  // return (0: continue, 1: close win, 2: error)
  int Engine::_update(const sf::Time & deltaTime)
  {
    GraphicRender * ret;

    if (!_grender)
      return 2;
    if ((ret = _grender->update(deltaTime, _event)) != _grender)
      {
      	delete _grender;
      	if ((_grender = ret) == 0)
      	  return 1;
      	if (_grender->init() == false)
      	  return 2;
      	_event.reset();
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
}

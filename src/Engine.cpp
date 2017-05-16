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
    int ret = 0;

    _draw(); // 1st render
    while (_ctx.win.isOpen())
      {
	       _processEvents();
      	if ((ret = _update(_clock.restart())))
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
    while (_ctx.win.pollEvent(_event))
      _input.update(_event);
  }

  // return (0: continue, 1: close win, 2: error)
  int Engine::_update(const sf::Time & deltaTime)
  {
    GraphicRender * ret;

    if (!_grender)
      return 2;
    if ((ret = _grender->update(deltaTime, _input)) != _grender)
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
}

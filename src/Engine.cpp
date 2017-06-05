#include "Engine.hpp"

namespace mysf
{
  Engine::Engine()
    : _grender(0)
		, _speed(1.f)
  {

  }

  Engine::~Engine()
  {
		if (ctx.win)
			delete ctx.win;
    if (_grender)
      delete _grender;
  }

	bool Engine::init(int /* ac */, char ** /* av */)
	{
		ctx.win = new sf::RenderWindow(sf::VideoMode(800, 450), "Mysf");
		_grender = new GraphicRender;

		return _grender->init();
	}

  int Engine::run()
  {
		sf::Clock clock;
    int ret = 0;

		// Doesn't work if put in contructor
		ctx.win->setKeyRepeatEnabled(false);

		_draw(); // 1st render
    while (ctx.win->isOpen())
      {
	       _processEvents();
      	if ((ret = _update(clock.restart())))
      	  {
      	    ctx.win->close();
      	    return ret - 1;
      	  }
      	_draw();
      }
    return ret;
  }

	void Engine::pause(bool isPaused)
	{
		_speed = isPaused ? 0.f : 1.f;
	}

	void Engine::setSpeed(float speed)
	{
		_speed = speed;
	}

	void Engine::multiplySpeed(float speed)
	{
		_speed *= speed;
	}

	void Engine::divideSpeed(float speed)
	{
		_speed /= speed;
	}

	float Engine::getSpeed() const
	{
		return _speed;
	}

  void Engine::_processEvents()
  {
		static sf::Event event;

		_event.loop();
    while (ctx.win->pollEvent(event))
      _event.update(event);
  }

  // return (0: continue, 1: close win, 2: error)
  int Engine::_update(const sf::Time & deltaTime)
  {
    GraphicRender * ret;

    if (!_grender)
      return 2;
    if ((ret = _grender->update(deltaTime * _speed, _event)) != _grender)
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
    ctx.win->clear();
    if (_grender)
      _grender->draw();
    ctx.win->display();
  }
}

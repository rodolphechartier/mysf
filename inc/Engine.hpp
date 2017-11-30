#ifndef MYSF_ENGINE_HPP_
# define MYSF_ENGINE_HPP_

# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>

# include "GraphicRender.hpp"
# include "Event.hpp"

namespace mysf
{
  template <class Window = sf::RenderWindow>
  class Engine
  {
  public:
    Engine()
      : _grender(0)
      , _speed(1.f)
    {

    }

    Engine(const Engine &) = delete;
    Engine & operator=(const Engine &) = delete;

    virtual ~Engine()
    {
      if (_grender)
	delete _grender;
    }

    virtual bool init(int /* ac */, char ** /* av */)
    {
      _grender = new GraphicRender;

      return _grender->init();
    }

    int run()
    {
      sf::Clock clock;
      int ret = 0;

      // Doesn't work if put in contructor
      _window.setKeyRepeatEnabled(false);

      _draw(); // 1st render
      while (_window.isOpen())
	{
	  _processEvents();
	  if ((ret = _update(clock.restart())))
	    {
	      _window.close();
	      return ret - 1;
	    }
	  _draw();
	}
      return ret;
    }

    void pause(bool isPaused)
    {
      _speed = isPaused ? 0.f : 1.f;
    }

    void setSpeed(float speed)
    {
      _speed = speed;
    }

    void multiplySpeed(float speed)
    {
      _speed *= speed;
    }

    void divideSpeed(float speed)
    {
      _speed /= speed;
    }

    float getSpeed() const
    {
      return _speed;
    }

  private:
    void _processEvents()
    {
      static sf::Event event;

      _event.loop();
      while (_window.pollEvent(event))
	_event.update(event);
    }

    // return (0: continue, 1: close win, 2: error)
    int _update(const sf::Time & deltaTime)
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

    void _draw()
    {
      _window.clear();
      if (_grender)
	_grender->draw(_window);
      _window.display();
    }

  protected:
    Window _window;
    GraphicRender * _grender;
    Event _event;
    float _speed;
  };
}

#endif // !MYSF_ENGINE_HPP_

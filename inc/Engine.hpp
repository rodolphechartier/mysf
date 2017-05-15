#ifndef ENGINE_HPP_
# define ENGINE_HPP_

# include "GraphicRender.hpp"
# include "Input.hpp"

# include "Context.hpp"

namespace mysf
{
  class Engine
  {
  public:
    Engine();
    Engine(const Engine &) = delete;
    Engine & operator=(const Engine &) = delete;
    virtual ~Engine();

    bool	init(int ac, char ** av);
    int		run();

  protected:
    virtual bool onInit(int ac, char ** av) = 0;

  private:
    void	_processEvents();
    int		_update(const sf::Time & deltaTime);
    void	_draw();

  private:
    Context _ctx;
    GraphicRender *	_grender;

    sf::Clock _clock;
    sf::Event _event;
    Input _input;
  };
}

#endif // !ENGINE_HPP_

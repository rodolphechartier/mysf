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

    virtual bool init(int ac, char ** av) = 0;
    int run();

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

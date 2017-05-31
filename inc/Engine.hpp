#ifndef ENGINE_HPP_
# define ENGINE_HPP_

# include "GraphicRender.hpp"
# include "Event.hpp"

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

  protected:
    GraphicRender *	_grender;
    Event _event;
  };
}

#endif // !ENGINE_HPP_

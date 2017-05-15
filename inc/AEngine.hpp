#ifndef AENGINE_HPP_
# define AENGINE_HPP_

# include "GraphicRender.hpp"
# include "Input.hpp"

# include "Context.hpp"

namespace mysf
{
  class AEngine
  {
  public:
    AEngine();
    AEngine(const AEngine &) = delete;
    AEngine & operator=(const AEngine &) = delete;
    virtual ~AEngine();

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

#endif // !AENGINE_HPP_

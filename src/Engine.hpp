#ifndef ENGINE_HPP_
# define ENGINE_HPP_

# include <string>

# include "GraphicRender.hpp"
# include "MainMenu.hpp"
# include "Input.hpp"

# include "Context.hpp"

class Engine
{
public:
  explicit Engine(int argc, char ** argv, const std::string & title = "mysf::Engine");
  Engine(const Engine &);
  Engine & operator=(const Engine &);
  virtual ~Engine();

  bool	init();
  int	run();

private:
  void	_processEvents();
  int	_update(const sf::Time & deltaTime);
  void	_draw();

private:
  int			_argc;
  char **		_argv;

  Context		_ctx;
  GraphicRender *	_grender;

  sf::Event		_event;
  Input			_input;
};

#endif // !ENGINE_HPP_

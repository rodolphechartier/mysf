#ifndef MAINMENU_HPP_
# define MAINMENU_HPP_

# include <vector>

# include <SFML/Audio.hpp>

# include "GraphicRender.hpp"
# include "Game.hpp"
# include "PlayOptionMenu.hpp"
# include "CheckBox.hpp"
# include "Button.hpp"

# include "Context.hpp"

class MainMenu : public GraphicRender
{
public:
  typedef GraphicRender * (MainMenu::*menuAction)();

  enum
    {
      First = 0,
      Play = First,
      Exit,
      NbSelect
    };

public:
  explicit MainMenu(Context & ctx);
  MainMenu(const MainMenu &);
  MainMenu & operator=(const MainMenu &);
  virtual ~MainMenu();

  virtual bool			init();
  virtual GraphicRender *	update(float deltaTime, const Input & input);

private:
  bool				_load();
  void				_unload();

  GraphicRender *		_play();
  GraphicRender *		_exit();

  // GraphicRender *		_playPvP();
  // GraphicRender *		_playAISecond();
  // GraphicRender *		_playAIFirst();
  // GraphicRender *		_exit();

private:
  std::vector<Button *>		_buttons;
  std::vector<menuAction>	_menuAction;
  int				_select;
  bool				_check;

  Updatable			_background;
  sf::Sound			_menuClick;
};

#endif // !MAINMENU_HPP_

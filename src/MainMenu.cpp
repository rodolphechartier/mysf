#include "MainMenu.hpp"

MainMenu::MainMenu(Context & ctx)
  : GraphicRender(ctx)
  , _select(MainMenu::First)
  , _check(false)
{

}

MainMenu::~MainMenu()
{
  for (unsigned int i = 0; i < _buttons.size(); ++i)
    if (_buttons[i])
      delete _buttons[i];
}

bool MainMenu::init()
{
  _ctx.gls.resize(2);

  if (_load() == false)
    return false;

  _background.setTexture(&_ctx.thl[Resource::Texture::Paper]);
  _background.setSize(sf::Vector2f(_ctx.win.getSize()));
  _ctx.gls[0].add(&_background);

  _buttons.resize(MainMenu::NbSelect);
  _menuAction.resize(MainMenu::NbSelect);

  _buttons[MainMenu::Play] = new Button(_ctx, _select, _check, "Play", MainMenu::Play);
  _buttons[MainMenu::Exit] = new Button(_ctx, _select, _check, "Exit", MainMenu::Exit);

  _menuAction[MainMenu::Play] = &MainMenu::_play;
  _menuAction[MainMenu::Exit] = &MainMenu::_exit;

  for (unsigned int i = 0; i < _buttons.size(); ++i)
    {
      _buttons[i]->setTexture(&_ctx.thl[Resource::Texture::Button]);
      _buttons[i]->setColor(sf::Color(32, 56, 120));
      _buttons[i]->setColorSelected(sf::Color(16, 28, 60));
      _buttons[i]->setTextColor(sf::Color(114, 114, 114));
      _buttons[i]->setTextColorSelected(sf::Color(220, 220, 220));
      _buttons[i]->setSize(sf::Vector2f(_ctx.win.getSize().x / 2,
					_ctx.win.getSize().y / (2 * _buttons.size() + 1)));
      _buttons[i]->setPosition(sf::Vector2f((_ctx.win.getSize().x / 2) - (_buttons[i]->getSize().x / 2),
				       ((i + 1) * _ctx.win.getSize().y / (_buttons.size() + 1)) - (_buttons[i]->getSize().y / 2)));
      _buttons[i]->updateSize();
      _ctx.gls[1].add(_buttons[i]);
    }

  _menuClick.setBuffer(_ctx.shl[Resource::Sound::MenuClick]);
  return true;
}

GraphicRender * MainMenu::update(float deltaTime, const Input & input)
{
  GraphicRender * ret = this;

  if (input.isClosed())
    return 0;

  _ctx.gls.update(deltaTime, input);
  if (input.getKey().isDown(sf::Keyboard::Up))
    _select = (_select + 1) % _buttons.size();
  if (input.getKey().isDown(sf::Keyboard::Down))
    _select = (_select ? _select : _buttons.size()) - 1;
  if (input.getKey().isDown(sf::Keyboard::Return))
    _check = true;
  if (_check)
    {
      _menuClick.play();
      if ((ret = (this->*_menuAction[_select])()) != this)
	_unload();
    }
  return ret;
}

bool MainMenu::_load()
{
  _ctx.thl.load(Resource::Texture::Paper, "assets/paper.png");
  _ctx.thl.load(Resource::Texture::CheckBox, "assets/check.png");
  _ctx.thl.load(Resource::Texture::Button, "assets/button.png");
  _ctx.shl.load(Resource::Sound::MenuClick, "assets/menuClick.wav");
  _ctx.fhl.load(Resource::Font::Gomoku, "assets/Bonzai.ttf");
  return true;
}

void MainMenu::_unload()
{
  _ctx.thl.unload(Resource::Texture::Paper);
  _ctx.thl.unload(Resource::Texture::CheckBox);
  _ctx.thl.unload(Resource::Texture::Button);
  _ctx.shl.unload(Resource::Sound::MenuClick);
  _ctx.fhl.unload(Resource::Font::Gomoku);
}

GraphicRender * MainMenu::_play()
{
  return new PlayOptionMenu(_ctx);
}

GraphicRender * MainMenu::_exit()
{
  return 0;
}

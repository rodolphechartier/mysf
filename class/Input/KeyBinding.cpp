#include "KeyBinding.hpp"

KeyBinding::KeyBinding()
{

}

KeyBinding::KeyBinding(const KeyBinding & o)
  : _bind(o._bind)
{

}

KeyBinding & KeyBinding::operator=(const KeyBinding & o)
{
  if (&o == this)
    return *this;
  _bind = o._bind;
  return *this;
}

KeyBinding::~KeyBinding()
{

}

bool KeyBinding::load(const std::string & filename, std::map<std::string, unsigned int> & bind)
{
  std::map<std::string, sf::Keyboard::Key> sfbind;
  std::ifstream file;
  std::string line;

  file.open(filename.c_str());
  if (file.is_open() == false)
    return false;
  _initSfbind(sfbind);
  while (std::getline(file, line))
    {
      line = line.substr(0, line.find_first_of("#"));
      _eraseSpace(line);
      if (line.size())
	{
	  unsigned int action;
	  std::vector<sf::Keyboard::Key> key;

	  action = bind[line.substr(0, line.find_first_of("="))];
	  line = line.substr(line.find_first_of("=") + 1);
	  while (line.size())
	    {
	      std::size_t pos;

	      key.push_back(sfbind[line.substr(0, line.find('|'))]);
	      pos = line.find('|');
	      if (pos != std::string::npos)
		line = line.substr(line.find('|') + (pos != line.size() - 1));
	      else
		line.resize(0);
	    }
	  if (_bind.size() <= action)
	    _bind.resize(action + 1);
	  _bind[action] = key;
	}
    }
  file.close();
  return true;
}

std::vector<sf::Keyboard::Key> & KeyBinding::operator[](unsigned int action)
{
  return _bind[action];
}

const std::vector<sf::Keyboard::Key> & KeyBinding::operator[](unsigned int action) const
{
  return _bind[action];
}

void KeyBinding::_eraseSpace(std::string & str)
{
  std::size_t pos, size;

  while ((pos = str.find_first_of(" \n\t")) != std::string::npos)
    {
      size = str.find_first_not_of(" \n\t", pos);
      if (size != std::string::npos)
	size -= pos;
      str.erase(pos, size);
    }
}

void KeyBinding::_initSfbind(std::map<std::string, sf::Keyboard::Key> & sfbind) const
{
  sfbind["Unknown"] = sf::Keyboard::Unknown;
  sfbind["A"] = sf::Keyboard::A;
  sfbind["B"] = sf::Keyboard::B;
  sfbind["C"] = sf::Keyboard::C;
  sfbind["D"] = sf::Keyboard::D;
  sfbind["E"] = sf::Keyboard::E;
  sfbind["F"] = sf::Keyboard::F;
  sfbind["G"] = sf::Keyboard::G;
  sfbind["H"] = sf::Keyboard::H;
  sfbind["I"] = sf::Keyboard::I;
  sfbind["J"] = sf::Keyboard::J;
  sfbind["K"] = sf::Keyboard::K;
  sfbind["L"] = sf::Keyboard::L;
  sfbind["M"] = sf::Keyboard::M;
  sfbind["N"] = sf::Keyboard::N;
  sfbind["O"] = sf::Keyboard::O;
  sfbind["P"] = sf::Keyboard::P;
  sfbind["Q"] = sf::Keyboard::Q;
  sfbind["R"] = sf::Keyboard::R;
  sfbind["S"] = sf::Keyboard::S;
  sfbind["T"] = sf::Keyboard::T;
  sfbind["U"] = sf::Keyboard::U;
  sfbind["V"] = sf::Keyboard::V;
  sfbind["W"] = sf::Keyboard::W;
  sfbind["X"] = sf::Keyboard::X;
  sfbind["Y"] = sf::Keyboard::Y;
  sfbind["Z"] = sf::Keyboard::Z;
  sfbind["Num0"] = sf::Keyboard::Num0;
  sfbind["Num1"] = sf::Keyboard::Num1;
  sfbind["Num2"] = sf::Keyboard::Num2;
  sfbind["Num3"] = sf::Keyboard::Num3;
  sfbind["Num4"] = sf::Keyboard::Num4;
  sfbind["Num5"] = sf::Keyboard::Num5;
  sfbind["Num6"] = sf::Keyboard::Num6;
  sfbind["Num7"] = sf::Keyboard::Num7;
  sfbind["Num8"] = sf::Keyboard::Num8;
  sfbind["Num9"] = sf::Keyboard::Num9;
  sfbind["Escape"] = sf::Keyboard::Escape;
  sfbind["LControl"] = sf::Keyboard::LControl;
  sfbind["LShift"] = sf::Keyboard::LShift;
  sfbind["LAlt"] = sf::Keyboard::LAlt;
  sfbind["LSystem"] = sf::Keyboard::LSystem;
  sfbind["RControl"] = sf::Keyboard::RControl;
  sfbind["RShift"] = sf::Keyboard::RShift;
  sfbind["RAlt"] = sf::Keyboard::RAlt;
  sfbind["RSystem"] = sf::Keyboard::RSystem;
  sfbind["Menu"] = sf::Keyboard::Menu;
  sfbind["LBracket"] = sf::Keyboard::LBracket;
  sfbind["RBracket"] = sf::Keyboard::RBracket;
  sfbind["SemiColon"] = sf::Keyboard::SemiColon;
  sfbind["Comma"] = sf::Keyboard::Comma;
  sfbind["Period"] = sf::Keyboard::Period;
  sfbind["Quote"] = sf::Keyboard::Quote;
  sfbind["Slash"] = sf::Keyboard::Slash;
  sfbind["BackSlash"] = sf::Keyboard::BackSlash;
  sfbind["Tilde"] = sf::Keyboard::Tilde;
  sfbind["Equal"] = sf::Keyboard::Equal;
  sfbind["Dash"] = sf::Keyboard::Dash;
  sfbind["Space"] = sf::Keyboard::Space;
  sfbind["Return"] = sf::Keyboard::Return;
  sfbind["BackSpace"] = sf::Keyboard::BackSpace;
  sfbind["Tab"] = sf::Keyboard::Tab;
  sfbind["PageUp"] = sf::Keyboard::PageUp;
  sfbind["PageDown"] = sf::Keyboard::PageDown;
  sfbind["End"] = sf::Keyboard::End;
  sfbind["Home"] = sf::Keyboard::Home;
  sfbind["Insert"] = sf::Keyboard::Insert;
  sfbind["Delete"] = sf::Keyboard::Delete;
  sfbind["Add"] = sf::Keyboard::Add;
  sfbind["Subtract"] = sf::Keyboard::Subtract;
  sfbind["Multiply"] = sf::Keyboard::Multiply;
  sfbind["Divide"] = sf::Keyboard::Divide;
  sfbind["Left"] = sf::Keyboard::Left;
  sfbind["Right"] = sf::Keyboard::Right;
  sfbind["Up"] = sf::Keyboard::Up;
  sfbind["Down"] = sf::Keyboard::Down;
  sfbind["Numpad0"] = sf::Keyboard::Numpad0;
  sfbind["Numpad1"] = sf::Keyboard::Numpad1;
  sfbind["Numpad2"] = sf::Keyboard::Numpad2;
  sfbind["Numpad3"] = sf::Keyboard::Numpad3;
  sfbind["Numpad4"] = sf::Keyboard::Numpad4;
  sfbind["Numpad5"] = sf::Keyboard::Numpad5;
  sfbind["Numpad6"] = sf::Keyboard::Numpad6;
  sfbind["Numpad7"] = sf::Keyboard::Numpad7;
  sfbind["Numpad8"] = sf::Keyboard::Numpad8;
  sfbind["Numpad9"] = sf::Keyboard::Numpad9;
  sfbind["F1"] = sf::Keyboard::F1;
  sfbind["F2"] = sf::Keyboard::F2;
  sfbind["F3"] = sf::Keyboard::F3;
  sfbind["F4"] = sf::Keyboard::F4;
  sfbind["F5"] = sf::Keyboard::F5;
  sfbind["F6"] = sf::Keyboard::F6;
  sfbind["F7"] = sf::Keyboard::F7;
  sfbind["F8"] = sf::Keyboard::F8;
  sfbind["F9"] = sf::Keyboard::F9;
  sfbind["F10"] = sf::Keyboard::F10;
  sfbind["F11"] = sf::Keyboard::F11;
  sfbind["F12"] = sf::Keyboard::F12;
  sfbind["F13"] = sf::Keyboard::F13;
  sfbind["F14"] = sf::Keyboard::F14;
  sfbind["F15"] = sf::Keyboard::F15;
  sfbind["Pause"] = sf::Keyboard::Pause;
}

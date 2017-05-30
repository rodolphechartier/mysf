#ifndef BINDING_HPP_
# define BINDING_HPP_

# include <fstream>
# include <vector>
# include <string>
# include <map>

# include <SFML/Window.hpp>

# include "Event.hpp"

namespace mysf
{
	struct Input
	{
		enum Type
		{
			KeyboardKey,
			MouseButton,
			MouseWheel,
			JoystickButton,
			JoystickAxis
		};

		Type type;
		union
		{
			unsigned int 					value;

			sf::Keyboard::Key 		keycode;
			sf::Mouse::Button 		mButton;
			mysf::Mouse::WheelDir wheelDir;
			unsigned int 					jButton;
			sf::Joystick::Axis 		axis;
		};
	};

  class Binding
  {
  public:
    explicit Binding(unsigned int nbAction = 0, unsigned int joystickId = 0);
    Binding(const Binding & o);
    Binding & operator=(const Binding & o);
    virtual ~Binding();

		const std::vector<Input> * getInput(unsigned int action, const Event & event) const;

		bool load(const std::string & filename, const std::map<std::string, unsigned int> & bind);
		void setNbAction(unsigned int size);
		void setBind(unsigned int action, const Input & bind);
		void setBind(unsigned int action, const std::vector<Input> & bind);
		void setBind(unsigned int action, const std::vector<std::vector<Input>> & bind);

		void setJoystickId(unsigned int joystickId);
		unsigned int getJoystickId() const;

	private:
		void _initSfbind(std::map<std::string, Input> & sfbind) const;

	protected:
		std::vector<std::vector<std::vector<Input>>> _bind;
		unsigned int _joystickId;
  };
}

#endif // !BINDING_HPP_

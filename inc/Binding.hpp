#ifndef BINDING_HPP_
# define BINDING_HPP_

# include <fstream>
# include <vector>
# include <string>
# include <map>

# include <SFML/Window.hpp>

# include "Input.hpp"

namespace mysf
{
  class Binding
  {
	public:
		enum InputType
		{
			KeyboardInput,
			MouseInput,
			JoystickInput
		};

		struct InputCode
		{
			InputCode(InputType inputType_, unsigned int code_)
				: inputType(inputType_), code(code_) {}

			InputType inputType;
			union
			{
				unsigned int code;
				sf::Keyboard::Key kcode;
				sf::Mouse::Button mcode;
				unsigned int jcode;
			};
		};

  public:
    explicit Binding(unsigned int joystickId = 0);
    Binding(const Binding & o);
    Binding & operator=(const Binding & o);
    virtual ~Binding();

		bool isDown(unsigned int action, const Input & input) const;

		void setBind(unsigned int action, const InputCode & bind);
		void setBind(unsigned int action, const std::vector<InputCode> & bind);
		void setBind(unsigned int action, const std::vector<std::vector<InputCode>> & bind);
		void setNbAction(unsigned int size);

		void setJoystickId(unsigned int joystickId);
		unsigned int getJoystickId() const;

	protected:
		std::vector<std::vector<std::vector<InputCode>>> _bind;
		unsigned int _joystickId;
  };
}

#endif // !BINDING_HPP_

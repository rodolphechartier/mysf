#include "Binding.hpp"

namespace mysf
{
	Binding::Binding(unsigned int joystickId)
		: _bind()
		, _joystickId(joystickId)
	{

	}

	Binding::Binding(const Binding & o)
		: _bind(o._bind)
		, _joystickId(o._joystickId)
	{

	}

	Binding & Binding::operator=(const Binding & o)
	{
		if (this == &o)
			return *this;
		_bind = o._bind;
		_joystickId = o._joystickId;
		return *this;
	}

	Binding::~Binding()
	{

	}

	const std::vector<Input> * Binding::getInput(unsigned int action, const Event & event) const
	{
		bool stop;

		for (unsigned int i = 0; i < _bind[action].size(); ++i)
		{
			stop = false;
			for (unsigned int j = 0; j < _bind[action][i].size() && !stop; ++j)
			{
				const Input & input = _bind[action][i][j];

				switch (input.type)
				{
					case Input::KeyboardKey:
						stop = (event.key().isDown(input.keycode) == false);
						break;
					case Input::MouseButton:
						stop = (event.mouse().isDown(input.mButton) == false);
						break;
					case Input::MouseWheel:
						stop = (event.mouse().isScrolled(input.wheelDir) == false);
						break;
					case Input::JoystickButton:
						stop = (event.joysticks().isConnected(_joystickId) == false || event.joysticks()[_joystickId].isDown(input.jButton) == false);
						break;
					case Input::JoystickAxis:
						stop = (event.joysticks().isConnected(_joystickId) == false || event.joysticks()[_joystickId].getAxis(input.axis) == 0.f);
						break;
					default:
						return 0;
				}
			}
			if (!stop)
				return &_bind[action][i];
		}
		return 0;
	}

	void Binding::setNbAction(unsigned int size)
	{
		_bind.resize(size);
	}

	void Binding::setBind(unsigned int action, const Input & bind)
	{
		if (action >= _bind.size())
			_bind.resize(action + 1);
		_bind[action].resize(1);
		_bind[action][0].resize(1, bind);
	}

	void Binding::setBind(unsigned int action, const std::vector<Input> & bind)
	{
		if (action >= _bind.size())
			_bind.resize(action + 1);
		_bind[action].resize(1);
		_bind[action][0] = bind;
	}

	void Binding::setBind(unsigned int action, const std::vector<std::vector<Input>> & bind)
	{
		if (action >= _bind.size())
			_bind.resize(action + 1);
		_bind[action] = bind;
	}

	void Binding::setJoystickId(unsigned int joystickId)
	{
		_joystickId = joystickId;
	}

	unsigned int Binding::getJoystickId() const
	{
		return _joystickId;
	}
}

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

	bool Binding::isDown(unsigned int action, const Input & input) const
	{
		bool stop;

		for (unsigned int i = 0; i < _bind[action].size(); ++i)
		{
			stop = false;
			for (unsigned int j = 0; j < _bind[action][i].size() && !stop; ++j)
				switch (_bind[action][i][j].inputType)
				{
					case KeyboardInput:
						if (input.key()[_bind[action][i][j].kcode] == false)
							stop = true;
						break;
					case MouseInput:
						if (input.mouse()[_bind[action][i][j].mcode] == false)
							stop = true;
						break;
					case JoystickInput:
						if (input.joysticks().isConnected(_joystickId) == false || input.joysticks()[_joystickId][_bind[action][i][j].jcode] == false)
							stop = true;
						break;
					default:
						return false;
				}
			if (!stop)
				return true;
		}
		return false;
	}

	void Binding::setBind(unsigned int action, const InputCode & bind)
	{
		if (action >= _bind.size())
			_bind.resize(action + 1);
		_bind[action].resize(1);
		_bind[action][0].resize(1, bind);
	}

	void Binding::setBind(unsigned int action, const std::vector<InputCode> & bind)
	{
		if (action >= _bind.size())
			_bind.resize(action + 1);
		_bind[action].resize(1);
		_bind[action][0] = bind;
	}

	void Binding::setBind(unsigned int action, const std::vector<std::vector<InputCode>> & bind)
	{
		if (action >= _bind.size())
			_bind.resize(action + 1);
		_bind[action] = bind;
	}

	void Binding::setNbAction(unsigned int size)
	{
		_bind.resize(size);
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

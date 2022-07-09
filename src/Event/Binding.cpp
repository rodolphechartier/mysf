#include "Binding.hpp"

namespace mysf
{
    Binding::Binding(unsigned int nbAction, unsigned int joystickId)
        : _bind(nbAction)
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

        for (unsigned int i = 0; i < _bind[action].size(); ++i) {
            stop = false;
            for (unsigned int j = 0; j < _bind[action][i].size() && !stop; ++j) {
                const Input & input = _bind[action][i][j];

                switch (input.type) {
                case Input::Type::KeyboardKey:
                    stop = (event.key().isDown(input.keycode) == false);
                    break;
                case Input::Type::MouseButton:
                    stop = (event.mouse().isDown(input.mButton) == false);
                    break;
                case Input::Type::MouseWheel:
                    stop = (event.mouse().isScrolled(input.wheelDir) == false);
                    break;
                case Input::Type::JoystickButton:
                    stop = (event.joysticks().isConnected(_joystickId) == false || event.joysticks()[_joystickId].isDown(input.jButton) == false);
                    break;
                case Input::Type::JoystickAxis:
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

    bool Binding::load(const std::string & filename, const std::map<std::string, unsigned int> & bind)
    {
        std::map<std::string, Input> sfbind;
        std::ifstream file;
        std::string line;

        file.open(filename.c_str());
        if (file.is_open() == false)
            return false;
        _initSfbind(sfbind);

        for (unsigned int nbline = 1; std::getline(file, line); ++nbline) {
            line = line.substr(0, line.find_first_of("#"));
            _eraseSpace(line);
            if (line.size()) {
                std::size_t pos;
                unsigned int action;

                try {
                    pos = line.find_first_of("=");
                    if (pos != std::string::npos) {
                        action = bind.at(line.substr(0, pos));
                        setBind(action, _parseActionOr(line.substr(pos + 1), sfbind));
                    }
                }
                catch (const std::out_of_range & e) {
                    std::cerr << filename << ": binding error l." << nbline << std::endl;
                }
            }
        }

        file.close();
        return true;
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

    std::vector<std::vector<Input>> Binding::_parseActionOr(std::string line, const std::map<std::string, Input> & sfbind) const
    {
        std::vector<std::vector<Input>> key;

        while (line.size()) {
            std::size_t pos;

            pos = line.find('|');
            key.push_back(_parseActionAnd(line.substr(0, pos), sfbind));
            if (pos == std::string::npos)
                return key;
            line = line.substr(pos + 1);
        }
        return key;
    }

    std::vector<Input> Binding::_parseActionAnd(std::string line, const std::map<std::string, Input> & sfbind) const
    {
        std::vector<Input> key;

        while (line.size()) {
            std::size_t pos;

            pos = line.find('+');
            key.push_back(sfbind.at(line.substr(0, pos)));
            if (pos == std::string::npos)
                return key;
            line = line.substr(pos + 1);
        }
        return key;
    }

    void Binding::_eraseSpace(std::string & str) const
    {
        std::size_t pos, size;

        while ((pos = str.find_first_of(" \n\t")) != std::string::npos) {
            size = str.find_first_not_of(" \n\t", pos);
            if (size != std::string::npos)
                size -= pos;
            str.erase(pos, size);
        }
    }

    void Binding::_initSfbind(std::map<std::string, Input> & sfbind) const
    {
        // KeyboardKey
        sfbind["A"]         = {Input::Type::KeyboardKey, {sf::Keyboard::A}};
        sfbind["B"]         = {Input::Type::KeyboardKey, {sf::Keyboard::B}};
        sfbind["C"]         = {Input::Type::KeyboardKey, {sf::Keyboard::C}};
        sfbind["D"]         = {Input::Type::KeyboardKey, {sf::Keyboard::D}};
        sfbind["E"]         = {Input::Type::KeyboardKey, {sf::Keyboard::E}};
        sfbind["F"]         = {Input::Type::KeyboardKey, {sf::Keyboard::F}};
        sfbind["G"]         = {Input::Type::KeyboardKey, {sf::Keyboard::G}};
        sfbind["H"]         = {Input::Type::KeyboardKey, {sf::Keyboard::H}};
        sfbind["I"]         = {Input::Type::KeyboardKey, {sf::Keyboard::I}};
        sfbind["J"]         = {Input::Type::KeyboardKey, {sf::Keyboard::J}};
        sfbind["K"]         = {Input::Type::KeyboardKey, {sf::Keyboard::K}};
        sfbind["L"]         = {Input::Type::KeyboardKey, {sf::Keyboard::L}};
        sfbind["M"]         = {Input::Type::KeyboardKey, {sf::Keyboard::M}};
        sfbind["N"]         = {Input::Type::KeyboardKey, {sf::Keyboard::N}};
        sfbind["O"]         = {Input::Type::KeyboardKey, {sf::Keyboard::O}};
        sfbind["P"]         = {Input::Type::KeyboardKey, {sf::Keyboard::P}};
        sfbind["Q"]         = {Input::Type::KeyboardKey, {sf::Keyboard::Q}};
        sfbind["R"]         = {Input::Type::KeyboardKey, {sf::Keyboard::R}};
        sfbind["S"]         = {Input::Type::KeyboardKey, {sf::Keyboard::S}};
        sfbind["T"]         = {Input::Type::KeyboardKey, {sf::Keyboard::T}};
        sfbind["U"]         = {Input::Type::KeyboardKey, {sf::Keyboard::U}};
        sfbind["V"]         = {Input::Type::KeyboardKey, {sf::Keyboard::V}};
        sfbind["W"]         = {Input::Type::KeyboardKey, {sf::Keyboard::W}};
        sfbind["X"]         = {Input::Type::KeyboardKey, {sf::Keyboard::X}};
        sfbind["Y"]         = {Input::Type::KeyboardKey, {sf::Keyboard::Y}};
        sfbind["Z"]         = {Input::Type::KeyboardKey, {sf::Keyboard::Z}};
        sfbind["Num0"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num0}};
        sfbind["Num1"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num1}};
        sfbind["Num2"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num2}};
        sfbind["Num3"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num3}};
        sfbind["Num4"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num4}};
        sfbind["Num5"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num5}};
        sfbind["Num6"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num6}};
        sfbind["Num7"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num7}};
        sfbind["Num8"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num8}};
        sfbind["Num9"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Num9}};
        sfbind["Escape"]    = {Input::Type::KeyboardKey, {sf::Keyboard::Escape}};
        sfbind["LControl"]  = {Input::Type::KeyboardKey, {sf::Keyboard::LControl}};
        sfbind["LShift"]    = {Input::Type::KeyboardKey, {sf::Keyboard::LShift}};
        sfbind["LAlt"]      = {Input::Type::KeyboardKey, {sf::Keyboard::LAlt}};
        sfbind["LSystem"]   = {Input::Type::KeyboardKey, {sf::Keyboard::LSystem}};
        sfbind["RControl"]  = {Input::Type::KeyboardKey, {sf::Keyboard::RControl}};
        sfbind["RShift"]    = {Input::Type::KeyboardKey, {sf::Keyboard::RShift}};
        sfbind["RAlt"]      = {Input::Type::KeyboardKey, {sf::Keyboard::RAlt}};
        sfbind["RSystem"]   = {Input::Type::KeyboardKey, {sf::Keyboard::RSystem}};
        sfbind["Menu"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Menu}};
        sfbind["LBracket"]  = {Input::Type::KeyboardKey, {sf::Keyboard::LBracket}};
        sfbind["RBracket"]  = {Input::Type::KeyboardKey, {sf::Keyboard::RBracket}};
        sfbind["SemiColon"] = {Input::Type::KeyboardKey, {sf::Keyboard::SemiColon}};
        sfbind["Comma"]     = {Input::Type::KeyboardKey, {sf::Keyboard::Comma}};
        sfbind["Period"]    = {Input::Type::KeyboardKey, {sf::Keyboard::Period}};
        sfbind["Quote"]     = {Input::Type::KeyboardKey, {sf::Keyboard::Quote}};
        sfbind["Slash"]     = {Input::Type::KeyboardKey, {sf::Keyboard::Slash}};
        sfbind["BackSlash"] = {Input::Type::KeyboardKey, {sf::Keyboard::BackSlash}};
        sfbind["Tilde"]     = {Input::Type::KeyboardKey, {sf::Keyboard::Tilde}};
        sfbind["Equal"]     = {Input::Type::KeyboardKey, {sf::Keyboard::Equal}};
        sfbind["Dash"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Dash}};
        sfbind["Space"]     = {Input::Type::KeyboardKey, {sf::Keyboard::Space}};
        sfbind["Return"]    = {Input::Type::KeyboardKey, {sf::Keyboard::Return}};
        sfbind["BackSpace"] = {Input::Type::KeyboardKey, {sf::Keyboard::BackSpace}};
        sfbind["Tab"]       = {Input::Type::KeyboardKey, {sf::Keyboard::Tab}};
        sfbind["PageUp"]    = {Input::Type::KeyboardKey, {sf::Keyboard::PageUp}};
        sfbind["PageDown"]  = {Input::Type::KeyboardKey, {sf::Keyboard::PageDown}};
        sfbind["End"]       = {Input::Type::KeyboardKey, {sf::Keyboard::End}};
        sfbind["Home"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Home}};
        sfbind["Insert"]    = {Input::Type::KeyboardKey, {sf::Keyboard::Insert}};
        sfbind["Delete"]    = {Input::Type::KeyboardKey, {sf::Keyboard::Delete}};
        sfbind["Add"]       = {Input::Type::KeyboardKey, {sf::Keyboard::Add}};
        sfbind["Subtract"]  = {Input::Type::KeyboardKey, {sf::Keyboard::Subtract}};
        sfbind["Multiply"]  = {Input::Type::KeyboardKey, {sf::Keyboard::Multiply}};
        sfbind["Divide"]    = {Input::Type::KeyboardKey, {sf::Keyboard::Divide}};
        sfbind["Left"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Left}};
        sfbind["Right"]     = {Input::Type::KeyboardKey, {sf::Keyboard::Right}};
        sfbind["Up"]        = {Input::Type::KeyboardKey, {sf::Keyboard::Up}};
        sfbind["Down"]      = {Input::Type::KeyboardKey, {sf::Keyboard::Down}};
        sfbind["Numpad0"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad0}};
        sfbind["Numpad1"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad1}};
        sfbind["Numpad2"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad2}};
        sfbind["Numpad3"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad3}};
        sfbind["Numpad4"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad4}};
        sfbind["Numpad5"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad5}};
        sfbind["Numpad6"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad6}};
        sfbind["Numpad7"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad7}};
        sfbind["Numpad8"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad8}};
        sfbind["Numpad9"]   = {Input::Type::KeyboardKey, {sf::Keyboard::Numpad9}};
        sfbind["F1"]        = {Input::Type::KeyboardKey, {sf::Keyboard::F1}};
        sfbind["F2"]        = {Input::Type::KeyboardKey, {sf::Keyboard::F2}};
        sfbind["F3"]        = {Input::Type::KeyboardKey, {sf::Keyboard::F3}};
        sfbind["F4"]        = {Input::Type::KeyboardKey, {sf::Keyboard::F4}};
        sfbind["F5"]        = {Input::Type::KeyboardKey, {sf::Keyboard::F5}};
        sfbind["F6"]        = {Input::Type::KeyboardKey, {sf::Keyboard::F6}};
        sfbind["F7"]        = {Input::Type::KeyboardKey, {sf::Keyboard::F7}};
        sfbind["F8"]        = {Input::Type::KeyboardKey, {sf::Keyboard::F8}};
        sfbind["F9"]        = {Input::Type::KeyboardKey, {sf::Keyboard::F9}};
        sfbind["F10"]       = {Input::Type::KeyboardKey, {sf::Keyboard::F10}};
        sfbind["F11"]       = {Input::Type::KeyboardKey, {sf::Keyboard::F11}};
        sfbind["F12"]       = {Input::Type::KeyboardKey, {sf::Keyboard::F12}};
        sfbind["F13"]       = {Input::Type::KeyboardKey, {sf::Keyboard::F13}};
        sfbind["F14"]       = {Input::Type::KeyboardKey, {sf::Keyboard::F14}};
        sfbind["F15"]       = {Input::Type::KeyboardKey, {sf::Keyboard::F15}};
        sfbind["Pause"]     = {Input::Type::KeyboardKey, {sf::Keyboard::Pause}};

        // MouseButton
        sfbind["MouseLeft"]     = {Input::Type::MouseButton, {sf::Mouse::Left}};
        sfbind["MouseRight"]    = {Input::Type::MouseButton, {sf::Mouse::Right}};
        sfbind["MouseMiddle"]   = {Input::Type::MouseButton, {sf::Mouse::Middle}};
        sfbind["MouseXButton1"] = {Input::Type::MouseButton, {sf::Mouse::XButton1}};
        sfbind["MouseXButton2"] = {Input::Type::MouseButton, {sf::Mouse::XButton2}};

        // MouseWheel
        sfbind["MouseVertical"]   = {Input::Type::MouseButton, {sf::Mouse::VerticalWheel}};
        sfbind["MouseHorizontal"] = {Input::Type::MouseButton, {sf::Mouse::HorizontalWheel}};

        // JoystickButton
        for (unsigned int i = 0; i < sf::Joystick::ButtonCount; ++i)
            sfbind[std::string("Joystick") + std::to_string(i)] = {Input::Type::JoystickButton, {i}};

        // JoystickAxis
        sfbind["JoystickX"]    = {Input::Type::JoystickAxis, {sf::Joystick::X}};
        sfbind["JoystickY"]    = {Input::Type::JoystickAxis, {sf::Joystick::Y}};
        sfbind["JoystickZ"]    = {Input::Type::JoystickAxis, {sf::Joystick::Z}};
        sfbind["JoystickR"]    = {Input::Type::JoystickAxis, {sf::Joystick::R}};
        sfbind["JoystickU"]    = {Input::Type::JoystickAxis, {sf::Joystick::U}};
        sfbind["JoystickV"]    = {Input::Type::JoystickAxis, {sf::Joystick::V}};
        sfbind["JoystickPovX"] = {Input::Type::JoystickAxis, {sf::Joystick::PovX}};
        sfbind["JoystickPovY"] = {Input::Type::JoystickAxis, {sf::Joystick::PovY}};
    }
}

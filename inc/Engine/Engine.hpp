#ifndef MYSF_ENGINE_HPP_
# define MYSF_ENGINE_HPP_

# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>

# include "GraphicRender.hpp"
# include "Event.hpp"

namespace mysf
{
    template <class Window = sf::RenderWindow>
    class Engine
    {
    private:
        enum class UpdateReturnCode {
            Continue,
            Close,
            Error
        };

    public:
        Engine()
            : _grender(new GraphicRender)
        {

        }

        Engine(const Engine &) = delete;
        Engine & operator=(const Engine &) = delete;

        virtual ~Engine()
        {
            if (_grender)
                delete _grender;
        }

        int run()
        {
            sf::Clock clock;
            UpdateReturnCode ret = UpdateReturnCode::Continue;

            // Doesn't work if put in contructor
            _window.setKeyRepeatEnabled(false);

            _draw(); // 1st render
            while (_window.isOpen()) {
                _processEvents();
                if ((ret = _update(clock.restart())) != UpdateReturnCode::Continue) {
                    _window.close();
                    if (ret == UpdateReturnCode::Error)
                        return 1;
                    return 0;
                }
                _draw();
            }
            return 0;
        }

    private:
        void _processEvents()
        {
            static sf::Event event;

            _event.loop();
            while (_window.pollEvent(event))
                _event.update(event);
        }

        UpdateReturnCode _update(const sf::Time & deltaTime)
        {
            GraphicRender * ret;

            if (!_grender)
                return UpdateReturnCode::Error;
            if ((ret = _grender->update(deltaTime, _event)) != _grender) {
                delete _grender;
                _grender = ret;
                if (_grender == 0)
                    return UpdateReturnCode::Close;
                _event.reset();
            }
            return UpdateReturnCode::Continue;
        }

        void _draw()
        {
            _window.clear();
            if (_grender)
                _grender->draw(_window);
            _window.display();
        }

    protected:
        Window _window;
        GraphicRender * _grender;
        Event _event;
    };
}

#endif // !MYSF_ENGINE_HPP_

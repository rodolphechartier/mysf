#ifndef MYSF_GRAPHIC_RENDER_HPP_
# define MYSF_GRAPHIC_RENDER_HPP_

# include "GraphicLayerSet.hpp"
# include "SoundPlayer.hpp"

namespace mysf
{
    class GraphicRender
    {
    public:
        GraphicRender();
        GraphicRender(const GraphicRender &) = delete;
        GraphicRender & operator=(const GraphicRender &) = delete;
        virtual ~GraphicRender();

        GraphicRender * update(const sf::Time & deltaTime, const Event & event);
        void draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates()) const;

        virtual GraphicRender * onUpdate(const sf::Time & deltaTime, const Event & event);
        virtual void onDraw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates()) const;

    protected:
        GraphicLayerSet _gls;
        SoundPlayer _spl;
    };
}

#endif // !MYSF_GRAPHIC_RENDER_HPP_

#include "GraphicRender.hpp"

namespace mysf
{
    GraphicRender::GraphicRender()
    {

    }

    GraphicRender::~GraphicRender()
    {

    }

    GraphicRender * GraphicRender::update(const sf::Time & deltaTime, const Event & event)
    {
        _spl.removeStoppedSounds();
        _gls.update(deltaTime, event);
        return onUpdate(deltaTime, event);
    }

    void GraphicRender::draw(sf::RenderTarget & target, sf::RenderStates states) const
    {
        _gls.draw(target, states);
        onDraw(target, states);
    }

    GraphicRender * GraphicRender::onUpdate(const sf::Time & /* deltaTime */, const Event & /* event */)
    {
        return this;
    }

    void GraphicRender::onDraw(sf::RenderTarget & /* target */, sf::RenderStates /* states */) const
    {

    }
}

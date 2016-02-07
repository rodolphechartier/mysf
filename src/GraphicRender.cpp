#include "GraphicRender.hpp"

namespace mysf
{
  GraphicRender::GraphicRender(Context & ctx)
    : _ctx(ctx)
  {

  }

  GraphicRender::~GraphicRender()
  {

  }

  GraphicRender * GraphicRender::update(const sf::Time & deltaTime, const Input & input)
  {
    _ctx.gls.update(deltaTime, input);
    return this;
  }

  void GraphicRender::draw() const
  {
    _ctx.gls.draw(_ctx.win, sf::RenderStates());
  }
}

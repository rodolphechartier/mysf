#include "GraphicRender.hpp"

namespace mysf
{
  GraphicRender::GraphicRender()
  {

  }

  GraphicRender::~GraphicRender()
  {

  }

	bool GraphicRender::init()
	{
		return true;
	}

  GraphicRender * GraphicRender::update(const sf::Time & deltaTime, const Event & event)
  {
    ctx.gls.update(deltaTime, event);
    return this;
  }

  void GraphicRender::draw() const
  {
    ctx.gls.draw(ctx.win);
  }
}

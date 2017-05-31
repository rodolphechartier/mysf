#ifndef GRAPHIC_RENDER_HPP_
# define GRAPHIC_RENDER_HPP_

# include "Context.hpp"

namespace mysf
{
  class GraphicRender
  {
  public:
    GraphicRender();
    GraphicRender(const GraphicRender &) = delete;
    GraphicRender & operator=(const GraphicRender &) = delete;
    virtual ~GraphicRender();

    virtual bool init() = 0;

    virtual GraphicRender * update(const sf::Time & deltaTime, const Event & event);
    virtual void draw() const;
  };
}

#endif // !GRAPHIC_RENDER_HPP_

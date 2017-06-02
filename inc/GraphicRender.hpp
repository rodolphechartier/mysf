#ifndef MYSF_GRAPHIC_RENDER_HPP_
# define MYSF_GRAPHIC_RENDER_HPP_

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

#endif // !MYSF_GRAPHIC_RENDER_HPP_

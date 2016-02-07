#ifndef GRAPHIC_RENDER_HPP_
# define GRAPHIC_RENDER_HPP_

# include "Context.hpp"

namespace mysf
{
  class GraphicRender
  {
  public:
    explicit GraphicRender(Context & ctx);
    GraphicRender(const GraphicRender &);
    GraphicRender & operator=(const GraphicRender &);
    virtual ~GraphicRender();

    virtual bool	init() = 0;

    GraphicRender *	update(const sf::Time & deltaTime, const Input & input);
    void		draw() const;

  protected:
    Context &		_ctx;
  };
}

#endif // !GRAPHIC_RENDER_HPP_

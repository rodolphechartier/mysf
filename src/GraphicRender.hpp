#ifndef GRAPHIC_RENDER_HPP_
# define GRAPHIC_RENDER_HPP_

# include "Context.hpp"

class GraphicRender
{
public:
  explicit GraphicRender(Context & ctx);
  GraphicRender(const GraphicRender &);
  GraphicRender & operator=(const GraphicRender &);
  virtual ~GraphicRender();

  virtual bool			init() = 0;

  virtual GraphicRender *	update(float deltaTime, const Input & input);
  virtual void			draw() const;

protected:
  Context &			_ctx;
};

#endif // !GRAPHIC_RENDER_HPP_

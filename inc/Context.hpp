#ifndef CONTEXT_HPP_
# define CONTEXT_HPP_

# include <SFML/Window.hpp>

# include "GraphicLayerSet.hpp"
# include "ResourceHolder.hpp"

namespace mysf
{
  struct Context
  {
    sf::RenderWindow  win;
    GraphicLayerSet	  gls;
    TextureHolder	    thl;
    SoundHolder		    shl;
    FontHolder		    fhl;
  };
}

#endif // !CONTEXT_HPP_

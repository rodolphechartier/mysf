#ifndef CONTEXT_HPP_
# define CONTEXT_HPP_

# include <SFML/Window.hpp>

# include "GraphicLayerSet.hpp"
# include "SoundPlayer.hpp"
# include "ResourceHolder.hpp"

namespace mysf
{
  struct Context
  {
    sf::RenderWindow  win;
    GraphicLayerSet	  gls;
		SoundPlayer				spl;
    TextureHolder	    thl;
    SoundHolder		    shl;
    FontHolder		    fhl;
  };

	extern Context ctx;
}

#endif // !CONTEXT_HPP_

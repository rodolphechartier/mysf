#ifndef MYSF_CONTEXT_HPP_
# define MYSF_CONTEXT_HPP_

# include <SFML/Window.hpp>

# include "GraphicLayerSet.hpp"
# include "SoundPlayer.hpp"
# include "ResourceHolder.hpp"

namespace mysf
{
  struct Context
  {
    sf::RenderWindow *	win;
    GraphicLayerSet 		gls;
		SoundPlayer					spl;
    TextureHolder	    	thl;
    SoundBufferHolder		shl;
    FontHolder		    	fhl;
  };

	extern Context ctx;
}

#endif // !MYSF_CONTEXT_HPP_

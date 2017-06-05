# Mysf

Mysf is a Library based on the SFML, its goal is to easly create 2D games. To do so, mysf provides 2D games base code you would have to think of, so you don't have to recode all-over again what you would do otherwise.

### Prerequisites

The library is based on the SFML so you will need to install the [SFML](https://www.sfml-dev.org/download.php) first.

### Installing

Download the project and compile it with the makefile. It will generates .a and .so libraries.

### Running the tests

There's an example directory that contains a project wich you can run to test if the library works.

# Documentation

### **Engine and Context**

The `mysf::Engine` is the main class of the library. It handles the loop game, process events and call update and draw funtions of its `_grender` instance.

`mysf::Engine` was design to be inherited to override its `virtual bool init(int ac, char ** av);` function (ac and av were design to be the main arguments, but we can decide to not use them). Within the function, we can create our window (wich is in the Gloabal Context, we will see that later in the documentation), instanciate your own GraphicRender, set the default sprites and plenty other things.

If There's no _grender instance in the Engine, nothing will happend. So you have to give the `mysf::GraphicRender * _grender` protected attribut an instance in the init function and init the GraphicRender instance via its `virtual bool init();` function.

Then in the main function, you just have to instantiate, initialize and run the Engine like so:

```
int main(int ac, char ** av)
{
  mysf::Engine engine;

  if (engine.init(ac, av) == false)
    return 1;
  return engine.run();
}
```

The `mysf::Context ctx` is a global structure defined in the Context.hpp file. It contains:
* `sf::RenderWindow win` - The main window
* `mysf::GraphicLayerSet gls`
* `mysf::SoundPlayer spl`
* `mysf::TextureHolder thl`
* `mysf::SoundBufferHolder shl`
* `mysf::FontHolder fhl`


ResourceHolder (Texture / Sound / Font)

### **GraphicRender and GraphicLayers**

GraphicRender
GraphicLayerSet
GraphicLayer

### **SceneNode**

SceneNode
SpriteNode

### **Event**

Event
Key
Mouse
Joystick
Binding (Input / EventType)

### **Sound**

SoundPlayer

## Authors

* **Rodolphe Chartier** - [rodolphechartier](https://github.com/rodolphechartier)

## License

This project is not licensed yet, you can use it for personal and/or profesional uses.

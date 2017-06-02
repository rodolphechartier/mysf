# Mysf

Mysf is a Librabry based on SFML. Its goal is to easly create 2D games. To do it, there is for example an Engine that already handles the loopGame so you don't have to recode all-over again code that you would do otherwise.

### Prerequisites

The library is based on the SFML so you will need to install the * [SFML](https://www.sfml-dev.org/download.php) first.

### Installing

Download the project et compile it with the make file. It will generates .a and .so libraries.

## Running the tests

There's an example directory that contain a project wich you can run to test if the lib works.

## Documentation

  First thing first, you must inherites from `mysf::Engine` class and overide the `virtual bool init(int ac, char **av);` function.
In this function, you will have to assign a new instance to the `_grender` protected attribut. This instance must be inherited from `mysf::GraphicRender` and overrive the `virtual bool init();` function as well as the `mysf::Engine`.

```
class Render : public mysf::GraphicRender
{
public:
  virtual bool init()
  {
    return true;
  }
};

class Main : public mysf::Engine
{
public:
  virtual bool init(int /* ac */, char ** /* av */)
  {
    _grender = new Render;
    return _grender->init();
  }
};
```
To fully understand what's going on here, checkout `inc/Engine.hpp` and `inc/GraphicRender.hpp` files. And generally check out hpp files.

Your `main` function then just have to instanciate, initialize and run the Engine. It does look like this:
```
int main(int ac, char ** av)
{
  Main test;

  if (test.init(ac, av) == false)
    return 1;
  return test.run();
}
```

When the `mysf::Engine::run();` function is called, the loop game begins. It will call updates and draw functions of the `_grender` instance. It will updates automaticly `mysf::Event` too. You can consider an instance of the `mysf::GraphicRender` as a Scene in a game.

Now, in your own graphicRender, you can use `mysf::SceneNode`. This class provide a child/parent relation to draw and update. It means that if you attach a child to a SceneNode, its position, rotation and globally its transformation will be relativ to its parents. Use this draw a lifebar, or characters names above their heads. `mysf::SpriteNode` is a class inherited from  `mysf::SceneNode` and you can assign an `sf::Texture` to it, set a position, a rotation and all things you can do with a `sf::Sprite`.

The `mysf::SceneNode` provides an `virtual void updateCurrent(const sf::Time &, const mysf::Event &)` function wich is design to "script" your node in the scene.

To add a SceneNode to your game you have 2 different choices, add it to the GraphicLayerSet inside the Global Context wich is accessible like this `mysf::ctx::gls`. Set, add or sub the number of layer you want to the gls with these following funtions:

```
void		resize(unsigned int nbLayer);
void		add(unsigned int nbLayer);
void		sub(unsigned int nbLayer);
```

Then access it with the `GrapahicLayer & operator[]`.

## Authors

* **Rodolphe Chartier** - [rodolphechartier](https://github.com/rodolphechartier)

## License

This project is not licensed yet, you can use it for personal and/or profesional uses.

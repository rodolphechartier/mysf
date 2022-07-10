# TODO

## **GUI**

### Layout

### CI

* Button
    * ToggleButton
    * RadioButton
    * Checkbox
* Slider
    * ScrollBar
    * DialSlider
* MessageBox
* TextField

====

Common properties:

* position
    * x
    * y
* size
    * width
    * heigth

====

       CI       |               In               |     Out
--------------------------------------------------------------------------------
 Button         | std::string text               | void function()
                | sf::Texture icon               |
--------------------------------------------------------------------------------
 ToggleButton   | std::vector<std::string> text  | unsigned int function()
                | std::vector<sf::Texture> icon  |
--------------------------------------------------------------------------------
 RadioButton    | std::vector<std::string> text  | unsigned int function()
                | sf::Texture checkedTexture     |
                | sf::Texture uncheckedTexture   |
--------------------------------------------------------------------------------
 Checkbox       | std::vector<std::string> text  | std::vector<unsigned int> function()
                | sf::Texture checkedTexture     | bool function(unsigned int)
                | sf::Texture uncheckedTexture   |
--------------------------------------------------------------------------------
 Slider<T>      | T min                          | T function()
                | T max                          |
                | T step                         |
                | mysf::Direction direction      |
--------------------------------------------------------------------------------
 ScrollBar      | int min                        | int function()
                | int max                        |
                | int step                       |
                | mysf::Direction direction      |
--------------------------------------------------------------------------------
 DialSlider<T>  | T min                          | T function()
                | T max                          |
                | T step                         |
                | mysf::Direction direction      |
--------------------------------------------------------------------------------
 MessageBox     | std::string title              |
--------------------------------------------------------------------------------
 TextField      | std::string title              | std::string function()

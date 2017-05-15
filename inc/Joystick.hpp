#ifndef JOYSTICK_HPP_
# define JOYSTICK_HPP_

# include <vector>

# include <SFML/Window.hpp>

namespace mysf
{
  class Joystick
  {
  public:
    explicit Joystick(unsigned int id);
    Joystick(const Joystick & o);
    Joystick & operator=(const Joystick & o);
    virtual ~Joystick();

    void	update();
    void	reset();

    unsigned int getID() const;
    bool  operator[](unsigned int button) const;
    bool	isDown(unsigned int button) const;
    bool	isDown(const std::vector<unsigned int> & buttons) const;

    float operator[](sf::Joystick::Axis axis) const;
    float getAxisPosition(sf::Joystick::Axis axis) const;

  protected:
    const unsigned int _id;
    std::vector<bool>	_down;
    std::vector<float> _axis;
  };
}

#endif // !JOYSTICK_HPP_

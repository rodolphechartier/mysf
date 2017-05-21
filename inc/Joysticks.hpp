#ifndef JOYSTICKS_HPP_
# define JOYSTICKS_HPP_

# include <vector>

# include <SFML/Window.hpp>

namespace mysf
{
  class Joysticks
  {
  public:
    class Joystick
    {
			friend class Joysticks;

    public:
      Joystick();
      Joystick(const Joystick & o);
      Joystick & operator=(const Joystick & o);
      virtual ~Joystick();

      void connect();
      void disconnect();
      bool isConnected() const;

      void reset();

			bool 		isDown(unsigned int button) const;
			float 	getAxis(sf::Joystick::Axis axis) const;

    private:
      bool _isConnected;
      std::vector<bool> _down;
      std::vector<float> _axis;
    };

  public:
    Joysticks();
    Joysticks(const Joysticks & o);
    Joysticks & operator=(const Joysticks & o);
    virtual ~Joysticks();

    void	update(const sf::Event & event);
    void	reset();

    const Joystick & operator[](unsigned int joystick) const;
    unsigned int size() const;
    unsigned int nbConnected() const;
		bool isConnected(unsigned int joystick) const;

  private:
    void connect(unsigned int joystick);
    void disconnect(unsigned int joystick);

  protected:
    std::vector<Joystick> _joysticks;
    unsigned int          _nbConnected;
  };
}

#endif // !JOYSTICKS_HPP_

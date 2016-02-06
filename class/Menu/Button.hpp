#ifndef BUTTON_HPP_
# define BUTTON_HPP_

# include "Updatable.hpp"

# include "Context.hpp"
# include "Resource.hpp"

class Button : public Updatable
{
public:
  explicit Button(Context & ctx, int & select, bool & check, const std::string & text, int id);
  Button(const Button &);
  Button & operator=(const Button &);
  virtual ~Button();

  virtual void		update(float deltaTime, const Input & input);
  virtual void		draw(sf::RenderTarget & target, sf::RenderStates states) const;

  void			setText(const std::string & text);
  void			setFont(const sf::Font & font);
  void			setCharacterSize(unsigned int characterSize);
  void			setColor(const sf::Color & color);
  void			setColorSelected(const sf::Color & color);
  void			setTextColor(const sf::Color & color);
  void			setTextColorSelected(const sf::Color & color);

  const sf::String &	getText() const;
  const sf::Text &	getText2() const;
  const sf::Font &	getFont() const;
  unsigned int		getCharacterSize() const;
  const sf::Color &	getColor() const;
  const sf::Color &	getColorSelected() const;
  const sf::Color &	getTextColor() const;
  const sf::Color &	getTextColorSelected() const;

  void			updateSize();

private:
  Context &	_ctx;

  int &		_select;
  bool &	_check;
  sf::Text	_text;
  int		_id;

  sf::Color	_color;
  sf::Color	_colorSelected;
  sf::Color	_textColor;
  sf::Color	_textColorSelected;
};

#endif // !BUTTON_HPP_

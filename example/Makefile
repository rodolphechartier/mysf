CC				= g++
CPPFLAGS	+= -Wall -Wextra -pedantic -Werror -o3 -std=c++11
CPPFLAGS	+= -I ../inc
CPPFLAGS	+= -I /usr/local/include

NAME			= a.out

LIBSFML		= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LIBMYSF		= -L ../ -lmysf

LIB				= $(LIBSFML) $(LIBMYSF)

SRC				= main.cpp

OBJ				= $(SRC:.cpp=.o)

RM				= rm -f

all: $(NAME)

$(NAME): cplib $(OBJ)
	$(CC)  $(CPPFLAGS) $(LIB) $(OBJ) -o $(NAME)

cplib:
	cp ../libmysf.so ../libmysf.a .

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY		= all $(NAME) cplib clean fclean re

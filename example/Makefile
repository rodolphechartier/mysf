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

$(NAME): make_lib $(OBJ)
	$(CC)  $(CPPFLAGS) $(LIB) $(OBJ) -o $(NAME)

make_lib:
	make -C ../
	cp ../libmysf.so ../libmysf.a .

clean:
	make clean -C ../
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ../
	$(RM) $(NAME)

re: fclean all

.PHONY		= all $(NAME) cplib clean fclean re

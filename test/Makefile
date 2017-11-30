CC		= g++
CPPFLAGS	+= -Wall -Wextra -Werror -o3 -std=c++14
CPPFLAGS	+= -I ../inc
CPPFLAGS	+= -I /usr/local/include
LDFLAGS		= $(LIB)

LIBSFML		= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LIBMYSF		= -L ./ -lmysf
LIB		= $(LIBSFML) $(LIBMYSF)

SRC		= test_anim.cpp

OBJ		= $(SRC:.cpp=.o)

NAME		= anim.out

RM		= rm -f
LN		= ln -s

all: libmysf $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

libmysf:
	make -C ../
	$(RM) ./libmysf.so ./libmysf.a
	$(LN) ../libmysf.so ./libmysf.so
	$(LN) ../libmysf.a ./libmysf.a

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY		= all $(NAME) clean fclean re

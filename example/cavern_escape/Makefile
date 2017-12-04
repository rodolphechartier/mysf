CC			= g++
CPPFLAGS	+= -Wall -Wextra -Werror -o3 -std=c++11
CPPFLAGS	+= -I ../../inc/ -I ./inc/
CPPFLAGS	+= -I /usr/local/include/
LDFLAGS		= $(LIB)

LIBSFML		= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LIBMYSF		= -L ../../ -lmysf
LIB			= $(LIBSFML) $(LIBMYSF)

SRCDIR		= src/
SRC			= $(SRCDIR)main.cpp \
			$(SRCDIR)Game.cpp

OBJ			= $(SRC:.cpp=.o)

LIBNAME		= libmysf
NAME		= cavern_escape.out

RM			= rm -f
LN			= ln -s

all: $(LIBNAME) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

$(LIBNAME):
	make -C ../../
	$(RM) ./$(LIBNAME).so ./$(LIBNAME).a
	$(LN) ../../$(LIBNAME).so ./$(LIBNAME).so
	$(LN) ../../$(LIBNAME).a ./$(LIBNAME).a

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ./$(LIBNAME).so ./$(LIBNAME).a

re: fclean all

.PHONY		= all $(NAME) $(LIBNAME) clean fclean re

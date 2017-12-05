CC			= g++
CPPFLAGS	+= -Wall -Wextra -Werror -o3 -std=c++11
CPPFLAGS	+= -I $(LIBPATH)inc
CPPFLAGS	+= -I /usr/local/include
LDFLAGS		= $(LIB)

LIBSFML		= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LIBMYSF		= -L ./ -lmysf
LIB			= $(LIBSFML) $(LIBMYSF)

SRC			= main.cpp

OBJ			= $(SRC:.cpp=.o)

LIBNAME		= libmysf
LIBPATH		= ../../
NAME		= basics.out

RM			= rm -f
LN			= ln -s

all: $(LIBNAME) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

$(LIBNAME):
	make -C $(LIBPATH)
	$(RM) ./$(LIBNAME).so ./$(LIBNAME).a
	$(LN)  $(LIBPATH)$(LIBNAME).so ./$(LIBNAME).so
	$(LN)  $(LIBPATH)$(LIBNAME).a ./$(LIBNAME).a

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ./$(LIBNAME).so ./$(LIBNAME).a

re: fclean all

.PHONY		= all $(NAME) $(LIBNAME) clean fclean re

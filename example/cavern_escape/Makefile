CC			= g++
CPPFLAGS	+= -Wall -Wextra -Werror -o3 -std=c++11
CPPFLAGS	+= -I ../../inc/ -I ./inc/ -I ./inc/Node/
CPPFLAGS	+= -I /usr/local/include/
LDFLAGS		= $(LIB)

LIBSFML		= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LIBMYSF		= -L ../../ -lmysf
LIB			= $(LIBSFML) $(LIBMYSF)

SRCDIR		= src/
NODEDIR		= $(SRCDIR)Node/

SRC			= $(SRCDIR)main.cpp \
			$(SRCDIR)Game.cpp \
			$(SRCDIR)Map.cpp \
			$(NODEDIR)Life.cpp \
			$(NODEDIR)Score.cpp \
			$(NODEDIR)Helicopter.cpp \
			$(NODEDIR)HelicopterIdle.cpp \
			$(NODEDIR)HelicopterHit.cpp \
			$(NODEDIR)HelicopterDestroy.cpp

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

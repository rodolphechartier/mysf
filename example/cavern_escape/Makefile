LIBNAME		= libmysf
LIBPATH		= ../..
NAME		= cavern_escape.out

LIBSFML		= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LIBMYSF		= -L $(LIBPATH) -lmysf
LIB			= $(LIBSFML) $(LIBMYSF)

RM			= rm -f
LN			= ln -s

CC			= g++
CPPFLAGS	+= -Wall -Wextra -Werror -o3 -std=c++11
CPPFLAGS	+= -I $(LIBPATH)/inc -I $(LIBPATH)/inc/Engine -I $(LIBPATH)/inc/Event -I $(LIBPATH)/inc/Node
CPPFLAGS	+= -I ./inc/ -I ./inc/Node/
CPPFLAGS	+= -I /usr/local/include/
LDFLAGS		= $(LIB)

SRCDIR		= src/
NODEDIR		= $(SRCDIR)Node/

SRC			= \
			$(SRCDIR)main.cpp \
			$(SRCDIR)Game.cpp \
			$(SRCDIR)Gameover.cpp \
			$(SRCDIR)Map.cpp \
			$(NODEDIR)Life.cpp \
			$(NODEDIR)Score.cpp \
			$(NODEDIR)Helicopter.cpp \
			$(NODEDIR)HelicopterIdle.cpp \
			$(NODEDIR)HelicopterHit.cpp \
			$(NODEDIR)HelicopterDestroy.cpp

OBJ			= $(SRC:.cpp=.o)

all: $(LIBNAME) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

$(LIBNAME):
	make -C $(LIBPATH)
	$(RM) ./$(LIBNAME).so ./$(LIBNAME).a
	$(LN) $(LIBPATH)/$(LIBNAME).so ./$(LIBNAME).so
	$(LN) $(LIBPATH)/$(LIBNAME).a ./$(LIBNAME).a

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ./$(LIBNAME).so ./$(LIBNAME).a

re: fclean all

.PHONY		= all $(NAME) $(LIBNAME) clean fclean re

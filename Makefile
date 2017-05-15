CC				= g++
CPPFLAGS	+= -Wall -Wextra -pedantic -Werror -o3 -std=c++11 -fPIC
CPPFLAGS	+= -I ./inc
CPPFLAGS	+= -I /usr/local/include

LIBSFML		= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

SRC				= src/AEngine.cpp \
						src/GraphicLayerSet.cpp \
						src/GraphicRender.cpp \
						src/Input.cpp \
						src/Key.cpp \
						src/KeyBinding.cpp \
						src/Layer.cpp \
						src/Mouse.cpp \
						src/SceneNode.cpp

OBJ				= $(SRC:.cpp=.o)

NAME			= mysf
NAME_STC	= lib$(NAME).a
NAME_DYN	= lib$(NAME).so

RM				= rm -f

all: $(NAME_STC) $(NAME_DYN)

$(NAME_STC): $(OBJ)
	ar rc $(NAME_STC) $(OBJ)
	ranlib $(NAME_STC)

$(NAME_DYN): $(OBJ)
	$(CC) -shared $(OBJ) $(CPPFLAGS) $(LIBSFML) -o $(NAME_DYN)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME_STC) $(NAME_DYN)

re: fclean all

.PHONY		= all $(NAME_STC) $(NAME_DYN) clean fclean re

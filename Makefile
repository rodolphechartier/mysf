CC			= g++
CPPFLAGS	+= -Wall -Wextra -pedantic -Werror -o3 -std=c++14 -fPIC
CPPFLAGS	+= -I ./inc -I ./inc/Engine -I ./inc/Event -I ./inc/Node
CPPFLAGS	+= -I /usr/local/include

LIBSFML		= -L /usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

SRC			= \
			src/Engine/GraphicLayer.cpp \
			src/Engine/GraphicLayerSet.cpp \
			src/Engine/GraphicRender.cpp \
			src/Engine/SoundPlayer.cpp \
			src/Event/Event.cpp \
			src/Event/Binding.cpp \
			src/Event/Key.cpp \
			src/Event/Mouse.cpp \
			src/Event/Joysticks.cpp \
			src/Node/SceneNode.cpp \
			src/Node/SpriteNode.cpp \
			src/Node/TextNode.cpp \
			src/Node/ShapeNode.cpp \
			src/Node/CircleShapeNode.cpp \
			src/Node/RectangleShapeNode.cpp \
			src/Node/ConvexShapeNode.cpp \
			src/Node/AnimNode.cpp

OBJ			= $(SRC:.cpp=.o)

NAME		= mysf
NAME_STC	= lib$(NAME).a
NAME_DYN	= lib$(NAME).so

RM			= rm -f

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

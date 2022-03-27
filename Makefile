##
## EPITECH PROJECT, 2019
## Navy
## File description:
## Navy
##

NAME	=	GameOfLife

CC	=	g++ -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

RM	=	rm -f

SRCS	=	src/main.cpp					\
			src/Window.cpp					\
			src/Sprite.cpp					\
			src/buttons/ButtonQuit.cpp		\
			src/buttons/ButtonHelp.cpp		\
			src/buttons/ButtonHome.cpp		\
			src/buttons/ButtonStart.cpp		\
			src/buttons/ButtonMusic.cpp		\
			src/buttons/ButtonPause.cpp		\
			src/buttons/ButtonRestart.cpp	\

OBJS	= 	$(SRCS:.cpp=.o)

CFLAGS 	+=	-Wall -Wextra

all:		$(NAME)

$(NAME): 	$(OBJS)
	 		$(CC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re

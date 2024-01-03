NAME = ClapTrap
FLAGS = -Wall -Wextra -Werror
SRCS = main.cpp ClapTrap.cpp
OBJ = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	c++ -o $(NAME) $(OBJ) $(FLAGS)

$(OBJ): $(SRCS)
	c++ -c  $(SRCS) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
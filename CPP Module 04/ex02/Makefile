NAME = AbstractAnimalsWithBrains
FLAGS = -std=c++11 -Wall -Wextra -Werror
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
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
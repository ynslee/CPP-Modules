NAME = RPN
FLAGS = -std=c++17 -Wall -Wextra -Werror
SRCS = main.cpp RPN.cpp
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
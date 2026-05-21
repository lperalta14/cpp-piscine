NAME = megaphone
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
.PHONY: all clean fclean re

all: $(NAME)
$(NAME):
	$(CXX) $(SRC) $(FLAGS) -o $(NAME)
clean: 
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all

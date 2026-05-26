NAME = LoverBoy
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = 
OBJ = $(SRC:.cpp=.o)
.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean: 
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all

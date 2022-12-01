CXX		= c++
# CXXFLAGS= -Wall -Wextra -Werror -std=c++98

NAME	= a.out

SRCS	= main.cpp Fixed.cpp bsp.cpp Point.cpp
OBJS	= $(SRCS:.cpp=.o)
HEADERS	= Fixed.hpp Point.hpp

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re

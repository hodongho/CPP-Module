CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

NAME	= a.out

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)
HEADERS	= MutantStack.hpp

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

$(OBJS)	: $(HEADERS)

.PHONY : all bonus clean fclean re

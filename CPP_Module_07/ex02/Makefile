CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

NAME	= a.out

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)
HEADERS	= Array.hpp

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJG)	: $(HEADERS)

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all


.PHONY : all bonus clean fclean re

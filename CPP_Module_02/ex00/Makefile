CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

NAME	= a.out

SRCS	= main.cpp Fixed.cpp
OBJS	= $(SRCS:.cpp=.o)
HEADERS	= Fixed.hpp

ifdef DFLAG
	CXXFLAGS += -g2 -fsanitize=address
endif

ifdef 98
	CXX	= g++
	CXXFLAGS += -pedantic
endif


debug:
	@make fclean
	@make DFLAG=1 all

98:
	@make fclean
	@make 98=1 all


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

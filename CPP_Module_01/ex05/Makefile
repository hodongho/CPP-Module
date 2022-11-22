CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

NAME	= Harl

SRCS	= main.cpp Harl.cpp
OBJS	= $(SRCS:.cpp=.o)
HEADER	= Harl.hpp

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

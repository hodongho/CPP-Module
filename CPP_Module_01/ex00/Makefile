CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

NAME	= Zombie

SRCS	= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS	= $(SRCS:.cpp=.o)

ifdef DFLAG
	CXXFLAGS += -g2 -fsanitize=address
endif

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

debug:
	@make fclean
	@make DFLAG=1 all

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re

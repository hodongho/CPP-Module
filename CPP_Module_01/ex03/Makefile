CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

NAME	= Weapon

SRCS	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS	= $(SRCS:.cpp=.o)
HEADER	= Weapon.hpp HumanA.hpp HumanB.hpp

ifdef DFLAG
	CXXFLAGS += -g2 -fsanitize=address
endif

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJS) : $(HEADER)

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

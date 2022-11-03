# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhyun <dhyun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:39:43 by dhyun             #+#    #+#              #
#    Updated: 2022/11/03 13:33:36 by dhyun            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

NAME	= megaphone

SRCS	= megaphone.cpp
OBJS	= $(SRCS:.cpp=.o)

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

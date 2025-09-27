# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 17:23:32 by ialashqa          #+#    #+#              #
#    Updated: 2025/09/23 17:23:32 by ialashqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.O: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
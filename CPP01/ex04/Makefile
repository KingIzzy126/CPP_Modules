# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 20:05:54 by ialashqa          #+#    #+#              #
#    Updated: 2025/08/03 18:17:26 by ismailalash      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex04

SRCS = main.cpp
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
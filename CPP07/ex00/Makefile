# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/28 16:00:23 by ismailalash       #+#    #+#              #
#    Updated: 2026/03/28 16:00:44 by ismailalash      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Run

SRCS = Main.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
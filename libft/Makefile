# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 11:59:12 by vonischu          #+#    #+#              #
#    Updated: 2018/10/18 06:50:15 by vonischu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = $(wildcard ./*.c)
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
FLAGS ?= -c -Wall -Wextra -Werror
FLAGS += -I./

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $@ $^
	@ranlib $@

%.o: ./%.c
	@$(CC) $(FLAGS) $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/21 17:55:25 by vonischu          #+#    #+#              #
#    Updated: 2018/10/21 17:55:26 by vonischu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

target = fractol
libft = ./libft/libft.a

sources_d = ./src
objects_d = ./obj

sources := $(shell find $(sources_d) -type f -name "*.c")
objects := $(patsubst $(sources_d)%,$(objects_d)%,$(sources:.c=.o))

CC=gcc
CFLAGS ?= -Wall -Werror -Wextra -g
IFLAGS := -I ./inc

.PHONY: all clean fclean re libft

all: $(target)

$(target): $(objects) $(libft)
	$(CC) -o $@ $^ -lmlx -framework OpenGL -framework AppKit
$(objects_d)/%.o: $(sources_d)/%.c | $(objects_d)
	$(CC) -c $< -o $@ $(CFLAGS) $(IFLAGS)
$(objects_d):
	mkdir -p $@

$(libft):
	@$(MAKE) -C ./libft/ all
clean:
	@rm -fr $(objects_d)
	@$(MAKE) -C ./libft/ clean
fclean: clean
	@rm -f $(target)
	@$(MAKE) -C ./libft/ fclean
re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knaumov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 10:18:27 by knaumov           #+#    #+#              #
#    Updated: 2018/10/29 14:34:28 by knaumov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ./srcs/*.c ./utils/*.c
INCLUDES = -I ./includes
LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS) $(INCLUDES) -c -g
	@echo "$(GREEN)Making objects files$(RESET)"
	@make -C libft
	@ar rc $(NAME) ./*.o ./libft/*.o
	@ranlib $(NAME)
	@echo "$(GREEN)Compiling libftprintf.a$(RESET)"
	@echo "$(BLUE)Complete$(RESET)"

clean:
	@/bin/rm -f ./*.o
	@echo "$(RED)Deleting objects for libftprintf.a$(RESET)"
	@echo "$(BLUE)Complete$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)Deleting libftprintf.a$(RESET)"
	@make -C libft fclean
	@echo "$(BLUE)Complete$(RESET)"

re: fclean all

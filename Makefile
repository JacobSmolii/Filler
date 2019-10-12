# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 12:37:43 by vsmolii           #+#    #+#              #
#    Updated: 2019/05/29 13:55:01 by vsmolii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vsmolii.filler
LIB = filler.a
GCCW = gcc -Wall -Werror -Wextra
SRC = *.c
LIBFT = libft/libft.a
INCLUDES = filler.h

OBJECT = $(SRC:.c=.o)

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m

all: $(NAME)

$(NAME):
	@echo "$(GREEN)Making objects files"
	@make -C libft
	@$(GCCW) -c -g $(SRC) $(INCLUDES)
	@ar rc $(LIB) $(OBJECT) ./libft/*.o
	@ranlib $(LIB)
	@$(GCCW) $(LIB) -o $(NAME)
	@echo "$(GREEN)Compiling vsmolii.filler"

clean:
	@echo "$(RED)Deleting objects for filler"
	@/bin/rm -f $(OBJECT)
	@make -C libft clean

fclean: clean
	@echo "$(RED)Deleting filler"
	@/bin/rm -f $(NAME) $(LIB)
	@make -C libft fclean

re: fclean all
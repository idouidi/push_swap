# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 19:04:31 by user42            #+#    #+#              #
#    Updated: 2021/10/11 21:06:39 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/push_swap.c srcs/operation/utils/moves_utils.c \
srcs/operation/moves.c srcs/operation/moves_2.c srcs/parsing/parsing.c \
srcs/algo/utils/algo_utils.c srcs/algo/algo.c srcs/algo/utils/sort_utils.c \
srcs/algo/algo_2.c

LIBFTPATH	= include/libft 
LIBOBJ		= include/libft/libft.a
@OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
NAME		= push_swap

all: $(NAME)


$(NAME): $(@OBJS)
	@echo "\033[33m- Compiling libft..."
	$(MAKE) -C $(LIBFTPATH)
	@echo "\033[32mDone."
	@echo "\033[33m- Compiling push_swap..."
	@gcc ${CFLAGS} -o ${NAME} ${@OBJS} $(LIBOBJ) -lpthread
	@echo "\033[32mDone."
	@echo "\033[31m========================"
	@echo "YOUR PUSH_SWAP IS READY"
	@echo "========================"

clean:
	rm -rf $(@OBJS)
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@rm -f $(NAME)
	cd $(LIBFTPATH) && make fclean

re: fclean all


.PHONY: libft, all, clean, fclean, re
.SILENT:
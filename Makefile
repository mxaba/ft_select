# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mxaba <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/21 09:25:51 by mxaba             #+#    #+#              #
#    Updated: 2018/09/24 07:54:51 by mxaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_select

HEADER	=	select.h

SRCS	=	items.c main.c arrows.c colours.c functions.c \
			print_list.c signals.c terminal.c remove_item.c

FLAGS	=	-Wall -Werror -Wextra -o

LIB		=	-ltermcap

all		:	$(NAME)

$(NAME)	:
			@gcc $(FLAGS) $(NAME) $(SRCS) $(LIB)

clean	:	
			@rm -rf $(NAME)

fclean	:	
			@rm -rf $(NAME)

re		:	fclean all

norm	:
			@norminette $(SRCS) $(HEADER)

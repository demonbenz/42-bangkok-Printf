# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otangkab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 17:30:13 by otangkab          #+#    #+#              #
#    Updated: 2022/09/12 22:33:27 by otangkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# variables

NAME		= libftprintf.a
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror -I
AR		= ar -rcs

INCLUDE		= ./includes
SRC_DIR		= ./srcs/

SRC_FILES	= ft_printf ft_print_format ft_print_address ft_util

SRCS		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		= $(addsuffix .o, $(SRC_FILES))

LIBFT		= libft

# makefile order

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp ./libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)
	ar -t $(NAME)
	@echo "make $(NAME)"

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCS)

clean:
	@rm -f *.o
	@make clean -C $(LIBFT)
	@echo "remove object files"

test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) -c main.c -o main.o
	$(CC) -o test main.o -L. libftprintf.a
	make clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)/libft.a
	@echo "remove $(NAME) file"

re: fclean all

.PHONY: all clean fclean re testmain

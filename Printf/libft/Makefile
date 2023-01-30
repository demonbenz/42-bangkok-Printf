# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otangkab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 17:19:05 by otangkab          #+#    #+#              #
#    Updated: 2022/09/11 17:24:55 by otangkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlen.c ft_bzero.c ft_calloc.c ft_toupper.c ft_strjoin.c ft_itoa.c

OBJS	= $(SRCS:.c=.o)
INCLUDE	= ../includes
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I
NAME	= libft.a

all: $(NAME) 

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "make $(NAME)"

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCS)
	@echo "make object files in libft"

clean:
	@rm -f *.o
	@echo "remove object files in libft"

fclean: clean
	@rm -f $(NAME)
	@echo "remove $(NAME)"

re: fclean all

.PHONY: all clean fclean re

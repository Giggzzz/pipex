# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 17:27:19 by gudias            #+#    #+#              #
#    Updated: 2022/03/11 17:49:06 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCL	= -I incs
RM		= rm -f

SRCSDIR	= srcs
OBJSDIR	= objs

SRCS	= pipex.c error.c utils.c check_args.c

OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CLFAGS) $(INCL) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -r $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

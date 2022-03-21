# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 17:27:19 by gudias            #+#    #+#              #
#    Updated: 2022/03/21 18:38:50 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCL	= -I incs
RM		= rm -f

SRCSDIR	= srcs
OBJSDIR	= objs

SRCS	= pipex.c error.c get_cmd.c exec_cmd.c openfile.c \
		  $(addprefix utils/, ft_println.c ft_split.c ft_strlen.c \
		  						ft_substr.c ft_strncmp.c ft_pathjoin.c)
		  		


OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	mkdir -p $(OBJSDIR) $(OBJSDIR)/utils
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

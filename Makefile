# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 17:27:19 by gudias            #+#    #+#              #
#    Updated: 2022/03/24 18:33:34 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCL	= -I incs
RM		= rm -f

SRCSDIR	= srcs
OBJSDIR	= objs

SRCS	= pipex.c error.c run_cmd.c here_doc.c \
		  $(addprefix utils/, ft_println.c ft_split.c ft_strlen.c \
		  	ft_strchr_nl.c ft_substr.c ft_strncmp.c ft_pathjoin.c \
			openfile.c get_next_line.c)
		  		


OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@echo "$(YELLOW)Compiling $(DEFAULT)$<"
	@mkdir -p $(OBJSDIR) $(OBJSDIR)/utils
	@$(CC) $(CLFAGS) $(INCL) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Creating executable..$(DEFAULT)"
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)--->./$@ is ready$(DEFAULT)"

clean:
	@$(RM) -r $(OBJSDIR)
	@echo "$(RED)!! Object files deleted !!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)!! ./$(NAME) deleted !!$(DEFAULT)"

bonus: re

re: fclean all

.PHONY: all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

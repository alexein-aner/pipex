# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knieve-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 16:23:00 by knieve-l          #+#    #+#              #
#    Updated: 2024/10/15 16:28:23 by knieve-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for pipex project

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strncmp.c ft_substr.c ft_strlen.c pipex.c
OBJS = $(SRCS:.c=.o)

INCLUDES = pipex.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

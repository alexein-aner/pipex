# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knieve-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 16:23:00 by knieve-l          #+#    #+#              #
#    Updated: 2024/10/16 13:51:20 by kamil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for pipex project

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_split.c \
      ft_strjoin.c \
      ft_strlen.c \
      ft_substr.c \
      pipex.c \
      pipex_utils.c \
      ft_strdup.c \
      ft_strlcpy.c \
      ft_strncmp.c

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 12:26:21 by bchabot           #+#    #+#              #
#    Updated: 2022/11/22 15:58:21 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	   parse_data.c \
	   check_errors.c \
	   philo_utils.c \
	   dinner.c \
	   death.c \
	   getset_data.c \
	   threads.c

CC = gcc

CFLAGS = -lpthread -Wall -Wextra -Werror -g

NAME = philo

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "\033[100m\033[1m\033[92mProgram compiled and ready to execute."

clean :
	rm -f $(OBJS)
	@echo "\033[91mObjects cleaned."

fclean : clean
	rm -rf $(NAME)
	@echo "\033[91mObjects and program cleaned."

re : fclean all

.PHONY : all re clean fclean
.SILENT :

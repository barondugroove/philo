# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 12:26:21 by bchabot           #+#    #+#              #
#    Updated: 2022/11/08 18:55:45 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo.c \
	   parse_data.c \
	   check_errors.c \
	   philo_utils.c \
	   print_data.c

CC = clang -pthread

CFLAGS = -g -Wall -Wextra -Werror

NAME = philo

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
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

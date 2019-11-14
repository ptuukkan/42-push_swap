# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 12:36:17 by ptuukkan          #+#    #+#              #
#    Updated: 2019/11/06 09:36:48 by ptuukkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
NAME = push_swap
LIB = libft.a
SRCDIR = srcs
SRCS = exec_and_check.c init_stack.c push_operations.c rotate_operations.c \
		swap_operations.c

OBJDIR = objects
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
INC = includes/

GCC = gcc -Werror -Wextra -Wall -g

all: $(NAME) $(CHECKER)

$(NAME): $(OBJS) objects/push_swap.o libft/$(LIB)
	$(GCC) $(OBJS) objects/push_swap.o -o $(NAME) libft/$(LIB)

$(CHECKER): $(OBJS) objects/checker.o libft/$(LIB)
	$(GCC) $(OBJS) objects/checker.o -o $(CHECKER) libft/$(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)/push_swap.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC) -I libft/$(INC)

libft/$(LIB):
	make -C libft/

clean:
		/bin/rm -f $(OBJS)
		/bin/rm -rf $(OBJDIR)
		make -C libft/ clean

fclean : clean
		/bin/rm -f $(NAME)
		/bin/rm -f $(CHECKER)
		make -C libft/ fclean

re: fclean all

.PHONY: clean fclean all

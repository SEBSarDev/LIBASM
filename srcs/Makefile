# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 16:41:36 by ssar              #+#    #+#              #
#    Updated: 2021/04/15 20:35:42 by ssar             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#obenir les .o en nasm : nasm -f elf64 file.s -o file.o
#puis lier avec les .c : clang main.c file.o -o executable
#si on veut faire un executable a partir d'un .s uniquement : ld file.o -o executable,doit commencer par _start dans ce cas

NAME = libasm.a
NASM = nasm -f elf64
CC = ar r
SRCS = ft_strlen.s \
       ft_strcpy.s \
       ft_strcmp.s \
       ft_write.s \
       ft_read.s \
       ft_strdup.s
OBJS = $(SRCS:.s=.o)
%.o : %.s
	$(NASM) $< -o $@
$(NAME) : $(OBJS)
	$(CC) $(NAME) $(OBJS)
all : $(NAME)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

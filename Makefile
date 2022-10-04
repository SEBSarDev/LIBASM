CC = clang
NAME = test
SRCS = main.c
OBJS = $(SRCS:.c=.o)
$(NAME) : $(OBJS)
	$(MAKE) -C ./srcs
	$(CC) $(OBJS) ./srcs/libasm.a -o $(NAME)
all : $(NAME)
clean :
	$(MAKE) clean -C ./srcs
	rm -rf $(OBJS)
fclean : clean
	$(MAKE) fclean -C ./srcs
	rm -rf $(NAME)
	rm -rf FILE.txt
	rm -rf MON_EXEMPLE.txt
re : fclean all

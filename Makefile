NAME		= philo
CC			= gcc
CFLAGS		=  -Wall -Wextra -Werror 
#-fsanitize=address
RM			= rm -f
SRCS	=	main.c ft_check.c ft_utils.c ft_init.c ft_threads.c
OBJS = $(SRCS:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@ 

all:	$(NAME)

$(NAME):	$(OBJS) 
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS) 

fclean:	clean
		$(RM) $(NAME)
		
re:	fclean all

.PHONY:	all clean fclean re
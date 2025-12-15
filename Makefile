MAKEFLAGS 	+= -s 

SERVER		= server.c utils.c
CLIENT		= client.c utils.c
SERVER_B	= server_bonus.c utils_bonus.c
CLIENT_B	= client_bonus.c utils_bonus.c

OBJS_S		= $(SERVER:.c=.o)
OBJS_C		= $(CLIENT:.c=.o)
OBJS_SB		= $(SERVER_B:.c=.o)
OBJS_CB		= $(CLIENT_B:.c=.o)

RM		= rm -rf
CC		= cc
CFLAGS		= -Wall -Wextra -Werror

PRINTF		= ft_printf/libftprintf.a
LIBFT		= libft/libft.a

NAME		= server client
NAME_C		= client
NAME_S		= server
NAME_B		= server_bonus client_bonus
NAME_CB		= client_bonus
NAME_SB		= server_bonus

GREEN 		= \033[0;32m
RED		= \033[0;31m
YELLOW		= \033[0;33m
PURPLE		= \033[0;35m

all: $(NAME) $(NAME_B)

$(NAME): $(OBJS_S) $(OBJS_C) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER) -o $(NAME_S) $(PRINTF) $(LIBFT) -g
	$(CC) $(CFLAGS) $(CLIENT) -o $(NAME_C) $(PRINTF) $(LIBFT) -g 
	@echo "$(GREEN)@\Compiled non bonus.\@"
	
$(NAME_B): $(OBJS_Sb) $(OBJS_CB) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_B) -o $(NAME_SB) $(PRINTF) $(LIBFT) -g
	$(CC) $(CFLAGS) $(CLIENT_B) -o $(NAME_CB) $(PRINTF) $(LIBFT) -g 
	@echo "$(YELLOW)@\Compiled bonus.\@"
	
$(PRINTF):
	make -C ft_printf

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJS_S) $(OBJS_C) $(OBJS_SB) $(OBJS_CB)
	make clean -C ft_printf
	make clean -C libft
	@echo "$(RED)@\Cleaned all .o files\@"

fclean: clean
	$(RM) $(NAME_S) $(NAME_C) $(NAME_SB) $(NAME_CB)
	make fclean -C ft_printf
	make fclean -C libft
	@echo "$(RED)@\Cleaned all named files\@"
	
re:	fclean all
	@echo "$(PURPLE)@\Remade\@"

.PHONY:	all clean fclean re

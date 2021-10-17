# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 12:31:20 by rnoriko           #+#    #+#              #
#    Updated: 2021/10/17 14:08:34 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER		=	server
NAME_CLIENT		=	client
SRC_SERVER		=	sources/server.c sources/utilities.c
SRC_CLIENT		=	sources/client.c sources/utilities.c
SRC_CLIENT_B	=	sources/client_bonus.c sources/utilities.c
HEADER			=	includes/minitalk.h

CFLAGS +=		-Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJS_SRV 	=	$(SRC_SERVER:.c=.o)
	OBJS_CLIENT	=	$(SRC_CLIENT_B:.c=.o)
else
	OBJS_SRV 	=	$(SRC_SERVER:.c=.o)
	OBJS_CLIENT	=	$(SRC_CLIENT:.c=.o)
endif

all:		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SRV) $(HEADER)
				clang $(CFLAGS) $(OBJS_SRV) -o $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJS_CLIENT) $(HEADER)
				clang $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

				@echo "\033[1m\033[30mServer and Client was created!\033[0m"
	
bonus:
			make WITH_BONUS=1 all

clean:
			rm -f $(OBJS_SRV) $(OBJS_CLIENT)
			rm -f $(OBJS_SRV:.c=.o) $(OBJS_CLIENT:.c=.o)

fclean:		clean
			rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: 		fclean all

.PHONY:		re clean fclean all bonus
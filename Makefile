# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 15:31:02 by gsap              #+#    #+#              #
#    Updated: 2021/07/29 18:41:44 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

CLIENT_BONUS = client_b

SERVER_BONUS = server_b

CC = gcc -Wall -Werror -Wextra

RM = rm -rf

all:
	${CC} client.c client_utils.c -o $(CLIENT)
	${CC} server.c server_utils.c -o $(SERVER)
	make clean

bonus:
	${CC} client_bonus.c client_utils_bonus.c -o $(CLIENT_BONUS)
	${CC} server_bonus.c server_utils_bonus.c -o $(SERVER_BONUS)
	make clean

clean:
	${RM} *.o

fclean: clean
	${RM} $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

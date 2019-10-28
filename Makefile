# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swarner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/06 16:20:04 by swarner           #+#    #+#              #
#    Updated: 2019/10/27 18:58:44 by swarner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = lib
LIBFT_PATH = lib/libft.a
LEM_IN = lem-in

HEADERS = -I includes/
FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = src
OBJ_FOLDER = obj

SRC_NAMES = main.c struct.c validation.c validation_2.c error_exit.c map_validation.c tools.c algorythm.c way_parse.c

LN_SRC = $(addprefix $(SRC_FOLDER)/, $(SRC_NAMES))

OBJ = $(addprefix $(OBJ_FOLDER)/, $(SRC_NAMES:.c=.o))

all: $(LIBFT_PATH) $(LEM_IN)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@
	@echo "Obj -> done"

$(LIBFT_PATH):
	@make -C $(LIBFT)
	@echo "Libft -> done"

$(LEM_IN): $(OBJ)
	@gcc $(OBJ) $(HEADERS) -L. $(LIBFT_PATH) -o $(LEM_IN)
	@echo "Lem-in binary -> done"

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -rf $(OBJ_FOLDER)
	@echo "Obj removed"

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(LEM_IN)
	@echo "Binaries removed"

re: fclean all

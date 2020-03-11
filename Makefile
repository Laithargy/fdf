# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 22:41:51 by mzhu              #+#    #+#              #
#    Updated: 2020/03/07 01:01:41 by mzhu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

SRC_DIR			= ./srcs

OUTPUT_DIR		= build

SRCS			= $(shell find $(SRC_DIR) -type f | grep  "\.c$$")

OBJ				:= $(patsubst $(SRC_DIR)/%.c,$(OUTPUT_DIR)/%.o,$(SRCS))

DEP				:= $(OBJ:.o=.d)

CFLAGS			= -g -I . -Wall -Wextra -Werror


LDFLAGS			= -lmlx -framework OpenGL -framework Appkit -L ./Libft -lft 

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./Libft
		$(MAKE) -C ./minilibx
		$(CC) -o $@ $(LDFLAGS) $^

-include $(DEP)


$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.c ./Makefile
		mkdir -p $(OUTPUT_DIR)
		$(CC) $(CFLAGS) -MMD -c $< -o $@


clean:
		$(RM) -r $(OUTPUT_DIR)
		$(MAKE) -C ./Libft clean


fclean: clean
		$(MAKE) -C ./minilibx clean
		$(MAKE) -C ./Libft fclean
		$(RM) $(NAME)


re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
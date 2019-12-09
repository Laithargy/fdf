# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 22:41:51 by mzhu              #+#    #+#              #
#    Updated: 2019/12/09 23:01:07 by mzhu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			= ./srcs

OUTPUT_DIR		= build

SRCS			= $(shell find . -type f | grep  "\.c$$")

OBJ				:= $(patsubst $(SRC_DIR)/%.c,$(OUTPUT_DIR)/%.o,$(SRCS))

DEP				:= $(OBJ:.o=.d)

CFLAGS			= -I ./includes -Wall -Wextra

NAME			= fdf


all: #$(NAME)
	echo $(OBJ)


$(NAME): $(OBJ)
		$(CC) -o $@ $^

-include $(DEP)


$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.c ./Makefile
		mkdir -p $(OUTPUT_DIR)
		$(CC) $(CFLAGS) -MMD -c $< -o $@


clean:
		$(RM) -r $(OUTPUT_DIR)


fclean:
		$(MAKE) clean
		$(RM) -f $(NAME)


re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
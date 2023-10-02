# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 11:58:01 by abelrodr          #+#    #+#              #
#    Updated: 2023/10/02 14:28:26 by abelrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra
UNAME = $(shell uname)
INC = -I $(INC_DIR) -I $(LIBFT_DIR)/inc
LIBFT = $(LIBFT_DIR)/libft.a
RM = rm -rf

#########################  Sources  ###########################################

SRC_MAIN = $(SRC_DIR)/push_swap/main.c

SRCS_AUX = \
			$(SRC_DIR)/push_swap/operations/push.c \
			$(SRC_DIR)/push_swap/operations/rotate.c \
			$(SRC_DIR)/push_swap/operations/swap.c \
			$(SRC_DIR)/push_swap/operations/reverse_rotate.c \
			$(SRC_DIR)/push_swap/algorithm_utils.c \
			$(SRC_DIR)/push_swap/algorithm.c \
			$(SRC_DIR)/push_swap/parsing.c \
			$(SRC_DIR)/push_swap/move.c \
			$(SRC_DIR)/push_swap/stack.c \
			$(SRC_DIR)/push_swap/utils.c \
			$(SRC_DIR)/push_swap/position.c \

SRCS_BONUS = $(SRC_DIR)/checker/checker.c

OBJ_MAIN = $(SRC_MAIN:$(SRC_DIR)/push_swap/%.c=$(OBJ_DIR)/push_swap/%.o)
OBJS_AUX = $(SRCS_AUX:$(SRC_DIR)/push_swap/%.c=$(OBJ_DIR)/push_swap/%.o)
OBJ_BONUS = $(SRCS_BONUS:$(SRC_DIR)/checker/%.c=$(OBJ_DIR)/checker/%.o)

######################### Directories  #################################

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc
LIBFT_DIR = libft

#########################  Colors  ############################################

R = \033[31;1m
G = \033[32;1m
C = \033[36;1m
B = \033[34;1m
Y = \033[33;1m
W = \033[37;1m
U = \033[4m
END = \033[0m

#########################  Args  ###############################################

all: $(NAME)

bonus: $(BONUS)

show:
				@printf "NAME: $(NAME)\n"
				@printf "CC: $(CC)\n"
				@printf "CFLAGS: $(CFLAGS)\n"
				@printf "SRCS :$(addprefix \n\t, $(notdir $(SRCS)))\n"

clean:
				@$(RM) $(OBJ_DIR)
				@make clean -sC $(LIBFT_DIR)
				@echo "\n$(G)[Cleaned $(C) '$(NAME) objects' $(G)successfully]\n$(END)"

fclean: clean
				@make fclean -sC $(LIBFT_DIR)
				@$(RM) push_swap
				@$(RM) checker
				@echo "$(G)[Removed $(C)'$(NAME)' $(G)successfully]\n$(END)"

re: fclean all

#########################  Tests  ########################################

test5: $(NAME)
	$(eval ARG = $(shell bash -c 'for i in $$(seq 0 49 | sort -R | head -n 5); do echo -n "$$i "; done'))
	./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l


test100: $(NAME)
	$(eval ARG = $(shell bash -c 'for i in $$(seq 0 99 | sort -R | head -n 100); do echo -n "$$i "; done'))
	./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)
	$(eval ARG = $(shell bash -c 'for i in $$(seq 0 499 | sort -R | head -n 500); do echo -n "$$i "; done'))
	./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

#########################  Rules  ########################################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/push_swap
	@mkdir -p $(OBJ_DIR)/checker
	@mkdir -p $(OBJ_DIR)/push_swap/operations
	@echo "$(BLUE)PUSH_SWAP Compiling:$(END) $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS_AUX) $(OBJ_MAIN)
	@make -sC $(LIBFT_DIR)
	@$(CC) $(OBJ_MAIN) $(OBJS_AUX) $(LIBFT) $(CFLAGS) $(INC) -g -o $@
	@echo "\n$(GREEN)[Compiled $(CIAN) $@ $(GREEN)successfully]\n$(END)"

$(BONUS): $(OBJS_AUX) $(OBJ_BONUS)
	@make -sC $(LIBFT_DIR)
	@$(CC) $(OBJ_BONUS) $(OBJS_AUX) $(LIBFT) $(CFLAGS) $(INC) -g -o $@
	@echo "\n$(GREEN)[Compiled $(CIAN) $@ $(GREEN)successfully]\n$(END)"

.PHONY: all bonus show clean fclean re test5 test100 test500
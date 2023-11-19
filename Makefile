# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 16:51:55 by roglopes          #+#    #+#              #
#    Updated: 2023/11/19 13:00:43 by roglopes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol
NAME_B		:= fractol_bonus

SOURCES		:= sources/mandatory/init.c        \
				sources/mandatory/main.c       \
				sources/mandatory/math_utils.c \
				sources/mandatory/render.c     \
				sources/mandatory/utils.c      \

SOURCES_B	:= sources/bonus/init_bonus.c        \
				sources/bonus/main_bonus.c       \
				sources/bonus/math_utils_bonus.c \
				sources/bonus/render_bonus.c     \
				sources/bonus/utils_bonus.c      \

OBJECTS		= ./objects/
OBJECTS_B	= ./objects_b/

HEADERS		:= -I ./includes/mandatory -I $(LIBMLX)/include
HEADERS_B	:= -I ./includes/bonus -I $(LIBMLX)/include

OBJS		:= ${SOURCES:sources/mandatory/%.c=$(OBJECTS)%.o}
OBJS_B		:= ${SOURCES_B:sources/bonus/%.c=$(OBJECTS_B)%.o}

LIBMLX		:= ./.library_mlx/MLX42
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX			= ./.library_mlx/MLX42/build/libmlx42.a

CFLAGS		:= -Wextra -Wall -Werror -g3 -O3
CC			:= cc

COUNT		:= 0
RED			= \033[0;31m
GREEN		= \033[0;32m
MAGENTA		= \033[0;35m
RESET		= \033[0m

all: $(OBJECTS) $(NAME)

$(OBJECTS):
	@mkdir -p $(OBJECTS)

$(MLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4

$(OBJECTS)%.o: ./sources/mandatory/%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf "$(GREEN)Compiling Fractol %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(SOURCES)))))

$(NAME): $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@printf "\n$(MAGENTA)Fractol compiled\n$(RESET)"

bonus: $(OBJECTS_B) $(NAME_B)

$(OBJECTS_B):
	@mkdir -p $(OBJECTS_B)

$(OBJECTS_B)%.o: ./sources/bonus/%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS_B)
	@printf "$(GREEN)Compiling Fractol %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(SOURCES_B)))))

$(NAME_B): $(MLX) $(OBJS_B)
	@$(CC) $(OBJS_B) $(LIBS) $(HEADERS_B) -o $(NAME_B)
	@printf "\n$(MAGENTA)Fractol Bonus compiled\n$(RESET)"

clean:
	@rm -rf $(OBJS) $(OBJS_B)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(OBJECTS) $(OBJECTS_B)
	@printf "$(RED)Deleted objects$(RESET)\n"

fclean: clean
	@rm -rf $(NAME) $(NAME_B)
	@printf "$(RED)Project is deleted$(RESET)\n"

re: fclean all

.PHONY: all, clean, fclean, re, bonus
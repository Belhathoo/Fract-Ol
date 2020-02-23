# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belhatho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 01:00:32 by belhatho          #+#    #+#              #
#    Updated: 2020/01/26 01:00:50 by belhatho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = colors.c fractals_a.c fractals_b.c main.c draw.c
SRCS += window_img.c mouse_key.c
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBRARIES) -L $(LIBFT)

%.o: %.c fractol.h libft/libft.h
	@gcc $(FLAGS) -c $< -o $@

clean:
		@make clean -C libft
		@rm -f $(OBJS)

fclean: clean
	        @make fclean -C libft
			        @rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
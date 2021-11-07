# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2021/11/07 19:39:06 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

SRCS_DIR:= files/srcs/
SRCS := $(wildcard $(SRCS_DIR)*.c)
OBJS := $(SRCS:%.c=%.o)
NAME:= fdf
CC:= gcc
CFLAGS:= -Wall -Werror -Wextra
LM:= -lm
LIBFT_PATH:= files/lib/libft
LIBFT_LIB:= -L$(LIBFT_PATH) $(LIBFT_PATH)/libft.a
MINILIBX:= -Lfiles/lib/minilibx-linux files/lib/minilibx-linux/libmlx.a -lXext -lX11 -lmlx
MINILIBX_MACOS:= -lmlx -framework OpenGL -framework AppKit
RM :=	rm -rvf
GNL:= files/lib/get_next_line/*.c
DEBUG_FLAG:= -g

all:	libft $(NAME) msg

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(GNL) $(OBJS) -o $(NAME) $(MINILIBX_MAC) $(LM) $(LIBFT_LIB)

$(%.o): $(%.c)
		$(CC) -c $^ -o $@
		@echo "Creating objects"

libft:
		make -C $(LIBFT_PATH)

debug: $(OBJS)
	$(CC) $(DEBUG_FLAG) $(LM) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		@echo "Removing objects"
		$(RM) $(OBJS)
fclean:
		make clean
		cd files/lib/libft && $(MAKE) fclean
		$(RM) $(NAME)
msg:

re:
	make fclean all
	@echo "All files has been deleted and recompiled"

.PHONY: clean fclean all re objects debug bonus

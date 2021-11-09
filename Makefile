# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2021/11/09 09:46:38 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

SRCS_DIR:= files/srcs/
BONUS_DIR:= files/srcs_bonus/
SRCS := $(wildcard $(SRCS_DIR)*.c)
SRCS_BONUS := $(wildcard $(BONUS_DIR)*.c)
OBJS := $(SRCS:%.c=%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)
NAME:= fdf
CC:= gcc
CFLAGS:= -Wall -Werror -Wextra
LM:= -lm
LIBFT_PATH:= files/lib/libft
LIBFT_LIB:= -L$(LIBFT_PATH) $(LIBFT_PATH)/libft.a
RM :=	rm -rvf
GNL:= files/lib/get_next_line/*.c
DEBUG_FLAG:= -g
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	MINILIBX:= -lmlx -framework OpenGL -framework AppKit
else
	MINILIBX:= -Lfiles/lib/minilibx-linux files/lib/minilibx-linux/libmlx.a -lXext -lX11 -lmlx
endif

all:	libft $(NAME) msg

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(GNL) $(OBJS) -o $(NAME) $(MINILIBX) $(LM) $(LIBFT_LIB)

bonus: libft $(OBJS_BONUS) msg
	$(CC) $(CFLAGS) $(GNL) $(OBJS_BONUS) -o $(NAME) $(MINILIBX) $(LM) $(LIBFT_LIB)
	
$(%.o): $(%.c)
		$(CC) -c $^ -o $@
		@echo "Creating objects"

libft:
		make -C $(LIBFT_PATH)

debug: $(OBJS)
	$(CC) $(DEBUG_FLAG) $(LM) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		@echo "Removing objects"
		$(RM) $(OBJS) $(OBJS_BONUS)
fclean:
		make clean
		cd files/lib/libft && $(MAKE) fclean
		$(RM) $(NAME)
msg:

re:
	make fclean all
	@echo "All files has been deleted and recompiled"

.PHONY: clean fclean all re objects debug bonus libft msg

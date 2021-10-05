# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2021/10/05 12:51:03 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

SRCS_DIR:=srcs/
#BUILD_DIR:=build/

#SRCS_DIR_BONUS:= files/srcs/bonus/

SRCS := $(wildcard $(SRCS_DIR)*.c)

#SRCS_BONUS :=	$(wildcard $(SRCS_DIR_BONUS)*.c) \

OBJS := $(SRCS:%.c=%.o)
#BUILD_OBJS:= $(BUILD_DIR)*.o
#OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)
NAME:= fdf
CC:= gcc
#CFLAGS:= -Wall -Werror -Wextra
LM:= -lm
LIBFT_PATH:= srcs/lib/libft
LIBFT_LIB:= -L$(LIBFT_PATH) $(LIBFT_PATH)/libft.a
MINILIBX:= -Lsrcs/lib/minilibx-linux srcs/lib/minilibx-linux/libmlx.a -lXext -lX11 -lmlx
RM :=	rm -rvf
DEBUG_FLAG:= -g

all:	libft $(NAME) msg

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MINILIBX) $(LM) $(LIBFT_LIB)

#bonus: $(OBJS_BONUS)
#	$(CC) $(OBJS_BONUS) -o $(NAME) $(CFLAGS)

$(%.o): $(%.c)
		$(CC) -c $^ -o $@
		@echo "Creating objects"

libft:
		make -C $(LIBFT_PATH)

debug: $(OBJS)
	$(CC) $(DEBUG_FLAG) $(LM) $(CFLAGS) $(OBJS) -o $(NAME)

#build:
#		mkdir -pv build
#		mv $(SRCS_DIR)*.o $(BUILD_DIR)

clean:
		@echo "Removing objects"
		$(RM) $(OBJS)
fclean:
		make clean
		$(RM) $(NAME)
msg:

re:
	make fclean all
	@echo "All files has been deleted and recompiled"


.PHONY: clean fclean all re objects debug bonus

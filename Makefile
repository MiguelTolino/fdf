# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2021/10/04 13:45:19 by mmateo-t         ###   ########.fr        #
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
CFLAGS:= -Wall -Werror -Wextra
LM:= -lm
RM :=	rm -rvf
DEBUG_FLAG:= -g

all:	$(NAME) msg

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LM) $(OBJS) -o $(NAME)

#bonus: $(OBJS_BONUS)
#	$(CC) $(OBJS_BONUS) -o $(NAME) $(CFLAGS)

$(%.o): $(%.c)
		$(CC) -c $^ -o $@
		@echo "Creating objects"

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
		$(RM) $(NAME) ./*.txt
msg:

re:
	make fclean all
	@echo "All files has been deleted and recompiled"


.PHONY: clean fclean all re objects debug bonus

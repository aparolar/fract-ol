NAME		=	fract_ol

S			=	src/

O			=	obj/

I			=	inc/

SRCS		=	$(wildcard $S*.c)

OBJS		=	$(SRCS:$S%.c=$O%.o)

LIBFT		=	-L lib/libft -lft

MLIBX		=	-L lib/minilibx_opengl -lmlx -framework OpenGL -framework AppKit
MLIBXL		=	-L lib/minilibx-linux -lmlx_Linux -lX11 -lXext
LIBMATH		=	-lm

CC			=	@gcc #-g3 -fsanitize=address #-O3 #clang

FLAGS		=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		
					git submodule init
					git submodule update
					make -C lib/libft
ifeq ($(shell uname),Linux)
					@make -s -C lib/minilibx-linux 2>/dev/null
					$(CC) $(FLAGS) $(SRCS) $(LIBMATH) $(LIBFT) $(MLIBXL) -o $(NAME)
else
					@make -s -C lib/minilibx_opengl 2>/dev/null
					$(CC) $(FLAGS) $(SRCS) $(LIBMATH) $(LIBFT) $(MLIBX) -o $(NAME)
endif


$O%.o:			$(OBJS)
				$(CC) $(FLAGS) -c $< -o $@

re:				fclean
				@make fclean -C lib/libft
				@make clean	-C lib/minilibx-linux
				@make clean  -C lib/minilibx_opengl
				$(MAKE)

clean:
				rm -rf $O*.o

fclean:			clean		
				rm -rf $(NAME)

test:			re
				./fract_ol 1

fullclean:		fclean
				make fclean -C lib/libft
				make clean -C lib/minilibx-linux

dbg_test:		re

.PHONY:			all re clean fclean

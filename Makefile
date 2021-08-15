NAME		=	fractol

S			=	src/

O			=	obj/

I			=	inc/

SRCS		=	$Smain.c\
				$Scolor.c\
				$Sfinish.c\
				$Sfractal.c\
				$Shook.c\
				$Simage.c\
				$Sutils1.c

OBJS		=	$(SRCS:$S%.c=$O%.o)

LIBFT		=	-L lib/libft -lft
MLIBX		=	-L lib/minilibx_opengl -lmlx -framework OpenGL -framework AppKit
MLIBXL		=	-L lib/minilibx-linux -lmlx_Linux -lX11 -lXext
LIBMATH		=	-lm

CC			=	@gcc

DBGF		=	-g3 -fsanitize=address

FLAGS		=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		
				git submodule init
				git submodule update
				make -s -C lib/libft

ifeq ($(shell uname),Linux)
				@make -s -C lib/minilibx-linux 2>/dev/null
				$(CC) $(FLAGS) $(SRCS) $(LIBMATH) $(LIBFT) $(MLIBXL) -o $(NAME)
else
				@make -s -C lib/minilibx_opengl 2>/dev/null
				$(CC) $(FLAGS) $(SRCS) $(LIBMATH) $(LIBFT) $(MLIBX) -o $(NAME)
endif

$O%.o:			$(OBJS)
				$(CC) $(FLAGS) -c $< -o $@

re:				fullclean
				$(MAKE)

bonus:			re

clean:
				rm -rf $O*.o

fclean:			clean		
				rm -rf $(NAME)

test:			re
				./$(NAME) 1

fullclean:		fclean
				@make fclean -s -C lib/libft 2>/dev/null
				@make clean  -s -C lib/minilibx-linux 2>/dev/null
				@make clean  -s -C lib/minilibx_opengl 2>/dev/null

.PHONY:			all re clean fclean bonus

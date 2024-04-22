NAME	:= fractol
BONUS	:= fractol_bonus
CC		:= gcc
SRCS 	:=	./mandatory/main.c \
			./mandatory/libft.c \
			./mandatory/ft_atod.c \
			./mandatory/check_input.c \
			./mandatory/init.c \
			./mandatory/iterator_function.c \
			./mandatory/iterator_function2.c \
			./mandatory/mlx_functions.c \
			./mandatory/events.c \
			./mandatory/events2.c \
			./mandatory/palette.c \
			./mandatory/is_double_format.c \

SRCS_BONUS 	:=	./bonus/main_bonus.c \
				./bonus/libft_bonus.c \
				./bonus/ft_atod_bonus.c \
				./bonus/check_input_bonus.c \
				./bonus/init_bonus.c \
				./bonus/iterator_function_bonus.c \
				./bonus/iterator_function2_bonus.c \
				./bonus/mlx_functions_bonus.c \
				./bonus/events_bonus.c \
				./bonus/events2_bonus.c \
				./bonus/palette_bonus.c \
				./bonus/is_double_format_bonus.c \

MLX 	:= ./mlx/libmlx.a
CCFLAGS := -O3 -I./mlx -g -Wall -Werror -Wextra
RM		:= rm -rf
OBJS	:= $(SRCS:.c=.o)
OBJS_BONUS	:= $(SRCS_BONUS:.c=.o)

all: $(MLX) $(OBJS)
	@$(CC) $(SRCS) $(MLX) $(CCFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(MLX) $(OBJS_BONUS)
	@$(CC) $(SRCS_BONUS) $(MLX) $(CCFLAGS) -framework OpenGL -framework AppKit -o $(BONUS)

$(MLX):
	@make -C ./mlx

clean:
	@make clean -C ./mlx
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME) $(BONUS)

re:	fclean all

.PHONY : all fclean clean re bonus

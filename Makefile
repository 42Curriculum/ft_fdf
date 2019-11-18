NAME = fdf

F_N = main error_check parser projection events draw_line fancy_error_check edit_file move_pixel save_file
OBJS = $(addprefix objects/, $(addsuffix .o, $(F_N)))
FILES = $(addprefix fdf_srcs/, $(addsuffix .c, $(F_N)))

MLX = mlx
LIB = libft

LIB_LINK = -L $(LIB) -l ft
MLX_LINK = -L $(MLX) -l mlx
FRAMEWORK = -framework OpenGL -framework AppKit

INCL = -I mlx/ -I incl/ -I libft/ -I incl/
FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

objects/%.o : fdf_srcs/%.c
	@/bin/mkdir -p objects
	@gcc $(FLAGS) -c $(INCL) $< -o $@ 

$(NAME) : $(OBJS)
	@echo  Making mlx.. 
	@make -C $(MLX)
	@echo  Making libft.. 
	@make -C $(LIB)
	@echo  Compiling..
	@gcc $(LIB_LINK) $(MLX_LINK) $(FRAMEWORK) $(OBJS) -o $(NAME)
	@echo Done!

clean :
	@/bin/rm -rf objects
	@make -C $(LIB) clean 
	@make -C $(MLX) clean

fclean : clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIB) fclean

re : fclean all
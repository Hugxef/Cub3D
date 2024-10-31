BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m
TOTEM 		= 🦁

FILES = main \
		xu8t \
		xu8t_utils \
		xu8t_utils_2 \
		xu8t_utils_3 \
		rays_utils \
		rays_utils_2 \
		rays_calc \
		xu8t_hooks_move \
		xu8t_hooks_camera \
		parsing \
		parsing_2 \
		parsing_3 \
		parsing_4 \
		parsing_5 \
		ft_isletter \
		ft_substr \
		ft_split \
		ft_atoi \
		ft_ismapping \
		ft_strdup \
		xu8t_strjoin \
		xu8t_collisions \
		xu8t_collisions_2 \
		xu8t_collisions_3 \
		errors

SRCS = $(FILES:%=srcs/%.c)
NAME		= cub3D
OBJS_DIR	= objs/
PROJECT_H	= srcs/xu8t.h
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra -g3
LIBS		= -lmlx -framework OpenGL -framework AppKit gnl/gnl.a
LIBGNL		= make -C gnl

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@$(LIBGNL)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}${TOTEM} [BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED)
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) $(LIBS) # Program
	@printf "\033[2K\r\033[0;32m${TOTEM} [END]\033[0m $(NAME)$(END)\n"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}${TOTEM} [CLEAN]${RST} done$(END)\n"

fclean: clean
	@make fclean -C gnl
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}${TOTEM} [FCLEAN]${RST} done$(END)\n"

re: fclean all

.PHONY:		all clean fclean re

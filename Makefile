# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:53:44 by mgendrot          #+#    #+#              #
#    Updated: 2024/12/15 21:07:41 by mgendrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME        = so_long

INCLUDE     = include

TMP 	   = .tmp/
CC          = cc 
CFLAGS_Dbeug = -fsanitize=address -fsanitize=undefined -g
CFLAGS      = -Wall -Wextra -Werror -g 

RM          = rm -f
MKDIR       = mkdir
CLONE 		= git clone --depth=1

LIBFT_DIR       = $(TMP)libft/
LIBFT_CFLAGS     = -L . -l ft
LIBFT           = libft.a
LIBFT_INC_H       =  include/libft.h
LIBFT_GIT	   	=  https://github.com/maxg56/libft.git

MINILIBX_DIR    = $(TMP)minilibx/
MINILIBX_CFLAGS =  libmlx42.a -ldl -lglfw -pthread -lm
MINILIBX         = libmlx42.a
MINILIBX_INC_H    = include/MLX42/*.h
MINILIBX_INC_H_F  = include/MLX42.h include/MLX42_lnt.h
MINILIBX_GIT    =  https://github.com/kodokaii/MLX42.git

# **************************************************************************** #
#                                   Colors                                     #
# **************************************************************************** #

DEF_COLOR           =   \033[0;39m
GRAY                =   \033[0;90m
RED                 =   \033[0;91m
GREEN               =   \033[0;92m
YELLOW              =   \033[0;93m
BLUE                =   \033[0;94m
MAGENTA	            =   \033[0;95m
CYAN                =   \033[0;96m
WHITE               =   \033[0;97m
BOLD                =   $'\x1b[1m'
END                 =   $'\x1b[0m'
TERM_UP             =   \033[1A
TERM_CLEAR_LINE     =   \033[2K\r

# **************************************************************************** #
#                                   Sources                                    #
# **************************************************************************** #

SRC_DIR         = src/
MAP_DIR         =  $(SRC_DIR)map/
UTILS_DIR       =  $(SRC_DIR)utils/
PRSIG_DIR       =  $(SRC_DIR)parsing/
SRC_FILES       =   main 
SRC_MAP		 	=   check_map render_map choose_tase 
SRC_UTILS		=   utils Erore init init2 usils_list_int \
					sprite_usils unload player
SRC_PRSIG	 	=   parsing parsing_utils parsimg_flag



SRC			    = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES))) \
				  $(addprefix $(MAP_DIR), $(addsuffix .c, $(SRC_MAP))) \
				  $(addprefix $(UTILS_DIR), $(addsuffix .c, $(SRC_UTILS))) \
				  $(addprefix $(PRSIG_DIR), $(addsuffix .c, $(SRC_PRSIG)))

OBJ_DIR         = $(TMP)obj/
OBJ             = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

DEPS            = $(OBJ:.o=.d)

# **************************************************************************** #
#                             progress_update                                  #
# **************************************************************************** #

TOTAL_FILES     := $(words $(OBJ))
COMPILED_COUNT  = 0

define progress_update
    @if [ ! -f .compiled_count ]; then \
        echo 0 > .compiled_count; \
        printf "\n"; \
    fi; \
    COMPILED_COUNT=$$(cat .compiled_count); \
    COMPILED_COUNT=$$((COMPILED_COUNT + 1)); \
    echo $$COMPILED_COUNT > .compiled_count; \
    printf "$(TERM_UP)$(TERM_CLEAR_LINE)$(CYAN)Compilation progress: \
        $$((COMPILED_COUNT * 100 / $(TOTAL_FILES)))%% $(BLUE) ->$(1) $(DEF_COLOR)\n"; \
    if [ $$COMPILED_COUNT -eq $(TOTAL_FILES) ]; then \
        rm -f .compiled_count; \
    fi
endef
# **************************************************************************** #\
#                                   Rules                                      #
# **************************************************************************** #

all: lib $(NAME) 
	@printf "$(GREEN)All targets compiled successfully!$(DEF_COLOR)\n"

# **************************************************************************** #
#                                   libift                                     #
# **************************************************************************** #

cleanlibs:
	@$(MAKE) clean -C $(LIBFT_DIR)	-s
	
fcleanlibs:
	@$(MAKE) fclean -C $(LIBFT_DIR) -s
	@$(RM) $(MINILIBX)
	@$(RM) $(MINILIBX_INC_H_F)
	@$(RM) -fr $(MINILIBX_DIR)
	@$(RM) $(LIBFT)
	@$(RM) $(LIBFT_INC_H)
	@$(RM) -fr $(LIBFT_DIR)

lib : $(LIBFT) $(MINILIBX)

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)/.git" ]; then \
		printf "$(TERM_YELLOW)Cloning third party library \"%s\" in \"%s\"...\n$(DEF_COLOR)" $(LIBFT_GIT) $(LIBFT);\
		git clone $(LIBFT_GIT) $(LIBFT_DIR) ;\
	fi
	@printf "$(MAGENTA)Making archive $(TERM_BLUE)\"%s\"$(MAGENTA)...$(DEF_COLOR)\n" $@
	@$(MAKE) -C $(LIBFT_DIR) -s
	@cp -u $(LIBFT_DIR)/$(LIBFT_INC_H) $(INCLUDE)
	@cp $(LIBFT_DIR)/$(LIBFT) ./ 
	@printf "$(TERM_CLEAR_LINE)$(GREEN)Done copying archive $(BLUE)\"%s\"$(DEF_COLOR) !\n$(TERM_RESET)" $@

$(MINILIBX):
	@if [ ! -d "$(MINILIBX_DIR)/.git" ]; then \
		printf "$(TERM_YELLOW)Cloning third party library \"%s\" in \"%s\"...\n$(DEF_COLOR)" $(MINILIBX_GIT) $(MINILIBX); \
		$(CLONE) $(MINILIBX_GIT) $(MINILIBX_DIR); \
	fi
	@printf "$(MAGENTA)Making archive $(TERM_BLUE)\"%s\"$(MAGENTA)...$(DEF_COLOR)\n" $@
	@cd $(MINILIBX_DIR) && set -e && \
		cmake -B build && \
		cmake --build build -j4
	@cp $(MINILIBX_DIR)/$(MINILIBX_INC_H) $(INCLUDE); 
	@cp .tmp/minilibx/build/$(MINILIBX) ./;
	@printf "$(TERM_CLEAR_LINE)$(GREEN)Done copying archive $(BLUE)\"%s\"$(DEF_COLOR) !\n$(TERM_RESET)" $@

relibft: fcleanlibs lib

# **************************************************************************** #
#                                   Pipex                                      #
# **************************************************************************** #

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_CFLAGS) $(MINILIBX_CFLAGS)  -o $(NAME)
	@printf "$(GREEN)%s compiled!\n$(DEF_COLOR)" $(NAME)

$(OBJ_DIR)%.o: %.c | $(OBJF)
	@mkdir -p $(dir $@)
	$(call progress_update,$(notdir $@))
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

-include $(DEPS)

%.d: %.c
	@$(CC) $(CFLAGS) -MM $< -MF $@

$(OBJF):
	@$(MKDIR) -p $(OBJ_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		$(RM) -r $(OBJ_DIR); \
		printf "$(YELLOW)Removing %d objects from \"%s\" folder.\n$(DEF_COLOR)" $(words $(OBJ)) $(OBJ_DIR);\
	fi
	
fclean: clean
	@if [ -e $(LIBFT) ]; then \
		printf "$(YELLOW)Removing \"%s\"...\n$(DEF_COLOR)" $(LIBFT);\
		$(RM) $(LIBFT);\
	fi
	@if [ -e $(LIBFT_INC_H) ]; then \
		printf "$(YELLOW)Removing \"%s\"...\n$(DEF_COLOR)" $(INC_DIR)/$(LIBFT_INC_H); \
		$(RM) $(LIBFT_INC_H);\
	fi
	@if [ -e $(NAME) ]; then \
		printf "$(YELLOW)Removing \"%s\"...\n$(DEF_COLOR)" $(NAME);\
		$(RM) -r $(NAME);\
	fi

re: fclean all

norminette:
	@norminette $(SRC_DIR) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
	&& bash -c 'echo -e "\033[1;31mNorminette KO!"'						\
	|| bash -c 'echo -e "\033[1;32mNorminette OK!"'


fcleanall: fcleanlibs
	@$(RM) -rf $(TMP)
	@printf "$(RED)All files removed!$(DEF_COLOR)\n"

.PHONY: all clean fclean re norminette  cleanlibs fcleanlibs libft
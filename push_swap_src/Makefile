NAME=Push_swap
CC=gcc
CFLAG=
CFLAG+= -Werror
CFLAG+= -Wextra
CFLAG+= -Wall
SRCNAME=algo_under_ten carve_argv ft_actions ft_algo ft_print ft_sorted main quartile sort_part_i algo_under_five

LIBS= ../dep/libft/libft.a ../dep/libmem/libmem.a ../dep/libvec/libvec.a

CC_LIBS= make -C ../dep/libft/; make -C ../dep/libmem/; make -C ../dep/libvec/;

INC_DIR_LIBS= -I ../dep/libft/inc/ -I ../dep/libmem/inc/ -I ../dep/libvec/inc/

INC_DIR=./inc/

OBJDIR=./obj/
SRCDIR=./src/

SRC= $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCNAME)))

OBJ= $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCNAME)))

INCDIR=./inc/

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@$(CC_LIBS)
	@$(CC) -o $@ $(OBJ) $(LIBS)
	@(echo "[ \033[35m$@\033[00m ]")

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAG) -c $< -o $@ -I $(INC_DIR) $(INC_DIR_LIBS)
	@(echo "\033[32m$@\033[00m")

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJ) $(OBJDIR)
	@(echo "\033[32mcleaned\033[00m")

fclean: clean
	@rm -rf $(NAME)

re: fclean all

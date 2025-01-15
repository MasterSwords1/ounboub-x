CFLAGS = -Wall -Wextra -Werror
SRCS = main.c cmd_exec.c fd_utils.c ft_split.c utils.c paths_utils.c
BSRCS = main_bonus.c cmd_exec_bonus.c fd_utils_bonus.c ft_split_bonus.c \
		utils_bonus.c paths_utils_bonus.c gnl_bonus.c
NAME = pipex
NAME_BONUS = pipex_bonus
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BOBJS) pipex_bonus.h
	$(CC) $(CFLAGS) $(BOBJS) -o $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: clean
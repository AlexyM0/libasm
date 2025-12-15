NAME    := libasm.a
NASM    := nasm
NASMFLAGS := -f elf64
AR      := ar
ARFLAGS := rcs
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
LDFLAGS := -no-pie
RM      := rm -f

ASM_SRC := ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
ASM_OBJ := $(ASM_SRC:.s=.o)

MAIN    := main
MAIN_SRC:= main.c

all: $(NAME) $(MAIN)

$(NAME): $(ASM_OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

$(MAIN): $(MAIN_SRC) $(NAME)
	$(CC) $(CFLAGS) $(MAIN_SRC) -L. -lasm $(LDFLAGS) -o $(MAIN)

clean:
	$(RM) $(ASM_OBJ)

fclean: clean
	$(RM) $(NAME) $(MAIN)

re: fclean all

test: all
	./$(MAIN)

.PHONY: all clean fclean re test

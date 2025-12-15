NAME    := libasm.a
NASM    := nasm
NASMFLAGS := -f elf64
AR      := ar
ARFLAGS := rcs
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
RM      := rm -f

ASM_SRC := ft_strlen.s ft_strcmp.s ft_strcpy.s
ASM_OBJ := $(ASM_SRC:.s=.o)

MAIN    := main
MAIN_SRC:= main.c

all: $(NAME) $(MAIN)

$(NAME): $(ASM_OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

$(MAIN): $(MAIN_SRC) $(NAME)
	$(CC) $(CFLAGS) $(MAIN_SRC) -L. -lasm -o $(MAIN)

clean:
	$(RM) $(ASM_OBJ)

fclean: clean
	$(RM) $(NAME) $(MAIN)

re: fclean all

.PHONY: all clean fclean re

# Binary file
BDR		= ./
BXT 	= .a
BIN		= $(shell basename $(shell pwd))


# Source file
SDR		= ./src
SXT		= .c
SRC 	= $(shell find $(SDR) -name '*$(SXT)')

ODR		= ./obj
OXT		= .o
OBJ 	= $(subst $(SXT),$(OXT), $(subst $(SDR),$(ODR), $(SRC)))

IDR 	= $(SDR)/inc

# Compiler
CC 		= gcc
CCFLAGS	= -g3 -Wall -Wextra -Werror -I $(IDR)

LD		= ar rcs
LDFLAGS	= 

MSG:
	@echo "[#]$(BIN)$(BXT)"

$(BIN):	MSG $(OBJ)
	@$(LD) $(LDFLAGS) $(BDR)$@$(BXT) $(OBJ)
	@echo " └─ [✓] $@$(BXT)"

$(ODR)/%.o: $(SDR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CCFLAGS) -o $@ -c $<
	@echo " ├─ [✓] $<"

all: $(BIN)

clean:
	@rm -Rf $(ODR)

purge: clean
	@rm -f $(NAME)

re:	purge all

.PHONY: all clean fclean re
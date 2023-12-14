#########################################
## PROJECT      : C LIBRARIES - OCL    ##
## DATE         : 2023                 ##
## ENVIRONEMENT : Unix                 ##
## AUTHOR       : ORNSOLOT             ##
#########################################

##################
## Project Tree ##
##################

## Binary file(s)
#################
BDR	= ..
BXT = .a
BIN	= lib$(shell basename $(shell pwd))

# Source file(s)
################
SDR		= src
SXT		= .c
SRC 	= $(shell find $(SDR) -name '*$(SXT)' ! -path '*/lib/*')

ODR		= obj
OXT		= .o
OBJ 	= $(subst $(SXT),$(OXT), $(subst $(SDR),$(ODR),$(SRC)))

## Dependencies file(s)
#######################
IDR 	= $(SDR)/inc

## Compiler
CC 		= gcc
CCFLAGS	= -g3 -Wall -Wextra -Werror -I $(IDR)

## Linker
LK		= ar
LKFLAGS	= rcso

#######################
## MAKEFILE VARIABLE ##
#######################
MAKEFLAGS	= --no-print-directory
LEFT		= $(LIFELINE)" │ "
NODE		= $(LIFELINE)" ├── [✓]"
TAIL		= $(LIFELINE)" └── [✓]"

####################
## Makefile Rules ##
####################
.PHONY: re all clean $(BIN)

## General rules
################
re:	clean all

all: $(BIN)

clean:
	@rm -Rf $(ODR)
	@rm -f $(BDR)/$(BIN)$(BXT)

vanity:
	@echo "$(LEFT)"
	@echo "$(LEFT)\t ██████╗  ██████╗██╗"
	@echo "$(LEFT)\t██╔═══██╗██╔════╝██║"
	@echo "$(LEFT)\t██║   ██║██║     ██║"
	@echo "$(LEFT)\t██║   ██║██║     ██║"
	@echo "$(LEFT)\t╚██████╔╝╚██████╗███████╗"
	@echo "$(LEFT)\t ╚═════╝  ╚═════╝╚══════╝"
	@echo "$(LEFT)"

## procedural Rules
###################
$(ODR)/%.o: $(SDR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CCFLAGS) -o $@ -c $<
	@echo "$(NODE) $<"

$(BIN): vanity $(OBJ)
	@$(LK) $(LKFLAGS) $(BDR)/$@$(BXT) $(OBJ)
	@echo "$(TAIL) $(BDR)/$@$(BXT)"
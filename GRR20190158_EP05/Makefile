#!/bin/bash

# Arquivo alvo
TARGET1 = retangulos 
TARGET2 = montecarlo

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -O3 -mavx -march=native
RFLAGS = -lm

# Diretórios
INC_DIR	= include
SRC_DIR = src
OBJ_DIR = obj

# Lista de arquivos
SRCS = $(wildcard $(SRC_DIR)/*.c)
COMMON = $(OBJ_DIR)/utils.o $(OBJ_DIR)/metodos.o 

# Alvo principal
all: DIR $(TARGET1) $(TARGET2)

# Criação do diretório
DIR:
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir $(OBJ_DIR); \
	fi

# Regra para compilar o programa principal
$(TARGET1): $(COMMON) $(OBJ_DIR)/retangulos.o
	$(CC) $(CFLAGS) $^ -o $@ $(RFLAGS)

$(TARGET2): $(COMMON) $(OBJ_DIR)/montecarlo.o
	$(CC) $(CFLAGS) $^ -o $@ $(RFLAGS)

# Regra para compilar arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos temporários
clean:
	@echo "Limpando Arquivos..."
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
	fi

# Limpa arquivos temporários e o programa
purge: clean
	@rm -f $(TARGET1) $(TARGET2)

# Garante que regras não sejam confundidas com arquivos de mesmo nome
.PHONY: all clean purge
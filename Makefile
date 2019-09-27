CC		:= g++
C_FLAGS := -std=c++17

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= guarda.exe
else
EXECUTABLE	:= guarda
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	$(CC) $(C_FLAGS) -I $(INCLUDE) -L $(LIB) $^ -o $@ $(LIBRARIES) -fopenmp -lcrypto -lboost_iostreams
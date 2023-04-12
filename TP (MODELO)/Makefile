# Makefile para qualquer pasta TP

CC = g++
CXXFLAGS = -std=c++11 -g -Wall

OUT_FILE = run.out

INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

MAIN = Main
TARGET = run.out
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)$(OUT_FILE)

run:
	

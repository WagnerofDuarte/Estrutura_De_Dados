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

#colocar o pg
timer: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)$(OUT_FILE)

run:
	$(BIN_FOLDER)$(OUT_FILE) f i 5
	$(BIN_FOLDER)$(OUT_FILE) f r 5
	$(BIN_FOLDER)$(OUT_FILE) s i 5
	$(BIN_FOLDER)$(OUT_FILE) s r 5
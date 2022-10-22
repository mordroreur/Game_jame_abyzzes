CC=g++

LDFLAG=$(shell sdl2-config --libs) -lSDL2_ttf -lpthread -lSDL2_image
CFLAG=$(shell sdl2-config --cflags) -Wall -Wextra -g -std=c++17
EXEC=app
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all:$(EXEC)

$(EXEC):$(OBJ)
	$(CC) -o $@ $^ $(LDFLAG)

%.o:%.cpp
	$(CC) $< -c -o $@ $(CFLAG)

.PHONY:clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	rm -rf compile_commands.json
	rm -rf .clangd

clangd: clean
	bear make

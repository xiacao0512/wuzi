FILES = ./source/chessboard.cpp ./source/console.cpp ./source/main.cpp ./source/ui.cpp ./source/wuzi.cpp ./source/scene.cpp ./source/input.cpp ./source/misc.cpp ./source/menu.cpp ./source/win.cpp ./source/combat.cpp	
BIN_FILE = wuzi.exe

default:
	make $(BIN_FILE)

$(BIN_FILE): $(FILES)
	g++ -O3 -Wall -Wextra -static $(FILES) -o $(BIN_FILE)

clean: $(BIN_FILE) Makefile
	del $(BIN_FILE)

CC = g++
TARGET = tetris
SOURCES = Pane.cpp \
        BoardPane.cpp \
        HelpPane.cpp \
        InfoPane.cpp \
        NextPane.cpp \
        StatPane.cpp \
        Tetris.cpp \
				Block.cpp \
				main.cpp

LDFLAGS = -lncurses

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -rf *.o $(TARGET)

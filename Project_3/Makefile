CC=g++
CFLAGS = -o
OBJS = maze_practice.o grid.o
TARGET = maze.out

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $@ $(OBJS)

maze_practice.o: grid.h maze_practice.cpp
grid.o: grid.h grid.cpp


clean:
	rm *.o $(TARGET)

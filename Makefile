CC = g++
CFLAGS = -o StoreProject_CSC455_Group09-master
INCLUDE = -IInclude
SOURCE = `find ./Source -name *.cpp ! -name MainMenu.cpp`
run:
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) Source/MainMenu.cpp
	./StoreProject_CSC455_Group09-master
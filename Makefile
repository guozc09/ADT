vpath %.h include
CC = gcc
CXX = g++
CFLAGS += -I./include
CXXFLAGS += -I./include

objects = src/main.o src/arithmometer.o src/linkList.o src/queen_adt.o src/rabbit_numbers.o

edit : $(objects)
	$(CXX) -o edit $(objects)
src/main.o : linkList.h
src/arithmometer.o : arithmometer.h
src/linkList.o : linkList.h
src/rabbit_numbers.o : rabbit_numbers.h

.PHONY : clean
clean :
	-rm edit $(objects)
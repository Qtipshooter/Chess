#Makefile
#Quinton Graham
#used for testing the chess game functions

#compiler used
CC = g++

#include directory
INCLUDE = -I./include

#source files
#GNU Make
#SRCS = $(wildcard *.cpp) $(wildcard src/*.cpp)
#Windows non-GNU make
SRCS := system()



#full flags
FLAGS = $(INCLUDE)

all: 
	echo $(INCLUDE)
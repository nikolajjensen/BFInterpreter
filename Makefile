# This Makefile was inspired by the gist from GitHub produced by user 'wenchy'.
# (22/10/2022) https://gist.github.com/wenchy/64db1636845a3da0c4c7

CC := g++
CFLAGS := -Wall -std=c++11
TARGET := BFInterpreter

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)

all: 
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -rf $(TARGET)
	
.PHONY: all clean
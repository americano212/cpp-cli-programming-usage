# Makefile for compiling exls.cpp using Curses library

CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lncurses

SRC = exls.cpp
OUTPUT = exls

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(OUTPUT)

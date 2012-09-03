CXX?=gcc
CXXFLAGS=-Wall
# -Wall: turn on almost all warnings
# -c: compile only. Produces .o (object) files. No linking
# -o: name the output file
# $^: variable representing the full list of the dependencies in the target
#      in which it is mentioned
# $@: variable representing the name of the target in which it is mentioned

all: main

main: main.c
	$(CXX) $(CXXFLAGS) $^ -o $@
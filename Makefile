###
### @file - Makefile
### @author - Kevin hillkev <hillkev@oregonstate.edu>
### @description - Makefile for Project 2, compiles files that have been changed
### with command 'make' and cleans object files with command 'make clean'.

#
# Valgrind Options
#
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

project2: main.o inputValidateMenu.o menu.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o
	g++ main.o inputValidateMenu.o menu.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o -o project2

main.o: main.cpp
	g++ -c main.cpp

inputValidateMenu.o: inputValidateMenu.cpp inputValidateMenu.hpp
	g++ -c inputValidateMenu.cpp

Zoo.o: Zoo.cpp Zoo.hpp
	g++ -c Zoo.cpp

Animal.o: Animal.cpp Animal.hpp
	g++ -c Animal.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -c Tiger.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -c Penguin.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -c Turtle.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

zip:
	zip Project2_Hill_Kevin.zip menu.cpp inputValidateMenu.cpp Turtle.cpp Turtle.hpp Penguin.cpp Penguin.hpp Tiger.cpp Tiger.hpp Animal.cpp Animal.hpp Zoo.cpp Zoo.hpp menu.hpp inputValidateMenu.hpp main.cpp Makefile

valgrind:
	valgrind $(VOPT) ./project2

clean: $(CLEAN)
	rm -f project2

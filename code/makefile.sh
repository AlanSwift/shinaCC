flex compiler.l
yacc -vdty compiler.y
g++ -std=c++11 -Wshadow -Wall -o scc *.c *.cpp
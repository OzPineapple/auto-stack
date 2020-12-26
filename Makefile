C = tcc

r: main
	./main

main: main.o State.o util.o
	$C $^ -o $@

Stage.o: State.c State.h
	$C -c $< -o $@

util.o: util.c util.h
	$C -c $< -o $@

clear:
	rm *.o main

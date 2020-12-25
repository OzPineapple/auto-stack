C = tcc

r: main
	./main

main: main.o Auto.o State.o
	$C main.o Auto.o State.o

Auto.o: Auto.h Auto.c
	$C -c Auto.c

State.o: State.h State.c
	$C -c State.c

c:
	rm *.o main

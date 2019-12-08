TARGET: trial

trial: test.o ip.o
	gcc test.o ip.o -o trial -lm

test.o: test.c
	gcc -c test.c -o test.o

ip.o: ip.c
	gcc -c ip.c -o ip.o

clean:
	rm test.o
	rm ip.o
	rm trial

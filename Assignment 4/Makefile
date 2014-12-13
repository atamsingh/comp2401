
output: main.o mhDefs.o
	gcc main.o mhDefs.o -o output

main.o:	main.c
	gcc -c main.c

mhDefs.o: mhDefs.c
	gcc -c mhDefs.c
clean:
	rm *.o

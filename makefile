all: dir.c
	gcc -o things dir.c

clean:
	rm things
	rm *~

run: all
	./things

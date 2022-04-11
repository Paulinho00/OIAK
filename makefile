clean:
	rm bst_c

all:
	gcc -g -O0 -m32 *.s *.h *.c -o bst_c

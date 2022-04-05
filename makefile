clean:
	rm bst_c

all:
	gcc -g -O0 -m32 *.s Bst.c -o bst_c

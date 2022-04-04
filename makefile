clean:
	rm bst_c

all:
	gcc -g -m32 *.s Bst.c -o bst_c

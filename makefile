clean:
	rm bst_c

all:
	gcc -g -O0 -m32 *.s Bst.h BstNode.h BstNodeInt.h Bst.c -o bst_c

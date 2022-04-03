clean:
	rm bst_c

all:
	gcc -g -m32 findPointerToElement.s findParentForElement.s setParentForElement.s constructorINT.s findMinKey.s Bst.c -o bst_c

clean:
	rm bst_c

all:
	gcc -g -O0 -m32 BstNode/*.s BstNodeInt/*.s ConvertingBigNumbers/*.s *.h *.c *.s -o bst_c

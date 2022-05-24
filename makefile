clean:
	rm bst_c

all:
	gcc -g -O0 -m32 BstNode/*.s BstNodeInt/*.s BstNodeInt/*.h BstNodeInt/*.c  ConvertingBigNumbers/*.s ConvertingBigNumbers/*.c  ConvertingBigNumbers/*.h BstNodeRealNumber/*.h  BstNodeRealNumber/*.c  BstNodeRealNumber/*.s *.h *.c *.s -o bst_c -lm
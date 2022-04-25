.text

.global setBit

//(int* byteOfMemory, int indexOfBitToSet)
setBit:
pushl %ebp
movl %esp, %ebp

//Odczyt indeksu ustawianego bitu
movl 12(%ebp), %eax

//Obliczanie wartosci do maski logicznej
pushl %eax
pushl $2
call pow
add $8, %esp

//Odczyt bloku pamięci
movl 8(%ebp), %edx
movl (%edx), %ecx
orl %eax, %ecx
movl %ecx, (%edx)


movl $0, %eax
popl %ebp
ret
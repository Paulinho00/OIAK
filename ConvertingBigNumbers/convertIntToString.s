.data

stringAdress: .space 4
binaryString: .space 4
.text

.global convertIntToString  

// (int* PointerToInt, int bytes)
convertIntToString:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt wskaznika na liczbe
movl 8(%ebp), %ebx

//Odczyt liczby bajtow
movl 12(%ebp), %ecx

pushl %ecx
pushl %ebx
call copyBinaryFromMemoryToStr
popl %ebx
popl %ecx
movl %eax, binaryString

//petla z algorytmem euklidesa


//odwrocenie stringu


end:
popl %ebx
popl %ebp
ret

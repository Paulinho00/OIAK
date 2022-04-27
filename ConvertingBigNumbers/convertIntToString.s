.data

stringAddress: .space 4
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

pushl binaryString
call strlen
add $4, %esp

//Obliczenie liczby potrzebnych bajtow w stringu
pushl %eax
call returnDigitNumber
add $4, %esp

pushl %eax
call malloc
add $4, %eax
movl %eax, stringAddress

//Licznik znakow w decimal String
movl $0, %ebx

//Adres decimal string
movl stringAddress, %ecx

//petla z algorytmem euklidesa
divisionLoop:
pushl %ecx
pushl binaryString
call euclideanDivisionBy10
add $4, %esp
popl %ecx

addl $48, %eax
movl %eax, (%ecx, %ebx)
incl %ebx

pushl %ecx
pushl binaryString
call strlen
add $4, %esp
popl %ecx

movl binaryString, %eax
xor %edx, %edx
movb (%eax), %edx
cmpl $'0', %edx
jne divisionLoop



inverseString:
//odwrocenie stringu


end:
popl %ebx
popl %ebp
ret

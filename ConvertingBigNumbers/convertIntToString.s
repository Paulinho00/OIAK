.bss

stringAdress: .space 4

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

//Obliczenie potrzebnej liczby bajtow
movl %ecx, %eax
movl $3, %esi
mull %esi

decl %ecx

//Zaalokowanie miejsca w pamieci na string z liczba
pushl %ecx
pushl %eax
call malloc
movl %eax, stringAdress
pop %ecx




end:
movl $3, %eax
movl %eax, (%edi, %esi)
mov stringAdress, %eax
popl %ebx
popl %ebp
ret

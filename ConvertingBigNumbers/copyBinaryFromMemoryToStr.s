.text

.global copyBinaryFromMemoryToStr

//(int* pointerToMemoryBlock, int bytes)
copyBinaryFromMemoryToStr:
pushl %ebp
movl %esp, %ebp
pushl %ebx
pushl %esi
pushl %edi

//Odczyt liczby bajtow
movl 12(%ebp), %eax

//Obliczenie liczbe bajtow potrzebnych do przechowania stringu
movl $8, %edx
mull %edx

pushl %eax
call malloc
add $4, %esp
//Adres stringu
movl %eax, %ebx

//Licznik dlugosci stringu
movl $0, %edi

//Ustawienie licznika bitow w bajcie
movl $0, %edx
//Ustawienie licznika bajtow
movl $0, %ecx

//Odczyt adresu na blok pamieci
movl 8(%ebp), %esi
addl %ecx, %esi


copyLoop:
bt %edx, (%esi)
jc add1

add0:
movl $'0', (%ebx, %edi)
incl %edi
jmp endLoop


add1:
movl $'1', (%ebx, %edi)
incl %edi

endLoop:
incl %edx
cmpl $7, %edx
jg nextByte
jmp copyLoop

nextByte:
incl %esi
incl %ecx
movl $0, %edx
cmpl 12(%ebp), %ecx
je remove0FromBeginning
jmp copyLoop

remove0FromBeginning:
movl $0, (%ebx, %edi)
decl %edi
pushl %edi
pushl %ebx
call remove0AtBeginning
add $8, %esp
movl %eax, %ebx

end:

movl %ebx, %eax
pop %edi
pop %esi
pop %ebx
pop %ebp
ret

.data
stringsLength: .long 0

.text

.global compareIntsInMemory
//(int* pointerToOneNumber, int* pointerToSecondNumber, int bytes, int isFirstNumberUnsigned, int isSecondNumberUnsigned)
//Zwraca:
// -1 jeśli druga liczba jest wieksza
//  0 jeśli są równe
//  1 jeśli pierwsza liczba jest wieksza
compareIntsInMemory:
pushl %ebp
mov %esp, %ebp
pushl %ebx
pushl %esi
pushl %edi

//Zamiana pierwszej liczby na string
pushl 16(%ebp)
pushl 8(%ebp)
call copyBinaryFromMemoryToStr
add $8, %esp
movl %eax, %ebx

//Zamiana drugiej liczby na string
pushl 16(%ebp)
pushl 12(%ebp)
call copyBinaryFromMemoryToStr
add $8, %esp
movl %eax, %ecx

//Porownanie znakow liczb
movl 20(%ebp), %edi
movl 24(%ebp), %eax

cmpl %edi, %eax
jg firstNumberIsGreater
jl secondNumberIsGreater

//Porownanie dlugosci stringow
pushl %ecx
pushl %ebx
call strlen
popl %ebx
popl %ecx
movl %eax, %edi

pushl %ecx
call strlen
popl %ecx

movl %eax, stringsLength
cmpl %edi, %eax
jg secondNumberIsGreaterCheckSign
jl firstNumberIsGreaterCheckSign

movl $0, %edi

comparingLoop:
xor %edx, %edx
xor %eax, %eax
//Odczyt cyfry z pierwszej liczby
movb (%ebx, %edi), %edx
//Odczyt cyfry z drugiej liczby
movb (%ecx, %edi), %eax

cmpl %eax, %edx
jl secondNumberIsGreaterCheckSign
jg firstNumberIsGreaterCheckSign

incl %edi
cmpl stringsLength, %edi
jl comparingLoop


areEqual:
movl $0, %eax
jmp end

firstNumberIsGreaterCheckSign:
movl 20(%ebp), %eax
cmpl $0, %eax
je firstNumberIsGreater
jne secondNumberIsGreater

secondNumberIsGreaterCheckSign:
movl 24(%ebp), %eax
cmpl $0, %eax
je secondNumberIsGreater
jne firstNumberIsGreater

firstNumberIsGreater:
movl $1, %eax
jmp end

secondNumberIsGreater:
movl $-1, %eax



end:
pushl %eax
pushl %ebx
pushl %ecx
call free
addl $4, %esp
popl %ebx

pushl %ebx
call free
addl $4, %esp

popl %eax
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
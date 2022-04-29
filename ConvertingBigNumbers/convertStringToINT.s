
.data
counterBits: .long 0
counterBytes: .space 4
binaryStringFromDecimalString: .long 4

.text

.global convertStringToINT

// (string number, int bytes)
convertStringToINT:
pushl %ebp
movl %esp, %ebp
pushl %ebx
pushl %esi
pushl %edi


//Zarezerwowanie odpowiedniej ilosci pamieci
pushl 12(%ebp)
call malloc
addl $4, %esp
movl %eax, %ebx


//Zerowanie zarezerwowanych bajtow
movl $0, %edx
zeroingLoop:
movl $0, (%ebx, %edx)
incl %edx
cmpl counterBytes, %edx
jl zeroingLoop

//Odczyt dlugosci stringa
pushl 8(%ebp)
call strlen
add $4, %esp
movl %eax, %ecx
decl %ecx

movl 12(%ebp), %eax
movl %eax, counterBytes
decl counterBytes

movl $7, counterBits

convertingLoop:
pushl %ecx
pushl 8(%ebp)
call oddsToOne
add $4, %esp
popl %ecx

cmpl $0, %eax
je incrementCounters

add1:
//Obliczenie bloku pamieci do ustawienia
movl counterBytes, %edx
addl %ebx, %edx

//Wywolanie funkcji ustawiajacej odpowiedni bit
pushl %ecx
pushl counterBits
pushl %edx
call setBit
addl $8, %esp
popl %ecx

incrementCounters:
decl counterBits
cmpl $0, counterBits
jge divideBy2

nextByte:
movl $7, counterBits
decl counterBytes

divideBy2:
pushl %ecx
pushl %edx
pushl 8(%ebp)
call divideStringBy2
add $4, %esp
movl 8(%ebp), %ecx
popl %ecx
popl %edx


endLoop:
pushl %eax
pushl %ecx
pushl 8(%ebp)
call strlen
add $4, %esp
popl %ecx
popl %edx

cmpl $1, %eax
jne convertingLoop

pushl %edx
movl 8(%ebp), %edx
xor %eax, %eax
movb (%edx), %eax
popl %edx
cmpl $'0', %eax
jne convertingLoop

end:
movl %ebx, %eax
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
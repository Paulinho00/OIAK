

.data
nextAdditive: .long 0
indexOfLetter: .long 0
len: .long 0

.text

.global divideStringBy2

//(string number)
divideStringBy2:
pushl %ebp
movl %esp, %ebp
pushl %ebx

movl $0, nextAdditive
movl $0, indexOfLetter
movl $0, len

//Odczyt wskaznika na string
movl 8(%ebp), %ecx

pushl %ecx
call strlen
popl %ecx

movl %eax, len

cmpl $1, %eax
jne dividingLoop


cmpl $'0', (%ecx)
jne checkForOnlyOne
je return0

checkForOnlyOne:
cmpl $'1', (%ecx)
jne dividingLoop

return0:
movl $0, %eax
addl $'0', %eax
movl %eax, (%ecx)
jmp end

dividingLoop:
movl indexOfLetter, %edx
movb (%ecx, %edx), %edx
subl $'0', %edx

//Sprawdzenie czy dana cyfra jest parzysta
pushl %ecx
pushl %edx
call checkEvenOddDigit
popl %edx
popl %ecx

pushl %eax
pushl %edx
//Obliczenie nowej cyfry
movl $2, %ebx
movl %edx, %eax
xor %edx, %edx
divl %ebx
addl nextAdditive, %eax
addl $48, %eax

//Zmiana cyfry
movl indexOfLetter, %edx
movb %eax, (%ecx, %edx)

pop %edx
pop %eax

//Obliczenie nastepnego dodatku
movl $5, %edx
mull %edx
movl %eax, nextAdditive

incl indexOfLetter

movl indexOfLetter, %edx
movb (%ecx, %edx), %edx

cmpl $0, %edx
je checkFor0
jmp dividingLoop

checkFor0:
movb (%ecx), %edx
decl len
movl $0, indexOfLetter
cmpl $'0', %edx
je remove0FromBeginning
jmp end

remove0FromBeginning:
movl $0, %edx
movl $1, %eax

removing0Loop:
movb (%ecx, %eax), %ebx
movb %ebx, (%ecx, %edx)

incl %edx
incl %eax
cmpl len, %edx
jg end
jmp removing0Loop



end:
popl %ebx
popl %ebp
ret
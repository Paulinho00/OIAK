.data
remainder: .long 0
length: .long 0
.text

.global euclideanDivisionBy10

//(string number)
euclideanDivisionBy10:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt wskaznika na liczbe
movl 8(%ebp), %ebx

pushl %ebx
call strlen
popl %ebx
movl %eax, length

movl $0, remainder

//Licznik petli
movl $0, %ecx

foreachBit:
movl remainder, %eax

pushl %ebx
movl $2, %ebx
mull %ebx
popl %ebx

//Odczyt bitu
xor %edx, %edx
movb (%ebx, %ecx), %edx

subl $48, %edx
//Obliczenie nowej reszty
addl %edx, %eax
movl %eax, remainder

cmpl $10, remainder
jge add1

add0:
movb $'0', (%ebx, %ecx)
incl %ecx
jmp endLoop

add1:
movb $'1', (%ebx, %ecx)
subl $10, remainder
incl %ecx

endLoop:
cmpl length, %ecx
jl foreachBit 

remove0:
decl %ecx
pushl %ecx
pushl %ebx
call remove0AtBeginning
add $8, %esp

movl remainder, %eax
popl %ebx
pop %ebp
ret


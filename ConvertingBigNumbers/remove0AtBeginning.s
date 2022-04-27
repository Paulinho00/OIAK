.data
newLen: .space 4

.text

.global remove0AtBeginning

//(string number, int len)
remove0AtBeginning:
pushl %ebp
movl %esp, %ebp
pushl %ebx
pushl %esi

//Odczyt wskaznika 
movl 8(%ebp), %edx

//Licznik zer
movl $0, %ecx

//Licznik petli usuwajacej
movl $0, %ebx

cmpl $1, 12(%ebp)
jle endProgram

howMany0:
xor %eax, %eax
movb (%edx, %ecx), %eax
cmpl $'1', %eax
je remove0

incl %ecx
jmp howMany0

remove0:
movl 12(%ebp), %esi
subl %ecx, %esi
movl %esi, newLen

remove0Loop:
pushl %ebx
addl %ecx, %ebx
movb (%edx, %ebx), %eax
popl %ebx
movb %eax, (%edx, %ebx)
cmpl newLen, %ebx
je end

incl %ebx
jmp remove0

end:
incl %ebx
movl $0, (%edx, %ebx)
movl %edx, %eax

endProgram:
pop %esi
pop %ebx
pop %ebp
ret
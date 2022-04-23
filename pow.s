.text

.global pow

pow:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt podstawy
mov 8(%ebp), %ebx
mov %ebx, %eax
//Odczyt wykladnika
mov 12(%ebp), %ecx


cmpl $0, %ecx
je returnOne

cmpl $1, %ecx
je end

//Petla obliczajaca potege
powLoop:
mull %ebx
mov %eax, %ebx
mov 8(%ebp), %eax
decl %ecx
cmpl $1, %ecx
jne powLoop

movl %ebx, %eax
jmp end

returnOne:
movl $1, %eax
jmp end


end:
pop %ebx
pop %ebp
ret
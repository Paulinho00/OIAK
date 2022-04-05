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

//Petla obliczajaca potege
powLoop:
mull %ebx
mov %eax, %ebx
mov 8(%ebp), %eax
decl %ecx
cmpl $1, %ecx
jne powLoop

end:
movl %ebx, %eax
pop %ebx
pop %ebp
ret
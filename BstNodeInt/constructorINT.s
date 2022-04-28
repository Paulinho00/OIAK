.text

.global constructorINT

//(int* pointerToValue, struct BstNodeInt* parent, int* count)
constructorINT:
pushl %ebp
movl %esp, %ebp
pushl %ebx

movl 8(%ebp), %eax
pushl %eax
push $16
call malloc
addl $4, %esp
//Wskaznik na nowy element
movl %eax, %ebx
popl %eax

//Zapisanie klucza nowego elementu
movl %eax, (%ebx)

//Zapisanie wskaznika na rodzica nowego elementu
movl 12(%ebp), %ecx
movl %ecx, 12(%ebx)

//Ustawienie NULL na wskaznikach na dzieci nowego elementu
movl $0, 4(%ebx)
movl $0, 8(%ebx)

//Inkrementacja licznika wezlow
mov 16(%ebp), %ecx
incl (%ecx)

mov %ebx, %eax
pop %ebx
pop %ebp
ret
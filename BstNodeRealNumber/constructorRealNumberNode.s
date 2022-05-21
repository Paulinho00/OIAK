.text

.global constructorRealNumberNode

//(int* pointerToIntValue, int* pointerToFractionalPart, struct BstNodeInt* parent, int* count, int isSigned)
constructorRealNumberNode:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Alokacja pamieci na strukture
pushl $24
call malloc
add $4, %esp
movl %eax, %ebx

//Zapisanie wskaznika na czesc calkowita
movl 8(%ebp), %eax
movl %eax, (%ebx)

//Zapisanie wskaznika na czesc ulamkowa
movl 12(%ebp), %eax
movl %eax, 16(%ebx)

//Ustawienie null na wskazniki na dzieci nowego elementu
movl $0, 4(%ebx)
movl $0, 8(%ebx)

//Zapisanie wskaznika na rodzica
movl 16(%ebp), %eax
movl %eax, 12(%ebx)

//Zapisanie informacji o znaku liczby
movl 24(%ebp), %eax
movl %eax, 20(%ebx)

//Inkrementacja licznika wezlow
movl 20(%ebp), %ecx
incl (%ecx)

movl %ebx, %eax
popl %ebx
popl %ebp
ret




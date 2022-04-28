.text

.global findParentForElement

//(int* pointerToValue, struct BstNodeInt* root, int bytes)
findParentForElement:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Inicjowanie rejestru przechowujacego wskaznik na rodzica
movl 12(%ebp), %ebx

movl 8(%ebp), %edx

//Rejestr z potencjalnym rodzicem
movl $0, %ecx

findParentLoop:
cmpl $0, %ebx
je end

//Przechowanie potencjalnego rodzica nowego elementu
mov %ebx, %ecx

//Wyszukanie nastepnego potencjalnego rodzica
pushl %ecx
pushl 16(%ebp)
pushl (%ebx)
pushl %edx
call compareIntsInMemory
popl %edx
addl $8, %esp
popl %ecx


cmpl $1, %eax
je rightChild
cmpl $-1, %eax
jl leftChild

leftChild:
mov 4(%ebx), %ebx
jmp findParentLoop

rightChild:
mov 8(%ebx), %ebx
jmp findParentLoop


end:
movl %ecx, %eax
pop %ebx
pop %ebp
ret
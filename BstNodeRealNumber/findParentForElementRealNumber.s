.text

.global findParentForElementRealNumber

//(int* pointerToIntValue, int* pointerToFractionalPart, struct BstNodeRealNumber* root, int bytes, int isSigned)
findParentForElementRealNumber:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Inicjowanie rejestru przechowujacego wskaznik na rodzica
movl 16(%ebp), %ebx

//Rejestr z potencjalnym rodzice
movl $0, %ecx

findParentLoop:
cmpl $0, %ebx
je end

//Przechowanie potencjalnego rodzica nowego elementu
movl %ebx, %ecx

//Porownanie czesci calkowitej
pushl %ecx
pushl 20(%ecx)
pushl 24(%ebp)
pushl 20(%ebp)
pushl (%ecx)
pushl 8(%ebp)
call compareIntsInMemory
addl $20, %esp
popl %ecx

cmpl $0, %eax
je checkFractionalPart
cmpl $1, %eax
je rightChild
cmpl $-1, %eax
jl leftChild

//Sprawdzenie czesci ulamkowej
checkFractionalPart:
pushl %ecx
pushl 20(%ecx)
pushl 24(%ebp)
pushl 20(%ebp)
pushl 4(%ecx)
pushl 12(%ebp)
call compareIntsInMemory
addl $20, %esp
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
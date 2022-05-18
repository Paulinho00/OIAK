.text

.global setParentForElementRealNumber

//(int addressOfRoot, int addressOfParent, int addressOfNewElement, int bytes)
setParentForElementRealNumber:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt wyszukanego rodzica nowego elementu
movl 12(%ebp), %ebx
//Odczyt nowego elementu
movl 16(%ebp), %ecx

//Sprawdzenie czy nowy element ma być korzeniem
cmpl $0, %ebx
je newRoot

//Sprawdzenie ktorym dzieckiem bedzie nowy element
//Sprawdzenie czesci calkowitej
pushl %ecx
pushl 20(%ebx)
pushl 20(%ecx)
pushl 20(%ebp)
pushl (%ebx)
pushl (%ecx)
call compareIntsInMemory
add $20, %esp
popl %ecx

cmpl $0, %eax
je checkFractionalPart
cmpl $1, %eax
je rightChild
cmpl $-1, %eax
je leftChild

//Sprawdzenie czesci ulamkowej
checkFractionalPart:
pushl %ecx
pushl 20(%ebx)
pushl 20(%ecx)
pushl 20(%ebp)
pushl 4(%ebx)
pushl 4(%ecx)
call compareIntsInMemory
addl $20, %esp
popl %ecx

cmpl $1, %eax
je rightChild
cmpl $-1, %eax
je leftChild

//Ustawienie elementu jako nowego korzenia
newRoot:
movl 8(%ebp), %eax
movl %ecx, (%eax)
jmp end

//Nowy element lewym dzieckiem
rightChild:
movl %ecx, 12(%ebx)
jmp end

//Nowy element prawym dzieckiem
leftChild:
movl %ecx, 8(%ebx)
jmp end

end:
mov %ecx, %eax
pop %ebx
pop %ebp
ret
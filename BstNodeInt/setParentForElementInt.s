.text

.global setParentForElementInt
//(int addressOfRoot, int addressOfParent, int addressOfNewElement, int bytes, isSigned)
setParentForElementInt:
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
pushl %ecx
pushl 16(%ebx)
pushl 16(%ecx)
pushl 20(%ebp)
pushl (%ebx)
pushl (%ecx)
call compareIntsInMemory
add $20, %esp
popl %ecx


cmpl $1, %eax
je rightChild

cmpl $-1, %eax
je leftChild

//Ustawienie elementu jako nowego korzenia
newRoot:
movl %ecx, (%eax)
jmp end

//Nowy element lewym dzieckiem
rightChild:
movl %ecx, 8(%ebx)
jmp end

//Nowy element prawym dzieckiem
leftChild:
movl %ecx, 4(%ebx)
jmp end

end:
mov %ecx, %eax
pop %ebx
pop %ebp
ret
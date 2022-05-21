.text

.global findPointerToElementRealNumber

//(int* pointerToIntValue, int* pointerToFractionalPart, struct BstNodeInt* root, int bytes, int isSigned, int bytesFractionalPart)
findPointerToElementRealNumber:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt czesci calkowitej
movl 8(%ebp), %ebx
//Odczyt wskaznika na korzen
movl 16(%ebp), %ecx

nextIteration:
//Sprawdzenie czy wskaznik jest nullem/
cmp $0, %ecx
je end

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
je leftChild


//Sprawdzenie czesci ulamkowej
checkFractionalPart:
pushl %ecx
pushl 20(%ecx)
pushl 24(%ebp)
pushl 28(%ebp)
pushl 16(%ecx)
pushl 12(%ebp)
call compareIntsInMemory
addl $20, %esp
popl %ecx

cmpl $0, %eax
je end
cmpl $1, %eax
je rightChild
cmpl $-1, %eax
je leftChild

//Wywolanie kolejnej iteracji petli dla prawego dziecka
rightChild:
mov 8(%ecx), %ecx
jmp nextIteration

//Wywolanie kolejnej iteracji petli dla lewego dziecka
leftChild:
mov 4(%ecx), %ecx
jmp nextIteration


end:
movl %ecx, %eax
popl %ebx
popl %ebp
ret
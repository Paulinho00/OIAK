
.text

.global returnOnlyChild

returnOnlyChild:
pushl %ebp
movl %esp, %ebp

//Sprawdzenie czy jedyne dziecko elementu jest z lewej czy prawej
cmpl $0, 4(%eax)
jne leftChild

rightChild:
mov 8(%eax), %eax
jmp end

leftChild:
mov 4(%eax), %eax
jmp end

end:
pop %ebp
ret



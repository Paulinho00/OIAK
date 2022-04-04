.data
next: .space 4
deleteNode: .space 4
.text

.global findNextElement

findNextElement:
pushl %ebp
movl %esp, %ebp

//Odczyt zmiennej przechowujacej wskaznik na wskaznik na nastepnik
movl %eax, next

//Odczyt zmiennej przechowujacej wskaznik na usuwany element
movl 8(%ebp), %eax
movl %eax, deleteNode

//Sprawdzenie czy usuwany element ma dzieci
cmpl $0, 4(%eax)
je withoutOneChild
cmpl $0, 8(%eax)
je withoutOneChild

//Przypadek gdy usuwany element ma dwoje dzieci
movl deleteNode, %eax
call findSuccessor
jmp end

//Przypadek gdy usuwany element nie ma jednego dziecka
withoutOneChild:
movl next, %ecx
movl %eax, (%ecx)
movl (%ecx), %eax

end:
pop %ebp
ret



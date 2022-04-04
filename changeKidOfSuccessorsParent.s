.data
root: .space 4
child: .space 4
next: .space 4

.text

.global changeKidOfSuccessorsParent

changeKidOfSuccessorsParent:
pushl %ebp
movl %esp, %ebp

//Odczyt wskaznika na wskaznik korzenia
movl 16(%ebp), %eax
movl %eax, root
//Odczyt wskaznika na dziecko nastepnika
movl 12(%ebp), %eax
movl %eax, child
//Odczyt wskaznika na wskaznik na nastepnika
movl 16(%ebp), %eax
movl %eax, next

//Sprawdzenie czy nastepnik ma rodzica
movl next, %eax
movl (%eax), %eax
cmpl $0, 12(%eax)
je changeRoot

//Sprawdzenie ktorym dzieckiem jest nastepnik
movl 12(%eax), %ecx
movl 4(%ecx), %ecx
cmpl %eax, %ecx
je leftChild 

//Zamiana prawego dziecka u rodzica nastepnika na dziecko nastepnika
rightChild:
movl 12(%eax), %ecx
movl child, %eax
movl %eax, 8(%ecx)
jmp end

//Zamiana lewego dziecka u rodzica nastepnika na dziecko nastepnika
leftChild:
movl 12(%eax), %ecx
movl child, %eax
movl %eax, 4(%ecx)
jmp end

changeRoot:
movl root, %eax
movl child, %ecx
movl %ecx, (%eax)

end:
pop %ebp
ret


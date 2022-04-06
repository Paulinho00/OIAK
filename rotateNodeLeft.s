.text

.global rotateNodeLeft

rotateNodeLeft:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt elementu wzgledem ktorego rotujemy
mov 8(%ebp), %eax 

//Sprawdzenie czy element nie jest nullem
cmpl $0, %eax
je elementIsNULL

//Sprawdzenie czy istnieje prawe dziecko elementu
mov 8(%eax), %ecx
cmpl $0, %ecx
je rotationNotPossible

//Rotacja
mov 4(%ecx), %ebx
mov %ebx, 8(%eax)

mov 4(%ecx), %ebx
cmpl $0, %ebx
je parentChange

mov %eax, 12(%ebx)

parentChange:
mov 12(%eax), %ebx
mov %ebx, 12(%ecx)

//Sprawdzenie  czy element jest korzeniem
cmpl $0, %ebx
jne isNotRoot

//Zmiana korzenia
mov 12(%ebp), %ebx
mov  %ecx, (%ebx)
jmp changePointersLeftChildAndElement

isNotRoot:
//Sprawdzenie ktorym dzieckiem jest element wzgledem ktorego rotujemy
mov 12(%eax), %ebx
mov 4(%ebx), %edx
cmpl %edx, %eax
jne rightChild

mov %ecx, 4(%ebx)
jmp changePointersLeftChildAndElement

rightChild:
mov %ecx, 8(%ebx)

changePointersLeftChildAndElement:
mov %eax, 4(%ecx)
mov %ecx, 12(%eax)
mov $0, %eax
jmp end


rotationNotPossible:
mov $-2, %eax
jmp end

elementIsNULL:
mov $-1, %eax

end:
pop %ebx
pop %ebp
ret
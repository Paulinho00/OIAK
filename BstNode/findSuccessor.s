.data
element: .space 4
.text

.global findSuccessor

findSuccessor:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt elementu do wyszukiwania nastepnika
mov %eax, element

cmp $0, 8(%eax)
jne minKey

//Odczyt rodzica elementu
mov 12(%eax), %ebx

//Petla wyszukujaca nastepnika w przypadku braku prawego dziecka elementu 
successorLoop:
cmpl $0, %ebx
je end
cmpl 4(%ebx), %eax
je end

movl %ebx, %eax
movl 12(%ebx), %ebx
jmp successorLoop


minKey:
mov 8(%eax), %eax
call findMinKey
jmp end

end:
pop %ebx
pop %ebp
ret
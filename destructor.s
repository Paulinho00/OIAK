.data
deleteNode: .space 4
next: .space 4
count: .space 4

.text

.global destructor

destructor:
pushl %ebp
movl %esp, %ebp

//Odczyt wskaznika  na usuwany element
movl 8(%ebp), %eax
movl %eax, deleteNode

//Odczyt wskaznika na nastepnik
movl 12(%ebp), %eax
movl %eax, next

//Sprawdzenie czy nastepnik jest tym samym co usuwany element
mov deleteNode, %ecx
cmpl %ecx, %eax
jne notTheSame

//Usuniecie nastepnika
pushl %ecx
call free
addl $4, %esp
jmp end

//Zamian wartosci klucza nastepnika i usuwanego elementu, usuniecie nastepnika
//POTRZEBNA ZMIANA PRZY DZIALANIACH NA LICZBACH WIEKSZYCH NIZ 32 bity
notTheSame:
movl (%eax), %eax
movl %eax, (%ecx)
movl next, %eax
pushl %eax
call free
addl $4, %esp


end:
movl 16(%ebp), %ecx
decl (%ecx)
pop %ebp
ret
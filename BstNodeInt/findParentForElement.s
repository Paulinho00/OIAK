.text

.global findParentForElement

findParentForElement:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Inicjowanie rejestru przechowujacego wskaznik na rodzica
movl 12(%ebp), %ebx

//Rejestr z potencjalnym rodzicem
movl $0, %ecx

findParentLoop:
cmpl $0, %ebx
je end

//Przechowanie potencjalnego rodzica nowego elementu
mov %ebx, %ecx

//Wyszukanie nastepnego potencjalnego rodzica
//POTRZEBA POROWNANIE DUZYCH LICZB
cmpl (%ebx), %eax
jg rightChild
cmpl (%ebx), %eax
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
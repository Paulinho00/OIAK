.text

.global setParentForElement

setParentForElement:
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
//POTRZEBA FUNKCJI POROWNUJACEJ
mov (%ebx), %edx
cmpl (%ecx), %edx
jl rightChild

cmpl (%ecx), %edx
jg leftChild

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
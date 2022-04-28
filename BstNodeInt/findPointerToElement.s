.text

.global findPointerToElement

//(int* pointerToValue, struct BstNodeInt* root, int bytes)
findPointerToElement:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt do szukanej liczby, przechowywanej w pamieci
movl 8(%ebp), %ebx
//Odczyt wskaznika na korzen drzewa
movl 12(%ebp), %ecx

nextIteration:
//Sprawdzenie czy element jest nullem
cmp $0, %ecx
je end

//Sprawdzenie czy klucz wezla jest wartoscia szukana
pushl %ecx
pushl 16(%ebp)
pushl (%ecx)
pushl %ebx
call compareIntsInMemory
popl %ebx
add $8, %esp
popl %ecx

cmp $0, %eax
je end
cmp $1, %eax
jg rightChild
cmp $-1, %eax
jl leftChild

//Wywolanie kolejnej iteracji petli dla lewego dziecka
leftChild:
mov 4(%ecx), %ecx
jmp nextIteration

//Wywolanie kolejnej iteracji petli dla prawego dziecka
rightChild:
mov 8(%ecx), %ecx
jmp nextIteration

end:
mov %ecx, %eax
pop %ebx
pop %ebp
ret
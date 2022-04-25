.text

.global findPointerToElement

findPointerToElement:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt wartosci szukanej
//POTRZEBA DOSTOSOWANIA DO WIELKICH LICZB
movl %eax, %ebx
//Odczyt wskaznika na korzen drzewa
movl 12(%ebp), %ecx

nextIteration:
//Sprwadzenie czy element jest nullem
cmp $0, %ecx
je end

//Sprawdzenie czy klucz wezla jest wartoscia szukana
//POTRZEBA FUNKCJI POROWNUJACEJ DUZE LICZBY
cmp (%ecx), %ebx
je end
cmp (%ecx), %ebx
jg rightChild
cmp (%ecx), %ebx
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
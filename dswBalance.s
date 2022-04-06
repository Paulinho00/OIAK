
.bss
m: .space 4

.text

.global dswBalance

dswBalance:
pushl %ebp
movl %esp, %ebp
pushl %ebx

//Odczyt wskaznika na korzen
mov 8(%ebp), %eax
mov (%eax), %eax

//Petla prostujaca drzewo
straighteningLoop:
cmpl $0, %eax
je endOfStraighteningLoop

mov 4(%eax), %ecx
cmpl $0, %ecx
jne makeRightRotation

mov 8(%eax), %eax
jmp straighteningLoop

makeRightRotation:
pushl %eax
pushl %ecx
pushl 8(%ebp)
pushl %eax
call rotateNodeRight
addl $8, %esp
pop %ecx
pop %eax
mov 12(%eax), %eax
jmp straighteningLoop


endOfStraighteningLoop:
//Obliczanie maksymalnej wysokosci zbalansowanego drzewa
mov 12(%ebp), %eax
incl %eax
pushl %eax
call binaryLogarithm
addl $4, %esp

//Obliczanie liczby rotacji
pushl %eax
pushl $2
call pow
addl $8, %esp
decl %eax
//Zapis liczby m
mov %eax, m

//Obliczenie liczby iteracji wstepnej petli rownowazacej
mov %eax, %ecx
mov 12(%ebp), %eax
subl %ecx ,%eax

//Odczyt wskaznika na korzen
mov 8(%ebp), %ecx
mov (%ecx), %ecx
mov $0, %edx

initialBalancingLoop:
cmpl %eax, %edx
jge endOfInitialBalancingLoop

//Wykonanie rotacji w lewo
pushl %eax
pushl %edx
pushl 8(%ebp)
pushl %ecx
call rotateNodeLeft
pop %ecx
addl $4, %esp
pop %edx
pop %eax
incl %edx

//Sprawdzenie czy istnieje stryj elementu z rotacji
mov 12(%ecx), %ebx
cmpl $0, %ebx
je initialBalancingLoop

mov 8(%ebx), %ebx
cmpl $0, %ebx
je initialBalancingLoop

//Ustawienie stryja elementu jako nowego elementu do rotacji
mov %ebx, %ecx
jmp initialBalancingLoop

endOfInitialBalancingLoop:
//Odczyt liczby m
mov m, %eax

balancingLoop:
cmpl $1, %eax
jle end

shrl $1, %eax
mov 8(%ebp), %ecx
mov (%ecx), %ecx
mov $0, %edx

innerBalancingLoop:
cmpl %eax, %edx
jge balancingLoop

pushl %eax
pushl %edx
pushl 8(%ebp)
pushl %ecx
call rotateNodeLeft
pop %ecx
addl $4, %esp
pop %edx
pop %eax
incl %edx

//Sprawdzenie czy istnieje stryj elementu z rotacji
mov 12(%ecx), %ebx
cmpl $0, %ebx
je innerBalancingLoop

mov 8(%ebx), %ebx
cmpl $0, %ebx
je innerBalancingLoop

//Ustawienie stryja elementu jako nowego elementu do rotacji
mov %ebx, %ecx
jmp innerBalancingLoop

end:
pop %ebx
pop %ebp
ret
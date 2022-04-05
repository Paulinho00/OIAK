.text

.global binaryLogarithm

binaryLogarithm:
pushl %ebp
movl %esp, %ebp

//Odczyt liczby logarytmowanej
mov 8(%ebp), %eax

//Sprawdzenie czy liczba logarytmowana > 0
cmpl $0, %eax
jnge incorrectBNumber

//Wartosc logarytmu
mov $-1, %ecx

//Petla obliczajaca algorytm
calculatingLog:
cmpl $0, %eax
je setReturnValue
incl %ecx
shrl $1, %eax
jmp calculatingLog

incorrectBNumber:
mov $-1, %eax

end:
pop %ebp
ret

setReturnValue:
mov %ecx, %eax
jmp end


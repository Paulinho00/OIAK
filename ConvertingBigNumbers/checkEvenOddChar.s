.text

.global checkEvenOddDigit

//(int number)
checkEvenOddDigit:
pushl %ebp
mov %esp, %ebp

movl 8(%ebp), %eax

//Sprawdzenie czy ostatnia cyfra jest podzielna przez 2
cmpl $1, %eax
je odd
cmpl $3, %eax
je odd
cmpl $5, %eax
je odd
cmpl $7, %eax
je odd
cmpl $9, %eax
je odd
jmp even


odd:
movl $1, %eax
jmp end

even:
movl $0, %eax

end:
pop %ebp
ret
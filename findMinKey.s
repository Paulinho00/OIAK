.text

.global findMinKey

findMinKey:
pushl %ebp
movl %esp, %ebp

//Sprawdzenie czy element ma lewe dziecko
searchLoop:
cmpl $0, 4(%eax)
je end

mov 4(%eax), %eax
jmp searchLoop

end:
pop %ebp
ret





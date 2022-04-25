.text

.global oddsToOne

//(string number)
oddsToOne:
pushl %ebp
movl %esp, %ebp

//Odczyt dlugosci stringa
pushl 8(%ebp)
call strlen
add $4, %esp
decl %eax

//Odczyt ostatniej cyfry w stringu
movl 8(%ebp), %ecx
movl (%ecx, %eax), %eax

//Sprawdzenie czy ostatnia cyfra jest podzielna przez 2
cmpl $'1', %eax
je odd
cmpl $'3', %eax
je odd
cmpl $'5', %eax
je odd
cmpl $'7', %eax
je odd
cmpl $'9', %eax
je odd
jmp even


odd:
movl $1, %eax
jmp end

even:
movl $0, %eax

end:
popl %ebp
ret
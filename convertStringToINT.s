.data
counter: .long 0

.text

.global convertStringToINT

// (string number, int bytes)
convertStringToINT:
pushl %ebp
movl %esp, %ebp
pushl %ebx
pushl %esi
pushl %edi

//Zarezerwowanie odpowiedniej ilosci pamieci
pushl 12(%ebp)
call malloc
addl $4, %esp
movl %eax, %ebx

//Odczyt dlugosci stringa
pushl 8(%ebp)
call strlen
add $4, %esp
movl %eax, %ecx
decl %ecx

//Licznik zapisanych bajtów
movl $0, %edx

movl $0, %esi

movl 8(%ebp), %edi

convertingLoop:
xor %eax, %eax
movb (%edi, %ecx), %al
cmpb $'0', %al
jl badInput
cmpb $'9', %al
jg badInput

subl $48, %eax

pushl %eax
pushl %ecx
pushl %edx
pushl counter
pushl $10
call pow
add $8, %esp
popl %edx
popl %ecx

pushl %edx
mull 4(%esp)
popl %edx

pushl %esi
addl %eax, %esi

cmpl $127, %esi
je saveDigits
jg overflow
jl iteration

overflow:
movl (%esp), %esi
movl %esi, (%ebx, %edx)
addl $4, %edx
movl 4(%esp), %esi
movl $0, counter
addl $4, %esp
jmp iteration

saveDigits:
movl %esi, (%ebx, %edx)
movl $-1, counter
addl $4, %edx
movl $0, %esi
jmp iteration

iteration:
addl $4, %esp
decl %ecx
incl counter
cmpl $0, %ecx
jge convertingLoop
jl saveLastDigits

badInput:
movl $-1, %eax
jmp end

saveLastDigits:
cmpl $0, %esi
je returnAddress
movl %esi, (%ebx, %edx)

returnAddress:
movl %ebx, %eax

end:
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
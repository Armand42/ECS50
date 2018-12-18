/*
NEW CHAPTER
stack register
container for a sequential collection of data
LIFO

stack pointer initialized to the top of the stack
push something onto stack - CUSP subtracts 1 from the stack
pointer and puts that something at the address in the stack pointer
(the new top of stack)

when we pop, the value at the top of the stack is stored where
indicated and 1 is added to the stack pointer

psha    push acc onto the stack at stack pointer
pshx    push index register onto stack at stack pointer
popa    pop from stack into acc
popx    pop from index register into acc
lds $nnn load stack pointer direct (from addr $nnn)
lds# $nnn   load stack pointer immediate (with value $nnn)
sts $nnn store stack pointer direct (to addr $nnn)



calling a subroutine

jsr $nnn

returning from a subroutine

rtn

*/
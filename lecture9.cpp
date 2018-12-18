/*
jsr - pushes program counter onto the stack
rtn- takes program counter and puts it in the program counter
and increments to the next instruction

parameter passing - dont do it

pass parameters on the stack instead of through shared variables

-The frame is a conceptual convenience that allows us to give names
to the values on the stack.
-To get at the different values on the stack by using names, we create
names for the values using the .equ directive.
-We use the frame pointer (a 12-bit register that holds a memory
address) to indicate the beginning of the frame of the stack.

Frame Instructions

ldf nnn     load frame pointer
stf nnn     store frame pointer
adf nnn     add frame pointer
sbf nnn     subtract frame pointer
cmf nnn     compare frame pointer
tsf         transfer stack pointer to frame pointer
tfs         push frame pointer to stack pointer

make sure to put space in between !

Subroutines and Parameters

Frame pointer starts at zero and when finished it ends at zero

$older  <-  sp              this is the frame
return addr
4
3

eventually stack pointer and frame pointer point to same address
in the stack

*/
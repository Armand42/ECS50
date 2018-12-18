/*
negate and add 1 for negative numbers
can also write  .word -3 for negative input
      
An assembler creates object code by translating combinations of mnemonics and syntax for operations and addressing
modes into their numerical equivalents.

Multiple assemblers can feed into the same CPU

Pass 1: create symbol table and generate addresses for instructions
Pass 2: substitute corresponding symbols with values from symbol table

The ASIDE assembler ignores everything past a ;


.equ max_int, 5     .equ is used to assign variables to constants, goes at the top of the program

Starting Addresses:
ASIDE starts assembly at locations $000 in memory. We might need to use $000 for other things.

.equ @ address  tells ASIDE that we want our program to begin at a specific address



*/

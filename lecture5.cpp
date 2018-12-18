/*
midterm chapters 1-4
open notes to midterm
7-9 review session wednesday in Bainer 1132

Indexed Addressing - Arrays in Cusp

int foo[5];
foo[2] = 75;

index register (XR) is a 12-bit register to be used as an index variable which is added to 
some memory addres, giving a new address offset from the original

no greater than flag needed because of the less than and equal to sign

index register instrux
No multiplication or division operators for the index register

index register only 12 bits long - theres only 4096 words of memory that can be represented as 12 bits



Array example 1:

    .equ arraySize 4        - array with 4 elemtents
    lda#    0               - initialize accumulator with 0
    ldx#    0               - initialize index register with 0
    loop:   cmx     max             - compare index register to maximum index
    jgt     end             - end of the loop
    ada+    ones            - increment to next index in array by 1
    adx#    1               - add ones to index register
    jmp     loop

    


    end:    sta result
            hlt
    ones:   .blkw    arraySize, 1             - array full of ones, sets aside a block of 4 words with ones in them
    max:    .word arraySize - 1               - definition of max value
    result: .word   



*/
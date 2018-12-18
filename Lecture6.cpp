/*
3) page 42 It doesnt. Theres no separation between data and instructions.
Its just 24 bits

How to get valid instructions into instruction register?
create valid instructions and execute them

4) 2 more bits
1 word has 3 bytes and you want to select from 3 different things the minimum number
of bits to represent 3 is 2 bits

can represent 64 things with 6 bits

            2 bits byte address                                pretend this address points to other thing
[    opcode| | address mode       |    memory address         ]
    8 bits      4 bits                      12 bits

00
01
10
11  never use 11 cuz you already use the 3 in new memory
you steal 2 bits


[     |     |      ]





5) You should not have negative addresses. 2s complement is for easy addition/subtraction
you can just use unsigned arithmetic for the program counter



Two-dimensional array
Its one dimension in cusp

row major ordering for a 2D array with row and column indexes starting at 0
index = row index * number of columns in a row + column index
2*3+1 = address 7






*/
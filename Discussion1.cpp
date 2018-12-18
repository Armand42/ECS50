/*
Cusp -> 24 bits

    8                 4                   12
 opcode        addressing mode     address or value

lda 001 -> Direct
lda# 001 -> Immediate

AND 001      A AND 001
OR  010      A OR 010
X0R 000      A XOR 000

-------------------------
Remainder loop
LDA# 16
Loop: MOD  2
JNE  005    jump not equal to zero; JEQ jump if equal to zero
STA  006
HLT
JMP  001

--------------------------
LDA#  001   -load value into accumulator
STA  001   -storing value in accumulator into address 001

---------------------------
Data Transfer Instructions

LDA
STA
PSH     pushing into stack pointer      SP
POP     popping out of stack            Mem[operand]
CLR
SET
TAX     ACC = XR
TXA
TSA
TFA

-------------------------------
A = A + value in address
ADA 005 + 002 = 007
                <-25 goes into the accumulator

----------------------------------
ADA add to the acc
ADX add with index register
SBA subtract with acc
MUL multiply with acc
DIV divide what is in the acc by the operand
INC +1 
DEC -1
NEG A becomes -A

CMA compare with acc with operand: equal to or less than
CMX 
AND
OR
XOR
COM complement 
SHRA shift right with the acc by 1 bit: lose LSB
SHLA shift left with the acc by 1 bit: lose MSB
RTRA rotate the element right
RTLA rotate the element left

JMP jump to address
JEQ jump if equal to zero
JNE jump if not equal to zero
JLT jump if less than
JGE jump if greater than
JLE jump if less than or equal to
JGT jump if greater than or equal to
JOV jump if overflow
JNO jump if no overflow


*/
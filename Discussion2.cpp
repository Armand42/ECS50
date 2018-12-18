/*

Index Register - XR
- 12 bits 
- unsigned Numbers
- +
Array

- - - - -
1 2 3 4 5

A[2]

A-> 0   $100
    1   $101
    2   $102         A + 2
    3   $103
    4   $104                A + 4
    5   $105

XR
[ 2 ]    ->offset

LDA+ A
LDA+ $100
A:= Mem[XR + A]
  = Mem[2 + $100]
  = Mem[$102]


LDX xxx         XR = Mem[xxx]
LDX#            XR = xxx
STX             Mem[xxx] = XR
ADX xxx         XR = XR + Mem[xxx]  
ADX#            XR = XR + xxx
SBX 
SBX#
CMX xxx
CMX#
EQ              = XR ? Mem[xxx] => XR = Mem[xxx]
LT              := XR < Mem[xxx]
TAX             XR = ACC   
TXA             ACC = XR
                A => 24 bits
                XR => 12 bits
                lose 12 MSB


Special looping instructions
-> AOC  xxx 
Add one and compare
XR = XR + 1
XR ? xxx

Example:
AOC $100 -> Adds 1 to address 100 and compares it to whats in 100 
only for the index register

ADX# 1
CMX $100

SOJ xxx
Subtract one and jump if not less than 0
XR = XR - 1
if OV = 0 than jump


SOJ $100
subtract by 1 and jump if overflow flag is not 0
SBX# 1  
JNO $100


Sum of all the elements in an array example:

x -> $100   some register stored in $100                100 elements in array fyi

         LDX#    0   -> index i = 0
         LDA#    0   -> sum = 0
Loop:    ADA+    $100
         ADX#    1    -> increment index register by 1
         CMX#    100
         JLT     Loop

Other version using AOC

         LDX#    0   -> index i = 0
         LDA#    0   -> sum = 0
Loop:    ADA+    $100
         AOC#    100
         JLT     Loop



Other version
         LDX#    99  
         LDA#    0   -> sum = 0
Loop:    ADA+    $100
         SOJ#    Loop           compares with zero so give it an address to jump to
       


Write a program that:

X -> $100 -> 10 elements
Loop -> product of all elements
->AOC
->SOJ
->No special loops


SOJ version
         LDX#    9  i = 9  
         LDA#    1   -> product = 1
Loop:    MUL+    $100   -> A = A * [$100 + XR]
         SOJ#    Loop  


AOC version
         LDX#    0  i = 9  
         LDA#    1   -> product = 1
Loop:    MUL+    $100   -> A = A * [$100 + XR]
         AOC#    10 
         JLT    Loop

No special loops
         LDX#    0  i = 9  
         LDA#    1   -> product = 1
Loop:    MUL+    $100   -> A = A * [$100 + XR]
         ADX#    1
         CMX     10
         JLT     Loop

*/
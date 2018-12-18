/*
Forward Referencing

.equ @, $100
.equ max_int, 5
lda counter
loop: cma n
jgt end     the assembler cant know the value to plug in until it has processed the instruction down there
mul counter
.
.
.
.
end

Location Counter

an instruction       increments the LC by 1
.equ    @,nnn        puts the value in nnn in the LC
.equ symbol,value    does not change the LC








*/
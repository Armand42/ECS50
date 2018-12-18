/*
Cusp
character 7 bits ASCII
stored in 8 bit byte
24 bit word so you get 1 character per 3 bytes per word
leading bit 0 other 7 bits are character

.char
opcodes for strings use the index register
ldc oldString
stc newString



	ldx#	0
loop:	cmx# strlen
	jge  end
	ldc  oldString
	ada#	1
	stc newString
	adx#  1
	jmp	loop
end:	hlt
	.equ @,$010
oldString:	.char 'hi how are you',strlen	       ; not a variable just a symbol so you need immediate addressing
	.equ @,$015
newString:	.blkw 5,0



upper:	cma# 'A'
	jlt next
	cma# 'Z'
	jgt next
	ada# 'a'-'A'
	stc newString
	jmp next
	









	.equ @, $000
	.equ stack, $300
	
	lds# stack
	ldf# 0
	ldx# 0
	psh# $010 ; address of array
	psh# strlen
	psh# $019  ; address of the result
	jsr swapcase
	ads# 3
	hlt

	.equ @, $010
inputString:  .char 'abcdefHIJKLM',strlen
	.equ @, $019
outputString:	.blkw 4, 0 ; there are 25 characters, need 9 blocks



; stack = [input, strlen, output, PC, FP] THIS IS JUST HERE TO REMEMBER THE POSITIONS OF EACH PARAMETER
	.equ @, $100
	.equ in, 4    ; A is position of array in stack
	.equ size, 3
	.equ out, 2
	

swapcase: 	pshf 
	; [$010, strlen, $030, PC, FP]
	tsf 

loop:	cmx ! size ; compare XR with strlen
	jge end
	ldc* ! in   ; load the XR position in inputString 
	; ACC contains the character  'a'
	cma# 'a'
	jlt upper
	cma# 'z'
	jgt next
	sba# 'a'-'A'
	stc* ! out
	jmp next

upper:	cma# 'A'
	jlt next
	cma# 'Z'
	jgt next
	ada# 'a'-'A'
	stc* ! out
	jmp next

next:	adx# 1
	jmp loop

end:	popf ; pop FP    [array, m, n, arrayT, PC]
	rtn   



    input = lEArN pYtHOn iN 30 YeaRS!

    step1: convert all to lowercase


    previous = NULL
    i = 0
    while i < strlen:
        if ((i == 0 or previous == space):
                s[i] to be upper case    
        else if s[i] is uppercase:
            s[i] to be lower case
        previous = s[i]
        i++;



    for(int i = 0; i < strlen-1; i++)
        if i == 0 or input[i-1] ==  space:
            convert input[i+1] to upper if it is the lowercase 










*/
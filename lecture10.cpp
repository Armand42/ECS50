/*
Subroutines and Parameters

; main program
	.equ @, $000
	.equ stack,$040	; make a stack
	lds# stack	; load stack pointer with 40/make sure ends at 40
	ldf# 0	; load frame pointer with 0/make sure ends at 0
	psh main_base	; order does not matter
	psh main_exp	
	jsr power
	ads# 2	; add 2 to stack pointer IMPORTANT
	
	sta answer
	hlt

main_base:	.word 3
main_exp:	.word 4
answer:	.word -1

; power subroutine
	.equ @,$020
	.equ base,3
	.equ exp,2  ; stack = [main_base, main_exp, PC, FP] 

power:	pshf		; push frame pointer onto the stack so we dont lose value of the frame pointer
	; stack = $040
	; FP = 0
	tsf       ; FP = SP
	; FP = $040
	lda# 1  ; ACC = 1
	sta temp  ; temp = 1
	
loop:	lda ! exp    ; ACC = Mem[exp + FP] = main_exp
	cma# 0
	jle end

	lda temp
	mul ! base     ; Mem[base + FP] = main_base
	sta temp

	dec ! exp
	jmp loop

end:	lda temp
	popf		; pop from stack into the frame pointer
	rtn

temp:	.word











	lds# stack	; load stack pointer with 40/make sure ends at 40
	ldf# 0	; load frame pointer with 0/make sure ends at 0
	psh main_base	; SP = SP - 1 and then mem[SP] = main_base
	psh main_exp
	jsr power ; SP = SP-1 and Mem[SP] = PC and PC = power
	ads# 2
	sta temp
	hlt


power:   	pshf   ; SP = [PC, FP]
	tsf
	lda# 1
	sta temp
	popf
	rtn     ; PC = Mem[SP] and set SP = SP + 1

main_base:	.word 3
main_exp:	.word 4
temp: 	.word 0





[1  2 3]
[4 5 6]
[7 8 9]
[10 11 12]

[1 4 7 10]
[2 5 8 11]
[3 6 9 12]

A: 1 2 3 4 5 6 7 8 9 10 11 12
B: 1 4 7 10 2 5 8 11 3 6 9 12

[1 4]
[2 5]
[3 6]

B: 1 4 2 5 3 6

given x, find (i,j) position,
   -> x = 0, A[0] = 1, A[0][0]   (i,j) = (0,0)
   -> x = 1, A[1] = 2, A[0][1]   (i,j) = (0,1)
   -> x = 2, A[2] = 3, A[0][2]   (i,j) = (0,2)
   -> x = 3, A[3] = 4, A[1][0]   (i,j) = (1,0)
   -> x = 4, A[4] = 5, A[1][1]   (i,j) = (1,1)
   -> x = 5, A[5] = 6, A[1][2]   (i,j) = (1,2)

   i = x/3    
   j = x%3
   (x = i*m+j)

   B[y] = B[j][i] = A[i][j] = A[x]

   -> y = j*n + i

A:
0: 1
1: 2
2: 3
3: 4
4: 5
5: 6
m = 3 rows
n = 2 colums
max_index_A = m*n - 1

B:
0: 1
1: 3
2: 5
3: 2
4: 4
5: 6

for x = 0 to max_index_A:
    i = x/n   ; i = x/m  
    j = x%n   ; x = 
    y = j*m + i
    B[y] = A[x]  // B[j][i] = A[i][j]

-> x: the index of array A (1D array from 0 to m*n-1)
-> y: the index of array B (1D array from 0 to m*n-1)
(i,j) is the index of 2D array, A[i][j] 

x = 0: (i,j) = (0,0)  -> y = 0 -> B[0] = A[0] = 1
x = 1: (i,j) = (0,1)  -> y = 2 -> B[3] = A[1] = 2
x = 2: (i,j) = (1,0)  -> y = 4 -> B[4] = A[2] = 3
x = 3: (i,j) = (1,1)  -> y = 1 -> B[1] = A[3] = 4
x = 4; (i,j) = (2,0)




*/

[1 2]
[3 4]
[5 6]

[1 3 5]
[2 4 6]

1 3 5 2 4 6
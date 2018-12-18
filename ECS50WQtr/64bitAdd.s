# takes two numbers and adds them together

.global _start

.data 
	num1: 
		.long 1		#upper sum value
		.long 2		#lower sum value

	num2:
		.long 2		#upper sum value
		.long 6		#lower sum value
.text

addition:
	addl $1, %edx		#function to add the one that carries over
ret

_start:

	movl $num1, %ebx		#ebx = num1 	#assigning the value of num1 to ebx
	movl $num2, %ecx		#ecx = num2	#assigning the value of num2 to ecx
						#edx will be our sum
						#storing upper sum
	addl (%ecx), %edx	#edx = 0 + ecx		#adding ecx to edx
	addl (%ebx), %edx	#edx = ecx + ebx	#adding ebx to edx

	addl $4, %ebx		#shifting 4 bytes
	addl $4, %ecx		#shifting 4 bytes
	
	addl (%ecx), %eax	#eax will be the sum after the shift
	addl (%ebx), %eax
	
	jc addition		#jumps to addition function if the carry flag has been initiated
				#eax now has the final lower sum
				#both numbers have been added

done:
	movl %eax, %eax


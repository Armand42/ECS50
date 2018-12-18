	

		lda current_secs
		ada elapsed_secs
		cma $03c
		jge first_else	; >= 60 go to first else
		sta future_secs
		jmp second_if


first_else:		sba $03c
		sta future_secs
		inc newMins

second_if:		lda newMins
		ada current_mins
		ada elapsed_mins
		cma $03c
		jge second_else
		sta future_mins
		jmp third_if

second_else:		sba $03c
		sta future_mins
		inc newHours

third_if:		lda newHours
		ada current_hours
		ada elapsed_hours
		cma $018
		jge third_else
		sta future_hours
		jmp end

third_else:		sba $018
		sta future_hours

end:		hlt
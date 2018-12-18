#include <iostream>
using namespace std;




int main() {



l = 0
r = limit ; // size - 1

while (l <= r) {
    int m = (l+r)/2;
    if (arr[m] == x) 
        return true;
    else if (arr[m] > x) 
        r = m - 1; 
    else
         l = m + 1; 
}
return false;






























int X[6] = {95,1002,233,-137,6332,-33191};
int Y[6] = {35,102,109,-1278,6332,-33194};
int i = 0;
int flag = 1;

while (i < 6) {
    if (X[i] <= Y[i]) {
        flag = 0;
        break;
    }
    i++;
}
cout << flag << endl;







// C program for implementation of selection sort
#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i = 0;
    int j = 0;
    int min_idx = 0;
    int limit = n-1;

    while (i < limit) {
        min_idx = i;
        j = i+1;
        while (j <= limit) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
            j++;
        }
        swap(min_idx, i);
        i++;
    }
 
    // One by one move boundary of unsorted subarray
    


    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}















    return 0;
}

; p3
	.equ @, $000
	
	lda SIZE
	sba# 1
	sta LIMIT   ; set LIMIT = SIZE - 1

LOOP1:	ldx I	; load I to XR 
	cmx LIMIT  ; compare I with LIMIT
	jge end   ; If I >= LIMIT then jumpt to end
	lda I     ; load I to ACC
	sta MIN_INDEX ; MIN_INDEX = I
	ada# 1     ; ACC = ACC + 1
	sta J       ; J = ACC = I + 1

LOOP2:	lda J       ; ACC = J
	cma LIMIT   ; compare J to LIMIT
	jgt SWAP    ; If J > LIMIT jumpt to SWAP
	ldx J       ; XR = J
	lda+ ARRAY    ; ACC = ARRAY[XR]
	ldx MIN_INDEX  ; XR = MIN_INDEX
	cma+ ARRAY    ; compare ACC with ARRAY[XR]
	jge INC_J     ;  if >=, jumpt to INC_J
	lda J        ; load J into ACC
	sta MIN_INDEX  ; store ACC to MIN_INDEX
INC_J:	lda J          ; ACC = J
	ada# 1         ; ACC = ACC + 1
	sta J          ; J = ACC
	jmp LOOP2     ; jumpt to loop 2

SWAP:	ldx I        ; XR = I
	lda+ ARRAY    ; ACC = ARRAY[XR]
	sta TEMP      ; TEMP = ACC
	ldx MIN_INDEX  ; XR = MIN_INDEX
	lda+ ARRAY     ; ACC = ARRAY[XR]
	ldx I          ; XR = I
	sta+ ARRAY     ; ARRAY[XR] = ACC
	lda TEMP       ; ACC = TEMP
	ldx MIN_INDEX ; XR = MIN_INDEX
	sta+ ARRAY     ; ARRAY[XR] = ACC
	jmp INC_I      ; jumpt to INC_I

INC_I:	lda I
	ada# 1
	sta I
	jmp LOOP1

end:	hlt

LIMIT:	.word 0
MIN_INDEX:	.word 0
TEMP: 	.word 0
I:	.word 0
J:	.word 0

	.equ	@,$100
SIZE:	.word 6
ARRAY:	.word 5
	.word 4
	.word 3
	.word 2
	.word 1
	.word 0











    ; p2

    	.equ @,$000
	
	ldx#	0
LOOP:	cmx  size
	jge  end
	lda+	X
	cma+  Y
	jgt	inc_INDEX	; jump if X[i] > Y[i]
	lda#	0
	sta	output
	jmp	end
inc_INDEX:	adx#	1
	jmp LOOP	
end:	lda output	; output is in acc
	hlt
output:	.word 1
size:	.word 6
X:	.word 95
	.word 1002
	.word 233
	.word -137	
	.word 6333
	.word -33191
Y:	.word 35
	.word 102
	.word 109
	.word -1378
	.word 6332
	.word -33194
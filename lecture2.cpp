#include <iostream>

using namespace std;
//Lecture #2

//Compute the sum of sqaures from all the integers 1 to N
int main() {

int counter = 1;
int n = 5;
int sum = 0;
while (counter <= n) {
    sum+= counter * counter;
    counter++;
    }
    cout << sum;
    return 0;
}


// Cusp Equivalent
/*
Order:

Program
Hlt
Data

load counter into accumulator
if counter(accumulator) > n then end somehow 
multiply accumulator by counter

add sum to accumulator
store accumulator back to sum

load the accumulator with the counter
add 1 to the accumulator
then store the accumulator back to counter
go to the top of the loop


Cusp Intructions

lda: load into accumulator
cma: compare to what is in accumulator
jgt: jump if greater than
.word: not an instruction / just fills up variables with the numbers

    $000            lda counter
    $001            loop:  cma n           (if counter(acc) > n)
    $002            jgt end         (if counter(acc) > n)
    $003            mul counter     (assumes you multiply accumulator) acc * counter
    $004            ada sum         adds value to sum
    $005            sta sum         stores sum into acc
    $006            lda counter     load acc with counter
    $007            ada #001        # means operand (immediate addressing/actual value $ means location 
    $008            sta counter     store acc to counter
    $009            jmp loop        go back to cma n

    $00A            end: hlt        defining names
    $00B            counter: .word  $001
    $00C            sum: .word $000
    $00D            n:   .word $005


Symbol Table: Replace all variable words with their hex counterparts

    loop -> $001
    end -> $00A
    counter -> $00B
    sum -> $00C
    n ->$00D



    $000            lda $00B
    $001            loop:  cma $00D           (if counter(acc) > n)
    $002            jgt $00A                  (if counter(acc) > n)
    $003            mul $00B                  (assumes you multiply accumulator) acc * counter
    $004            ada $00C                  adds value to sum
    $005            sta $00C                  stores sum into acc
    $006            lda $00B                  load acc with counter
    $007            ada #001                  # means operand (immediate addressing/actual value $ means location 
    $008            sta $00B                  store acc to counter
    $009            jmp $001                  go back to cma n

    $00A            end: hlt                  defining names
    $00B            counter: .word $001
    $00C            sum: .word $000
    $00Dn:          .word $005




mnemonics translation from book 

               $002 00B
               $202 00D         (if counter(acc) > n)
               $4D2 00A         (if counter(acc) > n)
               $182 00B         (assumes you multiply accumulator) acc * counter
               $102 00C         adds value to sum
               $042 00C         stores sum into acc
               $002 00B         load acc with counter
               $100 001         # means operand (immediate addressing/actual value $ means location 
               $042 00B         store acc to counter
               $402 001         go back to cma n

               $FFFFFF          defining names
               $000  001
               $000 000
               $000 005

Files made:

sos.csp
sos.lst
sos.obj

*/
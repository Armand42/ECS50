#include<stdio.h>							//user inputs two numbers. Program will output quotient of the two numbers.


int main(int argc, char* argv[]) {
	unsigned int dividend = 0;	
	unsigned int divisor = 0;
	int i; 
	unsigned int answer;
	unsigned int indexDividend;
	int check = 2;
	sscanf(argv[1], "%u", &dividend);
	sscanf(argv[2], "%u", &divisor); 				//initialize the dividend, quotient, divisor, iterator. The dividend is the first argument of the command line action. The divisor is the second argument.



	if (dividend == 0) {
		printf("%d / %d = 0 R 0\n", dividend, divisor);
		return 0;
	}

	if (divisor == 1) {
		printf("%d / %d = %d R 0\n", dividend, divisor, dividend);
		return 0; 
	}								//cases, for divisor = 1 and dividend = 0 case.
	



	unsigned int newDividend;
	for (i = 0; i < 32; i++) {
			if (check == 2) {
				newDividend = dividend >> (31 - i);
			}

			else {
				newDividend = (newDividend) || (indexDividend & 0x1);
			}						//cases, determines how to proceed with iterating through dividend.
			
			if (divisor > newDividend) {
				answer = answer << 1;
				continue; 				//if divisor is less than current dividend, increment answer with '0' and continue.
			}
			
			else {
				answer = answer << 1;
				answer = answer | 0x1;
				newDividend = ((newDividend - divisor) << 1);
				indexDividend = dividend >> (31 - i - 1);
				check = 1;
				continue; 				//if divisor is greater than current dividend, increment answer with '1', subtract divisor from current dividend, then continue.
			}
		}

 
	printf("%d / %d = %d R %d", dividend, divisor, answer, newDividend); //final print statement.
	
	return 0;
}

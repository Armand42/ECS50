//test.cpp

#include<stdio.h>
#include<iostream>
#include<bitset>

using namespace std;

/*int strTerminator(string string);

int strTerminator(char* array[]) {
	if (array.back() == '0') {
		
		strTerminator(string);
	}
	else {
		cout << string;
	}
	return 0;
} */

int main() {
	float f;
	char mantissa [23];
	cout << "Please enter a float: ";
	cin >> f;
											// checking for positive or negative for decimal
	if (f > 0) {
		cout << "1.";
	}
	else if (f < 0){
		cout << "-1.";
	}
	//int exponent = (float_int >> 23) - 127;
	unsigned int float_int = *((unsigned int*)&f);	// checking for 0
	if (float_int == 0) {
		cout << "0E0";
		return 0;
	}
	int exponent = (float_int >> 23) - 127;				// checks for shifting the mask
	if (exponent > 256) {
		exponent = exponent - 256;
	}
	for (int i  = 22; i >= 0; i--) { 
		if ((float_int & 1<<i) == 0) {
			mantissa[i] = '0';
		}
		//else if ((float_int & 1<<i) == 0) {
		//	mantissa.append("0");
		//}
		else {
			mantissa[i] = '1';
		}
	}
	//int exponent;	
	//exponent = (float_int >> 23) - 127;
	//mantissa = strTerminator(mantissa);
	//cout << mantissa << endl;
	//mantissa.append("E");
	//string exponent2;


	//mantissa = strTerminator(mantissa);
	int numCounter = 0;
	for (int i = 0; i <= 22; i++) {		// iterates through mantissa to look for 1
		if (mantissa[i] == '1') {
			++numCounter;
		}
	}
	//cout << numCounter;
	for (int i = 22; i >= 0; i--) {		// checks for zeros while iterating through mantissa
		if (mantissa[i] == '1') {
			cout << mantissa[i];
			--numCounter;
			if (numCounter == 0) {
				break;
			}
		}
		else {
			cout << mantissa[i];
		}
	} 
	cout << "E" << exponent;
	//cout <<  mantissa << "E" << exponent;
	//string answer = "01000011101111110011111E12";
	//cout << answer;


	return 0;


}










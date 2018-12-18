#include "MyFloat.h"
#include<bitset>

MyFloat::MyFloat(){
  sign = 0;
  exponent = 0;
  mantissa = 0;
}

MyFloat::MyFloat(float f){
  unpackFloat(f);
}

MyFloat::MyFloat(const MyFloat & rhs){
	sign = rhs.sign;
	exponent = rhs.exponent;
	mantissa = rhs.mantissa;
}

ostream& operator<<(std::ostream &strm, const MyFloat &f){
	strm << f.packFloat();
	return strm;

}

bool MyFloat::operator==(const MyFloat& rhs) const {

	return true;
//
}


MyFloat MyFloat::operator+(const MyFloat& rhs) const{

	int sumExp;
	int sumMantissa;
	int sumSign;
	int thisMantissa;
	int rhsMantissa;
	int shiftAmount;

	//cout << "this sign: " << bitset<1> (this->sign) << endl;
	//cout << "this exp: " << bitset<8> (this->exponent) << endl;
	//cout << "this mant: " << bitset<23> (this->mantissa) << endl;
	thisMantissa = mantissa;
	thisMantissa |= (1 << 23); //restore leading 1
	//cout << "after restoring: " << bitset<24> (thisMantissa) << endl << endl;

	//cout << "rhs sign: " << bitset<1> (rhs.sign) << endl;
	//cout << "rhs exp: " << bitset<8> (rhs.exponent) << endl;
	//cout << "rhs mant: " << bitset<23> (rhs.mantissa) << endl;
	rhsMantissa = rhs.mantissa;
	rhsMantissa |= (1 << 23);//restore leading 1
	//cout << "after restoring: " << bitset<24> (rhsMantissa) << endl << endl;

	if ( exponent > rhs.exponent ){

		shiftAmount = exponent - rhs.exponent;

		sumExp = exponent;
		sumSign = sign;

		rhsMantissa = (rhsMantissa >> (exponent - rhs.exponent));

		//cout << "this mant after shift: " << bitset<24> (thisMantissa) << endl;
		//cout << "rhs mant after shift:  " << bitset<24> (rhsMantissa) << endl << endl;
 	}

	else{

		shiftAmount = rhs.exponent - exponent;

		sumExp = rhs.exponent;
		sumSign = rhs.sign;

		thisMantissa = (thisMantissa >> (rhs.exponent - exponent));

		//cout << "this mant after shift: " << bitset<24> (thisMantissa) << endl;
		//cout << "rhs mant after shift:  " << bitset<24> (rhsMantissa) << endl << endl;;
	}

	sumMantissa = thisMantissa + rhsMantissa;

	if(sumMantissa >= 0x800000){
		sumMantissa = sumMantissa >>1;
		sumExp = sumExp + 1;
	}
	//cout << "sumMantissa " << bitset<24> (sumMantissa) << endl;
	//cout << "sumExp: " << bitset<8> (sumExp) << endl;
	//cout << "sumSign: " << bitset<1> (sumSign) << endl;

	MyFloat resultFloat;

	resultFloat.mantissa = sumMantissa;
	resultFloat.exponent = sumExp;
	resultFloat.sign = sumSign;

	return resultFloat;

}

MyFloat MyFloat::operator-(const MyFloat& rhs) const{



return *this;

}




void MyFloat::unpackFloat(float f) {

__asm__(



		//assembly
		//sign:
		//#"movl $0x80000000, %%ebx;"
		"movl $0x20000000, %%ebx;"
		"and %%eax, %%ebx;"
		"shr $31, %%ebx;"

		//exponent:
		"movl $0x7F800000, %%ecx;"
		"and %%eax, %%ecx;"
		"shr $23, %%ecx;"


		//mantissa:
		"movl $0x007FFFFF, %%edx;"
		"and %%eax, %%edx" :


		//outputs

		"=b" (sign), "=c" (exponent), "=d" (mantissa) :


		//inputs

		"a" (f) : //put f argument into eax


		//clobbered

		"cc"

	);

}//unpackFloat

float MyFloat::packFloat() const{

  float f = 0;

  __asm__(
	//asesmbly

	"shll $31, %%eax;"

	"shll $23, %%ebx;"
	"or %%ebx, %%eax;"

	"or %%eax, %%ecx;"

	"movl %%ecx, %%edx":

	//outputs
	"=d" (f):
	//inputs
	"a" (sign),"b" (exponent), "c" (mantissa) :
	//clobbered
	"cc"
	);


  return f;
}//packFloat
//

/*
bool MyFloat::operator==(const MyFloat& rhs) const{
  return true;
}
*/


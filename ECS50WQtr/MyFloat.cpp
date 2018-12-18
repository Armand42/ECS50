#include "MyFloat.h"

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


MyFloat MyFloat::operator+(const MyFloat& rhs) const{

  MyFloat result;
  unsigned int big;
  unsigned int small;
  int difference;

  
  if(exponent > rhs.exponent) {
    big = mantissa;
    small = rhs.mantissa;

    result.sign = sign;
    result.exponent = exponent;
    difference = exponent - rhs.exponent;
    small = small >> difference;
  }

  else {
    big = rhs.mantissa;
    small = mantissa;
    result.sign = rhs.sign;

  }





return *this - rhs; //you don't have to return *this. it's just here right now so it will compile
}



MyFloat MyFloat::operator-(const MyFloat& rhs) const{




  
return *this - rhs; //you don't have to return *this. it's just here right now so it will compile
 }



void MyFloat::unpackFloat(float f) {    // inline assembly crap
    
}//unpackFloat 


float MyFloat::packFloat() const{       // inline assembly crap
  //returns the floating point number represented by this  
   float f = 0;     
  
  return f; 
  }//packFloat //

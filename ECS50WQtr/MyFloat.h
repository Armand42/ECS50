#define MY_FLOAT_H   
#define MY_FLOAT_H     
#include <iostream>   
using namespace std;     
class MyFloat{     
   
   
    public:     
    //constructors       
    MyFloat();      
    MyFloat(float f);
     
    MyFloat(const MyFloat & rhs);       // need to define this
      virtual ~MyFloat() {

      }; 
      
                  //output       
    friend ostream& operator<<(std::ostream& strm, const MyFloat& f);             //addition      
     MyFloat operator+(const MyFloat& rhs) const;            
     //subtraction      
     MyFloat operator-(const MyFloat& rhs) const;         
     
    private:
        unsigned int sign;
        unsigned int exponent; 
        unsigned int mantissa;
        
        void unpackFloat(float f);   // must be implemented using assembly
        float packFloat() const;    // must be implemented using assembly
    };     
#ifndef MY_FLOAT_H
  #define MY_FLOAT_H
  
  #include <iostream> 
  using namespace std;
  
  class MyFloat{
    public:
    	//constructors
      MyFloat();
      MyFloat(float f);
      MyFloat(const MyFloat & rhs);
      virtual ~MyFloat() {};
      
      //output
      friend ostream& operator<<(std::ostream& strm, const MyFloat& f);
      
      //addition
      MyFloat operator+(const MyFloat& rhs) const; 
      
      //subtraction
      MyFloat operator-(const MyFloat& rhs) const; 
      //void unpackFloat(float f);
      //void unsigned int sign;
      //void unsigned int exponent;
      //void unsigned int mantissa;

      bool operator==(const MyFloat& rhs) const;
    private:
		  unsigned int sign;
		  unsigned int exponent;
		  unsigned int mantissa;
		  
		  
		  void unpackFloat(float f);
		  float packFloat() const;
  
  };

//#include "MyFloat.cpp"
  
#endif

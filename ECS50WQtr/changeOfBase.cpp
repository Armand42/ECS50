
#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

stack<int> Stack;               // Stack for ASCII values
stack<int> digitStack;          // Stack for remainders

// global variables for input

int base;
string number;
int newBase;
int copyBase;

int main() {
    
    
    
    cout << "Please enter the number's base: " << endl;
    cin >> base;
    copyBase = base;
    cout << "Please enter the number: " << endl;
    cin >> number;
   
    cout <<"Please enter the new base: " << endl;
    cin >> newBase;
    
    // iterates through string and converts chars to corresponding ASCII values
    
    for ( int i = 0; (unsigned) i < number.length(); i++){  
        if (int(number[i]) > 64 && int(number[i]) < 91 ){       // checks bounds according to ASCII Table
            Stack.push(int(number[i]) - 55);                    // pushes numbers from 10 - 32 into a Stack)
             // if input has letters
              
        }
        else if (int(number[i]) > 47 && int(number[i]) < 58 ) { // converts to number
            Stack.push(int(number[i]) - 48);
             // if input has numbers
        }      
    }
    
    // iterates through Stack values and multiples each popped value by base^(n+1) in order to convert number to base 10
    // pushes each value into stack and sums of new base 10 number
    int baseTenNum = 0;
    int exponent = 0;
    for(stack<int> copyStack = Stack; !copyStack.empty(); copyStack.pop())  {   
         baseTenNum = baseTenNum + copyStack.top() * pow(base, exponent);
         exponent++;
    }
    
    // converts base 10 number to new base desired
    
    int remainder = 0;
    while (baseTenNum != 0) {
        remainder = baseTenNum % newBase;
        baseTenNum = baseTenNum / newBase;
        digitStack.push(remainder);  
        
    }
    
    cout << number << " base " << copyBase << " is ";
    for(stack<int> copyStack2 = digitStack; !copyStack2.empty(); copyStack2.pop()) {
         
        if (copyStack2.top() < 10) {
            
        cout << copyStack2.top();
        }
        if (copyStack2.top() > 9 && copyStack2.top() < 33) {        
            
            cout << char (copyStack2.top() + 55);
            
        }
    }
    
    cout << " base " << newBase << endl;
    
    return 0;
}

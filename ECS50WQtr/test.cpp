#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <cstring>
#include <cmath>


using namespace std;
                               // global variable for the mask  
long int shifter = (1<<26);    // This will be use to shift values (bitwise operation)



int main(int argc, char** argv) {
    
    long int container[argc];   
    
    long int arrayLocation; 
    long int trial;        
    int arrayKey;          
    
    
    cout << "You entered the word: " << endl;
    
    for(int i = 1; i < argc; i++) {     // Converts from alphabet to integer value
        container[i] = atoi(argv[i]);
    }
    
    
  
    for (int i = 0; i < argc; i++){     // This loop will iterate and determine if the key is uppercase or lowercase
        arrayKey = container[i];
        
        
        if ((shifter & arrayKey) == 0) {        // conditional that works with a lowercase value
            arrayLocation = 0;                  // initializing the location at a (000 0000 0000 0000 0000 0000 0001)
            trial = pow(2, arrayLocation);
            
            while ((container[i] & trial) == 0){
                arrayLocation = arrayLocation + 1;
                trial = pow(2, arrayLocation);
                
            
            }
            cout << (int(arrayLocation + 97));      // ascii table values for lowercase
        }
        
        else {                                  // conditional that works with uppercase value
           
            arrayLocation = 0;                  // initializes location to a (000 0000 0000 0000 0000 0000 0001)
            trial = pow(2, arrayLocation);
            
            while((container[i] & trial) == 0) {
                arrayLocation = arrayLocation + 1;
                trial = pow(2, arrayLocation);
                
            }
            cout << (int(arrayLocation + 65));      // ascii table values for uppercase
            
            
            
        }
    }
    
    
    
    
   
    return 0;
}



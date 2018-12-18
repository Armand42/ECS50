#include <iostream>

using namespace std;



int main() {
    // 3*4 = 4 + 4 + 4 
    // m*n
    
    int result = 0;
    int m = 0;
    int n = 0;
    int counter = 1;
    cout <<  "Enter a number:  " << endl;
    cin >> m;
    cout << "Enter in n: " << endl;
    cin >> n;
    // check for if n is a negative number 
    if (n < 0) {
        n = -(n);
        m = -(m);
    }

    while (counter <= n) {
        result += m;
        counter++;
    }
    
    cout << result << endl;

    return 0;
}
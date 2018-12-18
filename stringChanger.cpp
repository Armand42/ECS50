#include <iostream>
#include <string>
using namespace std;



// ALMOST WORKS

int main() {
string input;
cout << "Enter a string: " << endl;
getline(cin,input);
//cout << input << endl;

for (int i = 0; i < input.length(); i++) {
    if (int(input[i]) > 96 && int(input[i]) < 123) {
        cout << char(input[i] - 32);
        
        //cout << "yay";
    }
    else if(int(input[i]) < 91 && int(input[i]) > 64) {
        cout << char(int(input[i]) + 32) << " ";
    }
}
//test = "lEArN pYtHOn iN 30 YeaRS!"


for (int i = 0; i < input.length(); i++) {
    for (int j = 0; j < input[i]; j++) {
        if (input[i] < 123 && input[i] > 96) {
            cout << char(input[i] - 32);
        }
    }
}



    return 0;
}
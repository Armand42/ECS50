#include <iostream>
using namespace std;

int main() {
    int ct1 = 17;   // hours
    int ct2 = 34;   // min
    int ct3 = 56;   // seconds

    int et1 = 9;
    int et2 = 48;
    int et3 = 17;

    int ft1 = 0;
    int ft2 = 0;
    int ft3 = 0;
    
    //int seconds = ct3 + et3;
    int newMinutes = 0;
    int newHours = 0;

// seconds_checker
    if (ct3 + et3 < 60) {
        ft3 = ct3 + et3;
    }


    else {
        ft3 = ct3 + et3 - 60;// lda ft3, ada ct3, ada e63, sub 60, sta ft3
        newMinutes = 1;
    }


    newMinutes = newMinutes + ct2 + et2;

//minutes_checker1

    if (newMinutes < 60) {
        ft2 = newMinutes;

    }


    else {
        ft2 = newMinutes - 60;
        newHours = 1;

    }


    newHours = newHours + ct1 + et1;
   
   // hours_checker1
    if (newHours < 24) {
        ft1 = newHours;
    }



    else {
        ft1 = newHours - 24;
    }




    cout << ft1 << endl;
    cout << ft2 << endl;
    cout << ft3 << endl;

/*
    int ct[3] = {17,34,56};
    int et[3] = {9,48,17};
    int ft[3] = {0,0,0};

    int seconds = ct[2] + et[2];
    int minutes = 0;
    int hours = 0;

    if (seconds < 60) {
        ft[2] = seconds;
    }
    else {
        ft[2] = seconds - 60;
        minutes = 1;
    }
    minutes = minutes + ct[1] + et[1];
    if (minutes < 60) {
        ft[1] = minutes;
    }
    else {
        ft[1] = minutes - 60;
        hours = 1;
    }
    hours = hours + ct[0] + et[0];
    if (hours < 24){
        ft[0] = hours;
    }
    else{
        ft[0] = hours - 24;
    }
    cout << ft[0] << endl;
    cout << ft[1] << endl;
    cout << ft[2] << endl;*/


    return 0;
}
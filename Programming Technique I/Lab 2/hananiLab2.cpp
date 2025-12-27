#include <iostream>
using namespace std;

int main(){
    int number , digit ;
    int product = 1;

    cout << "Enter an integer number: ";
    cin >> number;

    while (number>0){
        digit = number%10;
        product = product * digit;
        number = number /10;
 
        cout << digit;
        if (number>0)
           cout << " * " ;
    }
    cout << " = " << product << endl;
    cout << product << " is multiples of ";

    bool hasMultiple = false;
    if (product % 7==0){
        cout << "7";
        hasMultiple = true;
    }
        if (product % 4==0){
            if (hasMultiple) cout << " and ";
            cout << "4";
            hasMultiple = true;
    }
    if (product % 5==0){ 
         if (hasMultiple) cout << " and ";
        cout << "5";
        hasMultiple = true;
    }
    if (!hasMultiple)
      cout << "none of 4,5 or 7" ;
    cout << endl;  

    return 0;
}





    
    
    
#include <iostream>
#include <vector>

using namespace std;

void swapPointers(int* ptr1, int* ptr2);

int main(){
    int a {5};
    int b {10};
 
    int* ptrA = &a;
    int* ptrB = &b;

    cout << "Outside the funtion ptr1: " << ptrA << endl; 
    cout << "Outside the funtion ptr2: " << ptrB << endl;

    swapPointers(ptrA, ptrB);

    cout << ptrA << endl;
    cout << ptrB << endl;

    return 0;
}

void swapPointers(int* ptr1, int* ptr2){
  
    *ptr1 = *(ptr2--);
    *ptr2 = *(ptr1++);
}
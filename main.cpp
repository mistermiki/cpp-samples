//Trying out references

#include <iostream>

using namespace std;

void work(int x){
    x++;
}

void better_work(int &x){
    x++;
    // This approach saves memory usage, because it doesn't copy the input data to process it, but modifies it directly in it's memory location.
}

int main ()
{
    int a = 10;
    int &b = a; // b references to a
    int c = 200;
    b = c; // It's not possible to re-reference a variable. Now the value of c is passed to b, which refers to a. So a gets the value of c.

    cout << a << " " << b << endl; // 200 200
    cout << &a << " " << &b << endl;

    work(a); // a is not changed, because a is copied to x and the copy is incremented. a stays the same.
    cout << a << " " << b << endl; // 200 200

    better_work(a); // a is incremented, because better_work() takes as argument reference to a and changes it directly in the memory.
    cout << a << " " << b << endl; // 201 201

    return 0;
}
// ------------------
// LocalVariables.c++
// ------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

int f () {
    int v = 2;
    ++v;
    return v;}

int g () {
    static int sv = 2;
    ++sv;
    return sv;}

int main () {
    using namespace std;
    cout << "LocalVariables.c++" << endl;

    {
    int i = f();
    assert(i == 3);
    int j = f();
    assert(j == 3);
    }

    {
    int i = g();
    assert(i == 3);
    int j = g();
    assert(j == 4);
    }

    cout << "Done." << endl;
    return 0;}

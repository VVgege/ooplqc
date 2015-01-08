// -------------------
// GlobalVariables.c++
// -------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

int f () {
    std::cout << "f()" << std::endl;
    return 0;}

int v = f();

int main () {
    using namespace std;
    cout << "GlobalVariables.c++" << endl;

    assert(v == 0);

    cout << "Done." << endl;
    return 0;}

/*
f()
GlobalVariables.c++
Done.
*/

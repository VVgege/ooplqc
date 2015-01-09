// --------------------
// SingletonPattern.c++
// --------------------

// https://en.wikipedia.org/wiki/Singleton_pattern

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <string>   // string, ==

using namespace std;

class Singleton {
    private:
        ...

    public:
        string f () const {
            return "Singleton::f()";}

        ...};

int main () {
    cout << "SingletonPattern.c++" << endl;

    assert(&Singleton::only()    == &Singleton::only());
    assert(Singleton::only().f() == "Singleton::f()");

    cout << "Done." << endl;
    return 0;}

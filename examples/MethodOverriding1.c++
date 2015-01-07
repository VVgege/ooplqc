// ---------------------
// MethodOverriding1.c++
// ---------------------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <string>   // string, ==

struct A {
    std::string f (int) {
        return "A::f";}

    std::string g (int) {
        return "A::g";}};

struct B : A {
    std::string f (std::string) {
        return "B::f";}

    std::string g (double) {
        return "B::g";}};

struct C : A {
    using A::f;
    using A::g;

    std::string f (std::string) {
        return "C::f";}

    std::string g (double) {
        return "C::g";}};

int main () {
    using namespace std;
    cout << "MethodOverriding1.c++" << endl;

    {
    B x;

//  assert(x.f(2)    == "A::f"); // doesn't compile
    assert(x.A::f(2) == "A::f");

    assert(x.g(2)    == "B::g");
    }

    {
    C x;

    assert(x.f(2) == "A::f");
    assert(x.g(2) == "A::g");
    }

    cout << "Done." << endl;
    return 0;}

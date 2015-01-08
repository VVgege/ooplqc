// ---------------------
// InstanceVariables.c++
// ---------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
struct A {
//  T v = 2; // error: ISO C++ forbids initialization of member "v"
    T v;
    T w;};

template <typename T>
struct B {
          T v;
    const T cv;};

int main () {
    using namespace std;
    cout << "InstanceVariables.c++" << endl;

    {
    A<int> x;
//  assert(x.v == 0); // undefined
//  assert(x.w == 0); // undefined

    A<int> y = {};
    assert(y.v == 0);
    assert(y.w == 0);

    A<int> z = {2};
    assert(z.v == 2);
    assert(z.w == 0);

    A<int> t = {2, 3};
    assert(t.v == 2);
    assert(t.w == 3);

//  const A<int> x;          // error: uninitialized const "x"
//  assert(A<int>::v == 2);  // error: invalid use of non-static data member "A<int>::v"
    }

    {
    const A<int> x = {2, 3};
          A<int> y = x;      // A<int> y(x);
    assert(y.v == 2);
    assert(y.w == 3);
    assert(&x.v != &y.v);
    assert(&x.w != &y.w);

    {
    const A<int> x = {2, 3};
          A<int> y = {4, 5};
    y = x;
    assert(y.v  == 2);
    assert(y.w  == 3);
    assert(&x.v != &y.v);
    assert(&x.w != &y.w);
    }

    {
//  B<int> x;          // error: structure "x" with uninitialized const members
//  B<int> y = {};     // error: uninitialized const member "B<int>::cv"
//  B<int> z = {2};    // error: uninitialized const member "B<int>::cv"
    B<int> t = {2, 3};
    assert(t.v  == 2);
    assert(t.cv == 3);
    }

    {
    const B<int> x = {2, 3};
    assert(x.v  == 2);
    assert(x.cv == 3);

    B<int> y = x;            // B<int> y(x);
    assert(y.v  == 2);
    assert(y.cv == 3);

    assert(&x.v  != &y.v);
    assert(&x.cv != &y.cv);
    }

    {
    const B<int> x = {2, 3};
    assert(x.v  == 2);
    assert(x.cv == 3);

    B<int> y = {4, 5};
    assert(y.v  == 4);
    assert(y.cv == 5);

//  y = x;                   // error: non-static const member "const int B<int>::cv", can't use default assignment operator
    }
    }

    cout << "Done." << endl;
    return 0;}

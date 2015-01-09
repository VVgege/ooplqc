// ---------------
// ProxPattern.c++
// ---------------

// http://en.wikipedia.org/wiki/Proxy_pattern
// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <algorithm> // swap
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <memory>    // shared_ptr
#include <string>    // string, ==

using namespace std;

struct A {
    string f () {
        return "A::f";}};

template <typename T>
class my_shared_ptr {
    public:
        typedef T element_type;

    private:
        struct count {
            ...};

        ...

    public:
        ...};

template <typename T>
void test () {
    {
//  T x = new A; // error: no viable conversion from 'A *'
//  T x(new A);
    T x(new typename T::element_type);
    assert(x.unique());
    assert(x.use_count() == 1);
    assert(x->f()        == "A::f");
    }

    {
    T x(new typename T::element_type);
    assert(x.unique());
    assert(x.use_count() == 1);
    assert(x->f() == "A::f");
    T y(new typename T::element_type);
    assert(x != y);
    assert(y.unique());
    assert(y.use_count() == 1);
    assert(y->f() == "A::f");
    T z = y;
    assert(z == y);
    assert(!y.unique());
    assert(y.use_count() == 2);
    assert(y->f() == "A::f");
    assert(!z.unique());
    assert(z.use_count() == 2);
    assert(z->f() == "A::f");
    z = x;
    assert(z == x);
    assert(!x.unique());
    assert(x.use_count() == 2);
    assert(x->f() == "A::f");
    assert(y.unique());
    assert(y.use_count() == 1);
    assert(y->f() == "A::f");
    assert(!z.unique());
    assert(z.use_count() == 2);
    assert(z->f() == "A::f");
    }}

int main () {
    cout << "ProxyPattern.c++" << endl;

//  test<my_shared_ptr<A>>();
    test<   shared_ptr<A>>();

    cout << "Done." << endl;
    return 0;}

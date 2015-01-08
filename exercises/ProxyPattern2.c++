// ----------------
// ProxPattern2.c++
// ----------------

// http://en.wikipedia.org/wiki/Proxy_pattern
// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <algorithm> // swap
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <memory>    // shared_ptr
#include <string>    // string, ==

using namespace std;

template <typename T>
class my_shared_ptr {
    friend bool operator == (const my_shared_ptr& lhs, const my_shared_ptr& rhs) {
        return (lhs._p == rhs._p);}

    friend bool operator != (const my_shared_ptr& lhs, const my_shared_ptr& rhs) {
        return !(lhs == rhs);}

    public:
        typedef T                   element_type;

        typedef element_type*       pointer;
        typedef const element_type* const_pointer;

        typedef element_type&       reference;
        typedef const element_type& const_reference;

    private:
        struct count {
            std::size_t _c;
            pointer     _q;

            count (pointer q) :
                    _c (1),
                    _q (q) {
                assert(_q);}

            ~count () {
                assert(_c == 1);
                delete _q;}};

        count* _p;

    public:
        explicit my_shared_ptr (pointer q) {
            _p = new count(q);}

        my_shared_ptr (const my_shared_ptr& rhs) {
            _p = rhs._p;
            ++_p->_c;}

        ~my_shared_ptr () {
            if (unique())
                delete _p;
            else
                --_p->_c;}

        my_shared_ptr& operator = (my_shared_ptr that) {
            swap(that);
            return *this;}

        reference operator * () const {
            return *_p->_q;}

        pointer operator -> () const {
            return _p->_q;}

        pointer get () const {
            return _p->_q;}

        void swap (my_shared_ptr& that) {
            std::swap(_p, that._p);}

        bool unique () const {
            return use_count() == 1;}

        int use_count () const {
            return _p->_c;}};

struct A {
    string f () {
        return "A::f";}};

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
    cout << "ProxyPattern2.c++" << endl;

    test<my_shared_ptr<A>>();
    test<   shared_ptr<A>>();

    cout << "Done." << endl;
    return 0;}

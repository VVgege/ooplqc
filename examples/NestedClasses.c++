// -----------------
// NestedClasses.c++
// -----------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
class A {
    public:
        class B {
            friend class A;

            private:
                enum {ew = 5}; // one for all Bs
                static T cw;   // one for each kind of B
                       T iw;   // one for each B

            public:
                B () :
                        iw  (7)
                    {}

                void g () {
                    assert(ev == 2);    // A::ev
                    assert(cv == 3);    // A::cv
//                  assert(iv == 4);    // error: use of non-static data member 'iv' of 'A' from nested type 'B'
                    assert(ew == 5);    // B::ew
                    assert(cw == 6);    // B::cw
                    assert(iw == 7);}}; // this->iw

    private:
        enum {ev = 2}; // one for all As
        static T cv;   // one for each kind of A
               T iv;   // one for each A
               B x;

    public:
        A () :
                iv  (4)
            {}

        void f () {
            assert(ev    == 2); // A::ev
            assert(cv    == 3); // A::cv
            assert(iv    == 4); // this->iv
            assert(B::ew == 5);
            assert(B::cw == 6);
            assert(x.iw  == 7);}};

template <typename T>
T A<T>::cv = 3;

template <typename T>
T A<T>::B::cw = 6;

int main () {
    using namespace std;
    cout << "NestedClasses.c++" << endl;

    A<int> x;
    x.f();

    A<int>::B y;
    y.g();

    cout << "Done." << endl;
    return 0;}

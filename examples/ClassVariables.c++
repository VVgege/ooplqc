// ------------------
// ClassVariables.c++
// ------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
struct A {
    static T v0;

//  static T v1 = 1;        // error: ISO C++ forbids in-class initialization of non-const static member "A<T>::v1"
    static T v1;

//  static const T cv0 = 0; // error: ISO C++ forbids initialization of member constant "A<double>::cv0" of non-integral type "const double"
    static const T cv0;

    static const int cv1 = 1;};

template <typename T>
T A<T>::v0;

template <typename T>
T A<T>::v1 = v0 + 1;

//template <typename T> // error: uninitialized const "A<T>::cv0"
//const T A<T>::cv0;

template <typename T>
const T A<T>::cv0 = T();

//template <typename T>
//const int A<T>::cv1 = cv0 + 1; // error: duplicate initialization of ‘A<T>::cv1’

template <typename T>
const int A<T>::cv1;

int main () {
    using namespace std;
    cout << "ClassVariables.c++" << endl;

    assert(A<int>::cv1    == 1);
    assert(A<double>::cv1 == 1);

    assert(&A<int>::cv1 == &A<int>::cv1);
    assert(&A<int>::cv1 != &A<double>::cv1);

    A<int> x;
    A<int> y;
    assert(&x.cv1 == &y.cv1);

    cout << "Done." << endl;
    return 0;}

// -------------------
// IteratorPattern.c++
// -------------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream

template <typename II, typename OI>
OI my_copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

template <typename T>
class Range {
    private:
        ...

    public:
        class iterator {
            ...};

        ...};

int main () {
    using namespace std;
    cout << "IteratorPattern.c++" << endl;

    {
    Range<int> x(2, 2);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ostringstream out;
    my_copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "");
    }

    {
    Range<int> x(2, 3);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ostringstream out;
    my_copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "2");
    }

    {
    Range<int> x(2, 4);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ostringstream out;
    my_copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "23");
    }

    {
    Range<int> x(2, 5);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ostringstream out;
    my_copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "234");
    }

    cout << "Done." << endl;
    return 0;}

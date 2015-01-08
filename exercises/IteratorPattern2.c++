// --------------------
// IteratorPattern2.c++
// --------------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream

template <typename T>
class Range {
    private:
        T _b;
        T _e;

    public:
        class iterator {
            friend Range;

            private:
                T _n;

                iterator (const T& n) :
                        _n (n)
                    {}

            public:
                bool operator != (const iterator& other) const {
                    return _n != other._n;}

                const T& operator * () const {
                    return _n;}

                iterator& operator ++ () {
                    ++_n;
                    return *this;}};

        public:
            Range (const T& b, const T& e) :
                    _b (b),
                    _e (e)
                {}

            iterator begin () const {
                return iterator(_b);}

            iterator end () const {
                return iterator(_e);}};

int main () {
    using namespace std;
    cout << "IteratorPattern2.c++" << endl;

    {
    Range<int> x(2, 2);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "");
    }

    {
    Range<int> x(2, 3);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "2");
    }

    {
    Range<int> x(2, 4);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "23");
    }

    {
    Range<int> x(2, 5);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "234");
    }

    cout << "Done." << endl;
    return 0;}

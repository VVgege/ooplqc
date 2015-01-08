// -----------------
// StatePattern2.c++
// -----------------

// https://en.wikipedia.org/wiki/State_pattern

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <stdexcept> // domain_error

using namespace std;

enum State {HasQuarterState, NoQuarterState, SoldOutState};

class GumballMachine {
    private:
        int   _c;
        State _s;

    public:
        GumballMachine (int c) {
            _c = c;
            _s = NoQuarterState;}

        void dispense () {
            if (_s == HasQuarterState) {
                --_c;
                if (_c == 0)
                    _s = SoldOutState;
                else
                    _s = NoQuarterState;}
            else
                throw domain_error("");}

        void eject_quarter () {
            if (_s == HasQuarterState)
                _s = NoQuarterState;
            else
                throw domain_error("");}

        void insert_quarter () {
            if (_s == NoQuarterState)
                _s = HasQuarterState;
            else
                throw domain_error("");}

        void refill (int c) {
            _c += c;
            if (_s == SoldOutState)
                _s = NoQuarterState;}};

int main () {
    cout << "StatePattern2.c++" << endl;

    GumballMachine x(3);
    try {
        x.dispense();
        assert(false);}
    catch (domain_error&)
        {}
    try {
        x.eject_quarter();
        assert(false);}
    catch (domain_error&)
        {}

    x.insert_quarter();
    try {
        x.insert_quarter();
        assert(false);}
    catch (domain_error&)
        {}
    x.eject_quarter();
    try {
        x.eject_quarter();
        assert(false);}
    catch (domain_error&)
        {}

    x.insert_quarter();
    x.dispense();
    try {
        x.dispense();
        assert(false);}
    catch (domain_error&)
        {}

    x.insert_quarter();
    x.dispense();

    x.insert_quarter();
    x.dispense();

    try {
        x.dispense();
        assert(false);}
    catch (domain_error&)
        {}
    try {
        x.eject_quarter();
        assert(false);}
    catch (domain_error&)
        {}
    try {
        x.insert_quarter();
        assert(false);}
    catch (domain_error&)
        {}

    x.refill(1);
    x.insert_quarter();
    x.dispense();

    cout << "Done." << endl;
    return 0;}

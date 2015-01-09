// -----------------
// StatePattern2.c++
// -----------------

// https://en.wikipedia.org/wiki/State_pattern

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <memory>    // make_shared, shared_ptr
#include <stdexcept> // domain_error

using namespace std;

struct StateInterface {
    virtual ~StateInterface () {}

    virtual void dispense       ()    = 0;
    virtual void eject_quarter  ()    = 0;
    virtual void insert_quarter ()    = 0;
    virtual void refill         (int) = 0;};

class GumballMachine {
    private:
        struct AbstractState : StateInterface {
            GumballMachine& _gm;
            ...};

        struct HasQuarterState : AbstractState {
            ...};

        struct NoQuarterState : AbstractState {
            ...};

        struct SoldOutState : AbstractState {
            ...};

    private:
        int                        _c;
        shared_ptr<StateInterface> _s;

    public:
        GumballMachine (int c) :
                _c (c),
                _s (make_shared<NoQuarterState>(*this))
            {}

        void dispense () {
            ...}

        void eject_quarter () {
            ...}

        void insert_quarter () {
            ...}

        void refill (int c) {
            ...}};

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

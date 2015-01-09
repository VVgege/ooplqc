// -----------------
// StatePattern3.c++
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

            AbstractState (GumballMachine& gm) :
                    _gm (gm)
                {}

            ~AbstractState () = 0;

            void dispense () {
                throw domain_error("");}

            void eject_quarter () {
                throw domain_error("");}

            void insert_quarter () {
                throw domain_error("");}

            void refill (int c) {
                _gm._c += c;}};

        struct HasQuarterState : AbstractState {
            HasQuarterState (GumballMachine& gm) :
                    AbstractState(gm)
                {}

            void dispense () {
                --_gm._c;
                if (_gm._c == 0)
                    _gm._s = make_shared<SoldOutState>(_gm);
                else
                    _gm._s = make_shared<NoQuarterState>(_gm);}

            void eject_quarter () {
                _gm._s = make_shared<NoQuarterState>(_gm);}};

        struct NoQuarterState : AbstractState {
            NoQuarterState (GumballMachine& gm) :
                    AbstractState(gm)
                {}

            void insert_quarter () {
                _gm._s = make_shared<HasQuarterState>(_gm);}};

        struct SoldOutState : AbstractState {
            SoldOutState (GumballMachine& gm) :
                    AbstractState(gm)
                {}

            void refill (int c) {
                AbstractState::refill(c);
                _gm._s = make_shared<NoQuarterState>(_gm);}};

    private:
        int                        _c;
        shared_ptr<StateInterface> _s;

    public:
        GumballMachine (int c) :
                _c (c),
                _s (make_shared<NoQuarterState>(*this))
            {}

        void dispense () {
            _s->dispense();}

        void eject_quarter () {
            _s->eject_quarter();}

        void insert_quarter () {
            _s->insert_quarter();}

        void refill (int c) {
            _s->refill(c);}};

GumballMachine::AbstractState::~AbstractState () {}

int main () {
    cout << "StatePattern3.c++" << endl;

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

// ---------------------
// DecoratorPattern4.c++
// ---------------------

// http://en.wikipedia.org/wiki/Decorator_pattern
// http://en.wikipedia.org/wiki/Open/closed_principle
// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // make_shared, shared_ptr

using namespace std;

struct DrinkInterface {
    virtual ~DrinkInterface () {}
    virtual int cost () = 0;};

struct CoffeeDrink : DrinkInterface {
    int cost () {
        return 3;}};

struct EspressoDrink : DrinkInterface {
    int cost () {
        return 4;}};

struct AbstractDrink : DrinkInterface {
    int                        _c;
    shared_ptr<DrinkInterface> _d;

    AbstractDrink (int c, shared_ptr<DrinkInterface> d) :
            _c (c),
            _d (d)
        {}

    int cost () {
        return _c + _d->cost();}};

struct Milk : AbstractDrink {
    Milk (shared_ptr<DrinkInterface> d) :
            AbstractDrink(1, d)
        {}};

struct Mocha : AbstractDrink {
    Mocha (shared_ptr<DrinkInterface> d) :
            AbstractDrink(2, d)
        {}};

int main () {
    cout << "DecoratorPattern4.c++" << endl;

    {
    shared_ptr<DrinkInterface> p = make_shared<CoffeeDrink>();
    assert(p->cost() == 3);
    shared_ptr<DrinkInterface> q = make_shared<Milk>(p);
    assert(q->cost() == 4);
    shared_ptr<DrinkInterface> r = make_shared<Mocha>(p);
    assert(r->cost() == 5);
    shared_ptr<DrinkInterface> s = make_shared<Mocha>(q);
    assert(s->cost() == 6);
    }

    {
    shared_ptr<DrinkInterface> p = make_shared<EspressoDrink>();
    assert(p->cost() == 4);
    shared_ptr<DrinkInterface> q = make_shared<Milk>(p);
    assert(q->cost() == 5);
    shared_ptr<DrinkInterface> r = make_shared<Mocha>(p);
    assert(r->cost() == 6);
    shared_ptr<DrinkInterface> s = make_shared<Mocha>(q);
    assert(s->cost() == 7);
    }

    cout << "Done." << endl;
    return 0;}

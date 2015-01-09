// --------------------
// DecoratorPattern.c++
// --------------------

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

struct MilkCoffeeDrink : DrinkInterface {
    int cost () {
        return 3 + 1;}};

struct MochaCoffeeDrink : DrinkInterface {
    int cost () {
        return 3 + 2;}};

struct MochaMilkCoffeeDrink : DrinkInterface {
    int cost () {
        return 3 + 1 + 2;}};

struct EspressoDrink : DrinkInterface {
    int cost () {
        return 4;}};

struct MilkEspressoDrink : DrinkInterface {
    int cost () {
        return 4 + 1;}};

struct MochaEspressoDrink : DrinkInterface {
    int cost () {
        return 4 + 2;}};

struct MochaMilkEspressoDrink : DrinkInterface {
    int cost () {
        return 4 + 1 + 2;}};

int main () {
    cout << "DecoratorPattern.c++" << endl;

    {
    shared_ptr<DrinkInterface> p = make_shared<CoffeeDrink>();
    assert(p->cost() == 3);
    shared_ptr<DrinkInterface> q = make_shared<MilkCoffeeDrink>();
    assert(q->cost() == 4);
    shared_ptr<DrinkInterface> r = make_shared<MochaCoffeeDrink>();
    assert(r->cost() == 5);
    shared_ptr<DrinkInterface> s = make_shared<MochaMilkCoffeeDrink>();
    assert(s->cost() == 6);
    }

    {
    shared_ptr<DrinkInterface> p = make_shared<EspressoDrink>();
    assert(p->cost() == 4);
    shared_ptr<DrinkInterface> q = make_shared<MilkEspressoDrink>();
    assert(q->cost() == 5);
    shared_ptr<DrinkInterface> r = make_shared<MochaEspressoDrink>();
    assert(r->cost() == 6);
    shared_ptr<DrinkInterface> s = make_shared<MochaMilkEspressoDrink>();
    assert(s->cost() == 7);
    }

    cout << "Done." << endl;
    return 0;}

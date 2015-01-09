// ------------------
// FactoryPattern.c++
// ------------------

// http://en.wikipedia.org/wiki/Factory_method_pattern
// http://en.wikipedia.org/wiki/Abstract_factory_pattern
// http://en.wikipedia.org/wiki/Dependency_inversion_principle

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // make_shared, shared_ptr
#include <string>   // string, ==, +

using namespace std;

struct CrustInterface {
    virtual string display () = 0;};

struct ThickCrust : CrustInterface {
    string display () {
        return "thick";}};

struct ThinCrust : CrustInterface {
    string display () {
        return "thin";}};

struct SauceInterface {
    virtual string display () = 0;};

struct MushroomSauce : SauceInterface {
    string display () {
        return "mushroom";}};

struct TomatoSauce : SauceInterface {
    string display () {
        return "tomato";}};

struct ToppingInterface {
    virtual string display () = 0;};

struct MozzarellaTopping : ToppingInterface {
    string display () {
        return "mozzarella";}};

struct ReggianoTopping : ToppingInterface {
    string display () {
        return "reggiano";}};

struct PizzaInterface {
    virtual ~PizzaInterface () {}
    virtual string display () = 0;};

struct Pizza : PizzaInterface {
    shared_ptr<CrustInterface>   _c;
    shared_ptr<SauceInterface>   _s;
    shared_ptr<ToppingInterface> _t;

    Pizza (
        shared_ptr<CrustInterface>   c,
        shared_ptr<SauceInterface>   s,
        shared_ptr<ToppingInterface> t) :
            _c (c),
            _s (s),
            _t (t)
        {}

    string display () {
        return
            _c->display() + ", " +
            _s->display() + ", " +
            _t->display();}};

shared_ptr<Pizza> make_chicago_pizza () {
    return
        make_shared<Pizza>(
            make_shared<ThickCrust>(),
            make_shared<MushroomSauce>(),
            make_shared<MozzarellaTopping>());}

shared_ptr<Pizza> make_new_york_pizza () {
    return
        make_shared<Pizza>(
            make_shared<ThinCrust>(),
            make_shared<TomatoSauce>(),
            make_shared<ReggianoTopping>());}

int main () {
    cout << "FactoryPattern.c++" << endl;

    {
    shared_ptr<PizzaInterface> p = make_chicago_pizza();
    assert(p->display() == "thick, mushroom, mozzarella");
    }

    {
    shared_ptr<PizzaInterface> p = make_new_york_pizza();
    assert(p->display() == "thin, tomato, reggiano");
    }

    cout << "Done." << endl;
    return 0;}

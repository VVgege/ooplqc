// --------------------
// StrategyPattern2.c++
// --------------------

// http://en.wikipedia.org/wiki/Strategy_pattern
// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // make_shared, shared_ptr
#include <string>   // string, ==

using namespace std;

struct DuckInterface {
    virtual ~DuckInterface () {}

    virtual string swim  () = 0;
    virtual string fly   () = 0;
    virtual string quack () = 0;};

struct AbstractDuck : virtual DuckInterface {
    virtual string swim () final {
        return "can swim";}};

struct FlyingDuck : virtual AbstractDuck {
    string fly () {
        return "can fly";}};

struct NonFlyingDuck : virtual AbstractDuck {
    string fly () {
        return "can not fly";}};

struct QuackingDuck : virtual AbstractDuck {
    string quack () {
        return "can quack";}};

struct NonQuackingDuck : virtual AbstractDuck {
    string quack () {
        return "can not quack";}};

struct DecoyDuck : NonFlyingDuck, QuackingDuck
    {};

struct MallardDuck : FlyingDuck, QuackingDuck
    {};

struct ModelDuck : NonFlyingDuck, NonQuackingDuck
    {};

struct RubberDuck : NonFlyingDuck, QuackingDuck
    {};

int main () {
    cout << "StrategyPattern2.c++" << endl;

    {
    DuckInterface* p = new DecoyDuck;
    assert(p->fly()   == "can not fly");
    assert(p->quack() == "can quack");
    assert(p->swim()  == "can swim");
    delete p;
    }

    {
    shared_ptr<DuckInterface> p = shared_ptr<DuckInterface>(new MallardDuck);
    assert(p->fly()   == "can fly");
    assert(p->quack() == "can quack");
    assert(p->swim()  == "can swim");
    }

    {
    shared_ptr<ModelDuck> p = make_shared<ModelDuck>();
    assert(p->fly()   == "can not fly");
    assert(p->quack() == "can not quack");
    assert(p->swim()  == "can swim");
    }

    {
    auto p = make_shared<RubberDuck>();
    assert(p->fly()   == "can not fly");
    assert(p->quack() == "can quack");
    assert(p->swim()  == "can swim");
    }

    cout << "Done." << endl;
    return 0;}

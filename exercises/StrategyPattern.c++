// -------------------
// StrategyPattern.c++
// -------------------

// http://en.wikipedia.org/wiki/Strategy_pattern
// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // make_shared, shared_ptr
#include <string>   // string, ==

using namespace std;

struct DuckInterface {
    virtual ~DuckInterface () {}

    virtual string fly   () = 0;
    virtual string quack () = 0;
    virtual string swim  () = 0;};

struct AbstractDuck : DuckInterface {
    string swim () final {
        return "can swim";}};

struct DecoyDuck : AbstractDuck {
    string fly () {
        return "can not fly";}

    string quack () {
        return "can quack";}};

struct MallardDuck : AbstractDuck {
    string fly () {
        return "can fly";}

    string quack () {
        return "can quack";}};

struct ModelDuck : AbstractDuck {
    string fly () {
        return "can not fly";}

    string quack () {
        return "can not quack";}};

struct RubberDuck : AbstractDuck {
    string fly () {
        return "can not fly";}

    string quack () {
        return "can quack";}};

int main () {
    cout << "StrategyPattern.c++" << endl;

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

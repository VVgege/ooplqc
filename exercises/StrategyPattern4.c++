// --------------------
// StrategyPattern4.c++
// --------------------

// http://en.wikipedia.org/wiki/Strategy_pattern
// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // make_shared, shared_ptr
#include <string>   // string, ==

using namespace std;

struct FlyingInterface {
    virtual ~FlyingInterface () {}
    virtual string fly () = 0;};

struct Flying : FlyingInterface {
    string fly () {
        return "can fly";}};

struct NonFlying : FlyingInterface {
    string fly () {
        return "can not fly";}};

struct RocketFlying : FlyingInterface {
    string fly () {
        return "can rocket fly";}};

struct QuackingInterface {
    virtual ~QuackingInterface () {}
    virtual string quack () = 0;};

struct Quacking : QuackingInterface {
    string quack () {
        return "can quack";}};

struct NonQuacking : QuackingInterface {
    string quack () {
        return "can not quack";}};

class Duck {
    private:
        shared_ptr<FlyingInterface>   _f;
        shared_ptr<QuackingInterface> _q;

    public:
        Duck (shared_ptr<FlyingInterface> f, shared_ptr<QuackingInterface> q) {
            _f = f;
            _q = q;}

        string fly () {
            return _f->fly();}

        string quack () {
            return _q->quack();}

        string swim () {
            return "can swim";}};

int main () {
    cout << "StrategyPattern4.c++" << endl;

    {
    Duck decoy_duck(make_shared<NonFlying>(), make_shared<Quacking>());
    assert(decoy_duck.fly()   == "can not fly");
    assert(decoy_duck.quack() == "can quack");
    assert(decoy_duck.swim()  == "can swim");
    }

    {
    Duck mallard_duck(make_shared<Flying>(), make_shared<Quacking>());
    assert(mallard_duck.fly()   == "can fly");
    assert(mallard_duck.quack() == "can quack");
    assert(mallard_duck.swim()  == "can swim");
    }

    {
    Duck model_duck(make_shared<NonFlying>(), make_shared<NonQuacking>());
    assert(model_duck.fly()   == "can not fly");
    assert(model_duck.quack() == "can not quack");
    assert(model_duck.swim()  == "can swim");
    }

    {
    Duck rubber_duck(make_shared<NonFlying>(), make_shared<NonQuacking>());
    assert(rubber_duck.fly()   == "can not fly");
    assert(rubber_duck.quack() == "can not quack");
    assert(rubber_duck.swim()  == "can swim");
    }

    cout << "Done." << endl;
    return 0;}

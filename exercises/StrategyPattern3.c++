// --------------------
// StrategyPattern3.c++
// --------------------

// http://en.wikipedia.org/wiki/Strategy_pattern

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <string>   // string, ==

using namespace std;

struct Flying {
    string fly () {
        return "can fly";}};

struct NonFlying {
    string fly () {
        return "can not fly";}};

struct Quacking {
    string quack () {
        return "can quack";}};

struct NonQuacking {
    string quack () {
        return "can not quack";}};

template <typename F, typename Q>
struct Duck {
    F f;
    Q q;

    string fly () {
        return f.fly();}

    string quack () {
        return q.quack();}

    string swim () {
        return "can swim";}};

int main () {
    cout << "StrategyPattern3.c++" << endl;

    {
    Duck<NonFlying, Quacking> decoy_duck;
    assert(decoy_duck.fly()   == "can not fly");
    assert(decoy_duck.quack() == "can quack");
    assert(decoy_duck.swim()  == "can swim");
    }

    {
    Duck<Flying, Quacking> mallard_duck;
    assert(mallard_duck.fly()   == "can fly");
    assert(mallard_duck.quack() == "can quack");
    assert(mallard_duck.swim()  == "can swim");
    }

    {
    Duck<NonFlying, NonQuacking> model_duck;
    assert(model_duck.fly()   == "can not fly");
    assert(model_duck.quack() == "can not quack");
    assert(model_duck.swim()  == "can swim");
    }

    {
    Duck<NonFlying, NonQuacking> rubber_duck;
    assert(rubber_duck.fly()   == "can not fly");
    assert(rubber_duck.quack() == "can not quack");
    assert(rubber_duck.swim()  == "can swim");
    }

    cout << "Done." << endl;
    return 0;}

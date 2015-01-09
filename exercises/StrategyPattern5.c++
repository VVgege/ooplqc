// --------------------
// StrategyPattern5.c++
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

struct DuckInterface {
    virtual ~DuckInterface () {}

    virtual string fly   () = 0;
    virtual string quack () = 0;
    virtual string swim  () = 0;};

template <typename F, typename Q>
class Duck : public DuckInterface {
    private:
        F f;
        Q q;

    public:
        string fly () {
            return f.fly();}

        string quack () {
            return q.quack();}

        string swim () {
            return "can swim";}};

typedef Duck<NonFlying, Quacking>    DecoyDuck;
typedef Duck<Flying,    Quacking>    MallardDuck;
typedef Duck<NonFlying, NonQuacking> ModelDuck;
typedef Duck<NonFlying, Quacking>    RubberDuck;

int main () {
    cout << "StrategyPattern5.c++" << endl;

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

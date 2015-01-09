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

struct QuackingInterface {
    virtual ~QuackingInterface () {}
    virtual string quack () = 0;};

struct Quacking : QuackingInterface {
    string quack () {
        return "can quack";}};

struct NonQuacking : QuackingInterface {
    string quack () {
        return "can not quack";}};

struct DuckInterface {
    virtual ~DuckInterface () {}

    virtual string fly   () = 0;
    virtual string quack () = 0;
    virtual string swim  () = 0;};

class AbstractDuck : public DuckInterface {
    private:
        shared_ptr<FlyingInterface>   _f;
        shared_ptr<QuackingInterface> _q;

    public:
        AbstractDuck (shared_ptr<FlyingInterface> f, shared_ptr<QuackingInterface> q) :
                _f (f),
                _q (q)
            {}

        ~AbstractDuck () = 0;

        string fly () final {
            return _f->fly();}

        string quack () final {
            return _q->quack();}

        string swim () final {
            return "can swim";}};

AbstractDuck::~AbstractDuck () {}

struct DecoyDuck : AbstractDuck {
    DecoyDuck () :
            AbstractDuck (
                make_shared<NonFlying>(),
                make_shared<Quacking>())
        {}};

struct MallardDuck : AbstractDuck {
    MallardDuck () :
            AbstractDuck (
                make_shared<Flying>(),
                make_shared<Quacking>())
        {}};

struct ModelDuck : AbstractDuck {
    ModelDuck () :
        AbstractDuck (
            make_shared<NonFlying>(),
            make_shared<NonQuacking>())
        {}};

struct RubberDuck : AbstractDuck {
    RubberDuck () :
        AbstractDuck (
            make_shared<NonFlying>(),
            make_shared<Quacking>())
        {}};

int main () {
    cout << "StrategyPattern4.c++" << endl;

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

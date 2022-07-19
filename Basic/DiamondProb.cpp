#include<iostream>

using namespace std;

class A{
    int a;
    public:
        A() {cout << "Constr A " << endl;}
        ~A() {cout << "Desc A " << endl;}    
};
class B: public A{             //-->problem
//class B: virtual public A{   //-->solution
    int a;
    public:
        B() {cout << "constr B " << endl;}
        ~B() {cout << "Desc B " << endl;}
};
class C: public A{             //-->problem
//class C: virtual public A{   //-->solution
    int a;
    public:
        C() {cout << " consts C "<< endl;}
        ~C() {cout << "Desc C " << endl;}
};

class D : public B, public C{
    int a;
    public:
        D() {cout << " constr D " << endl;}
        ~D() {cout << "Desc D " << endl;}
};

int main()
{
    D d;
    return 0;
}

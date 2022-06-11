/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class employee{
  
  string _name;
  public:
    employee(string name): _name(name) {
        cout << "inside employee constructor" << endl;
    }
    ~employee()
    {
        cout << _name << " employee desctructor " << endl;
    }
    string getName()
    {       
        return _name;
    }
};

template <typename T>
class mySmartPtr{
    T * ptr;
    public:
        mySmartPtr(T * obj): ptr(obj)
        {
            cout << "inside mySmartPtr const " << endl;
        }
        ~mySmartPtr()
        {         
            delete ptr;
        }
        T * operator ->()
        {
            return ptr;
        }
        T & operator *()
        {
            return *ptr;
        }
};

int main()
{
    cout<<"Hello World" << endl;
    mySmartPtr <employee> obj (new employee("nitin"));
    cout << obj->getName() << endl;
    {
        mySmartPtr<employee> obj1 (new employee("nitin1"));
        cout << obj1->getName() << endl;
    }

    return 0;
}

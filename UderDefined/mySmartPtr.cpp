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

class mySmartPtr{
    employee * ptr;
    public:
        mySmartPtr(employee * obj): ptr(obj)
        {
            cout << "inside mySmartPtr const " << endl;
        }
        ~mySmartPtr()
        {           
            delete ptr;
        }
        employee * operator ->()
        {
            return ptr;
        }
        employee & operator *()
        {
            return *ptr;
        }
};

int main()
{
    cout<<"Hello World" << endl;
    mySmartPtr obj (new employee("nitin"));
    cout << obj->getName() << endl;
    {
        mySmartPtr obj1 (new employee("nitin1"));
        cout << obj1->getName() << endl;
    }
    return 0;
}

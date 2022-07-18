#include<iostream>

using namespace std;

class sample{
    public: 
        string _name;
        string * _surname;
        //sample() {}
        sample():_name(""), _surname(new string()) {}
        sample(string name, string surname): _name(name) , _surname(new string(surname)) {}
        
        //sample(const sample & obj) : _name(obj._name+ "hellboy1 "), _surname(new string(*obj._surname)) { cout << " copy constructor with intializer list  " << endl;}
        //copy constructor 
        sample(const sample & obj)
        {
            cout << " copy constructor without initializer list  " << endl;
            _name = obj._name + " hellboy";
            _surname = new string(*obj._surname);
        }
        //assignment operator
        sample& operator=(sample & obj)
        {
            cout << " assignment without initializer list 1 " << endl;
            if(this != &obj)
            {
                delete _surname;
                _name = obj._name + " hellboy 2";
                _surname = new string(*obj._surname);
            }
            return *this;
        }
        //move constructor
        sample(sample &&obj): _name(obj._name + "helboy 3"), _surname(nullptr)
        {
            cout << "move constructor get called " << endl;
            _surname = obj._surname; 
            obj._surname = nullptr;
            obj._name= " ";
        }
        //move assignment 
        sample& operator=(sample &&obj)
        {
            if(this != &obj)
            {
                delete _surname;
                cout << "move assignment get called " << endl;
                _surname = obj._surname; 
                _name = obj._name + "hellboy 4";
                cout << "move assignment get called " << _name << endl;
                obj._surname = nullptr;
                obj._name= " ";
            }
            return *this;
        }

        ~sample()
        {
            cout << " desctructor get called " << endl;
            delete _surname;
        }
};

int main()
{
    sample s("nitin", "kotania");
    cout << &s << " " << s._name << " " << *s._surname << endl;
    cout << &s << " " << &s._name << " " << &(*s._surname) << endl;
cout << "----------------------copy----------------------------------------" << endl;
    sample s1(s);
    cout << &s1 << " " << s1._name << " " << *s1._surname << endl;
    cout << &s1 << " " << &s1._name << " " << &(*s1._surname) << endl; 
cout << "-----------------------assignment---------------------------------------" << endl;
    sample s2;
    s2 = s;
    cout << &s2 << " " << s2._name << " " << *s2._surname << endl;
    cout << &s2 << " " << &s2._name << " " << &(*s2._surname) << endl; 
cout << "-----------------------mv copy---------------------------------------" << endl;
    sample s3(move(s1));
    cout << &s3 << " " << s3._name << " " << *s3._surname << endl;
    cout << &s3 << " " << &s3._name << " " << &(*s3._surname) << endl; 
    cout << "-->" << &s1 << " " << s1._name ;
cout << "-----------------------mv assignment---------------------------------------" << endl;
    sample s4;
    s4 = std::move(s2);
    cout << &s4 << " " << s4._name << " " << *s4._surname << endl;
    cout << &s4 << " " << &s4._name << " " << &(*s4._surname) << endl; 
    cout << "-->" << &s2 << " " << s2._name ;

    return 0;
}

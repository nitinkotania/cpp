#include <iostream>

using namespace std;

class Singleton{
    public:
        static Singleton * getInstance();
        //static void releaseInstance();
        
    private:
        Singleton(){};
        ~Singleton(){};
        Singleton(const Singleton & obj);
        Singleton operator=(const Singleton & obj);
        static Singleton * s_instance;
        static int counter;
};

//Singleton * Singleton::

Singleton * Singleton::s_instance = nullptr;
int Singleton::counter = 0;


Singleton * Singleton::getInstance(){
    if(!s_instance)
    {
        s_instance = new Singleton();
    }
  
    counter++;
      cout << "instance refered :" << counter  << endl;
    return s_instance;
}
/*
void Singleton::releaseInstance()
{
    counter--;
    if(!s_instance && 0 == counter)
    {
        delete s_instance;
        s_instance = NULL;
    }
}
*/

int main()
{
    cout<<"Hello World" << endl;
    
    Singleton * inst1 = Singleton::getInstance();
    Singleton * inst2 = Singleton::getInstance();
    Singleton * inst3 = Singleton::getInstance();
    return 0;
}
